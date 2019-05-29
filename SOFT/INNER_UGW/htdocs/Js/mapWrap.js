/**
 * @fileoverview MapWrapper���ṩ�˽�Google��GPS������ʽ��Marker��ӵ���ͼ�ϵĹ��ܡ�
 * �û�����ֱ��ͨ�������ṩ��addOverlay����,���Google��GPS������ʽ��Marker����ͼ��,
 * ������Ҫ�Ƚ�Google��GPS����ת��Ϊ�ٶ����꣬Ȼ������ӵĲ�����
 * ���������<a href="symbols/BMapLib.MapWrapper.html">MapWrapper</a>��
 * ����Baidu Map API 1.2��
 *
 * @author Baidu Map Api Group 
 * @version 1.2
 */

/** 
 * @namespace BMap������library�������BMapLib�����ռ���
 */
var BMapLib = window.BMapLib = BMapLib || {};

(function() { 

    /**
     * GPS����ϵ����
     */
    BMapLib.COORD_TYPE_GPS  = 0;
    
    /**
     * Google ����ϵ����
     */
    BMapLib.COORD_TYPE_GOOGLE = 2;

    /**
     * Baidu ����ϵ����
     */
    var COORD_TYPE_BAIDU = 4;
    
    /**
     * ÿ��������ת�������������
     */
    var CONVERT_NUM_ONCE = 20;
    
    
    /** 
     * @exports MapWrapper as BMapLib.MapWrapper 
     */
    var MapWrapper =    

    /**
     * MapWrapper��Ĺ��캯��
     * @class ��Google��GPS������ʽ��Marker��ӵ���ͼ��,
     * ʵ��������󣬼��ɵ��ø����ṩ��addOverlay�������GPS��Google������ʽ��Marker��
     * 
     * @constructor
     * @param {Map} map BMap.Map��ʵ������
     * @param {Number} coordType ��Ҫת�����������ͣ��磺GPS�������� | Google��������
     *     
     */
    BMapLib.MapWrapper = function(map, coordType){
        this._map = map;
        this._coordType = coordType;

        //��ʱ����ת��ǰ��mkr�����ص��˶����ϣ�ת����Ϻ���ɾ����
        this._hashObject = {};

        //�������飬�����ۼ�ÿ��20������㣬Ȼ��һͬ��������
        this._arrCache = [];
    }

    /*
     * ������������Ψһ��ʶÿ�����͵���������к�
     */
    MapWrapper.prototype._uiqueNum = 0;

    /**
     * �Ƿ���Է�������,���������ۼƷ�������ı�ʶ
     */
    MapWrapper.prototype._canSendRequest = true;

    /**
     * ����������ӵ���ͼ�ϡ��˺������Ƚ���������ת��Ϊ�ٶ����꣬Ȼ���ٽ���������ӵ���ͼ�ϡ�
     * @param {Overlay} overlay ���������Ŀǰֻ֧��Marker����� 
     * @return �޷���ֵ
     */
    MapWrapper.prototype.addOverlay = function(overlay){
		
		var pt = new BMap.Point(0,0);
		
		this.setPosition(overlay,pt);
    }
	
	MapWrapper.prototype.setPosition = function(overlay,pt){
        //Ŀǰ��֧��Marker����
        if(!overlay || !(overlay instanceof BMap.Marker)){
            return;
        }
        if(!pt || !(pt instanceof BMap.Point)){
            return;
        }

        var data = {
            'overlay'    : overlay,        
			"position"	 : pt,
            'uiqueNum'   : this._uiqueNum //Ψһ��ʶ�������
        };
        
        this._arrCache.push(data);
        this._hashObject['guid' + this._uiqueNum] = overlay; //��¼��hash�����У��ص���ʹ��

        this._uiqueNum++;
        
        var me = this;    
        if(me._canSendRequest){
            me._canSendRequest = false;

            window.setTimeout(function(){
                me._canSendRequest = true;
                me._delayRequest();            
            }, 50);
        }
    }

    /**
     * �ӳٷ�������
     */
    MapWrapper.prototype._delayRequest = function(){
        var arrCache = this._arrCache;
        var group = Math.ceil(arrCache.length / CONVERT_NUM_ONCE); //�������            
        
        for(var i = 0; i < group; i++){
            var arrX = [], arrY = [], arrGuid = [],arrMethod = [];
            
            var minIndex = i * CONVERT_NUM_ONCE;
            var maxIndex = -1;
            if(arrCache.length - (i + 1) * CONVERT_NUM_ONCE > 0){
                maxIndex = (i + 1) * CONVERT_NUM_ONCE;
            } else {
                maxIndex = arrCache.length;
            }
            
            for(var j = minIndex; j < maxIndex; j++){            
                var data = arrCache[j];           
				
                var x = data.overlay.getPosition().lng;
                var y = data.overlay.getPosition().lat;
				
				var method = 0;
                
				if((data.position.lng != 0) && (data.position.lat != 0))
				{
					x = data.position.lng;
					y = data.position.lat;
					method = 1;
				}
                arrX.push(x);
                arrY.push(y);            
                arrGuid.push('guid' + data.uiqueNum);
				arrMethod.push(method);
            }

            var strX = arrX.join(",");
            var strY = arrY.join(",");
            
            //��������
            var jsonParam = {
                x:      strX,
                y:      strY,
                from:   this._coordType,
                to:     COORD_TYPE_BAIDU,
                mode:   1
            };
            
            //�û��Զ������
            var userData = {
                'guids': arrGuid,
				'methods':arrMethod
            };
            
            var me = this;
            MapWrapper._SearchRequestMgr.request(function(json, userData){
                me._requestCbk(json, userData);
            }, jsonParam, userData);        
        }    

        this._arrCache.length = 0; //�������0
    }

    /**
     * ����ת����Ļص�����
     * @param {Json} json ת�����json����
     * @param {Json} userData ������ǰһЩ�������ڻص�������ʹ��
     * 
     */
    MapWrapper.prototype._requestCbk = function(json, userData){
        if(json && json instanceof Array){
            var guids = userData.guids;
			var methods = userData.methods;
            for(var i = 0; i < json.length; i++){
                var item = json[i];
                if(item && item.error == 0){
                    var newX = item.x, newY = item.y;
                    var newPt = new BMap.Point(newX, newY);
                    
                    var guid = guids[i];
					var method = methods[i];
                    if(this._hashObject[guid]){
                        var mkr = this._hashObject[guid];
                        mkr.setPosition(newPt);
						
						if(method == 0)
							this._map.addOverlay(mkr);

                        delete this._hashObject[guid];
                    }

                }
            }
        }
    }

    /**
     * json����ת��Ϊurl�ִ�
     * @param {Json} json ��Ҫת����json����
     * @param {Function} encode ���뺯��
     */
    MapWrapper._jsonToQuery = function(json, encode){
      var s = [];
      encode = encode || function(v){return v};
      for (var n in json){
        s.push(n + "=" + encode(json[n]));
      }
      return s.join("&");
    }

    /**
     * �������ģ�� 
     */
    MapWrapper._SearchRequestMgr = {
      /**
       * �����ַ
       */
      COORD_CONVERT_URL: "http://api.map.baidu.com/ag/coord/convert",  
      /**
       * ������
       * @param {Function} cbk �ص�����
       * @param {Object} params �����������, �ڻص�����ʱ���ݸ��ص�����
       * @param {Object} userData �û��Զ�������, �ڻص�����ʱ���ݸ��ص�����
       * @param {String} path ��������·������ѡ
       */
      request: function(cbk, params, userData, path){    
        var timeStamp = (Math.random() * 100000).toFixed(0);// ���������
        
        MapWrapper._cbkMount["_cbk" + timeStamp] = function(json){// ȫ�ֻص�����
          userData = userData || {};
          cbk && cbk(json, userData);
          delete MapWrapper._cbkMount["_cbk" + timeStamp];
        };

        path = path || "";    
        
        var reqParam = MapWrapper._jsonToQuery(params, encodeURIComponent);    

        var me = this,
            url = me.COORD_CONVERT_URL + path + "?" + reqParam + 
                        "&ie=utf-8&oue=1&res=api&callback=BMapLib.MapWrapper._cbkMount._cbk" + timeStamp;
            
        me.createScript(url);
      },
      /**
       * ��̬����script��ǩ����������
       * @param {String} url script��ǩ��Ӧ��url
       */
      createScript: function(url) {    
        var script = document.createElement("script");
        script.src = url;
        script.setAttribute('type', 'text/javascript');
        script.setAttribute('charset', 'utf-8');

        // �ű�������ɺ�����Ƴ�
        if (script.addEventListener) {
          script.addEventListener('load', function(e) {
            var t = e.target;
            t.parentNode.removeChild(t);
          }, false);
        }
        else if (script.attachEvent) {
          script.attachEvent('onreadystatechange', function(e) {
            var t = window.event.srcElement;
            if (t && (t.readyState == 'loaded' || t.readyState == 'complete')) {
              t.parentNode.removeChild(t);
            }
          });
        }
        // ʹ��setTimeout���ie6�޷���������
        setTimeout(function() {        
          document.getElementsByTagName('head')[0].appendChild(script);      
          script = null;
        }, 1);
      }
    };

    /*
     * ȫ�ֻص��������ص�
     */
    MapWrapper._cbkMount = {};

})();//�հ�����