/*
https://www.tenpay.com/cgi-bin/v1.0/manage_base.cgi?Sender=pai00001&Content=欢迎您,高勇<a%20href="http://www.sina.com">aa</a>&Sign=5B0A4023E93C1EF3310A08DC2BD8E24B&disp=3
*/

ie4=(document.all)?true:false;
ns4=(document.layers)?true:false;

function show_tips(){
	if (divHistory.style.display=="none")
	{
	  g_CCookie.SetCookie("CftHelper_disp","show");
		divHistory.style.display="block";
		HideBk(true);
//		lay_ifr.style.display="block"
	}
	else
	{
	  g_CCookie.SetCookie("CftHelper_disp","hide");
		divHistory.style.display="none";
//		lay_ifr.style.display="none"
	}
}

function HideBk(state)
{
	var ifObj = document.getElementById("DivShim"); 
	var theObj = document.getElementById("divHistory"); 
	//alert(ifObj);
	//alert(theObj);
	if(ifObj && ifObj)
	{
		if(state)
		{
			ifObj.style.width = theObj.offsetWidth; 
			ifObj.style.height = theObj.offsetHeight; 
			ifObj.style.top = theObj.style.top; 
			ifObj.style.left = theObj.style.left; 
			ifObj.style.zIndex = theObj.style.zIndex - 1; 
			ifObj.style.display = "block"; 
		}
		else
		{
			ifObj.style.display = "none";
		}
	}
	
}

function toExit()
{
	var args=toExit.arguments;
	var visible=args[0];
	
	g_CCookie.SetCookie("CftHelper_disp",args[0]);
	
	if(ns4){
		theObj=eval("document.layers[\'"+args[1]+"\']");
		if(theObj)  theObj.visibility=visible;
	}
	else if(ie4)
	{
		if(visible=='show')visible='inline';
		if(visible=='hide')visible='none';
		theObj=eval("document.all[\'"+args[1]+"\']");
		if(theObj)theObj.style.display = visible;
	}
	if(visible == 'show' ||  visible=='inline')
	{
		HideBk(true);
	}
	else
	{
		HideBk(false);
	}
}     

function beginDrag(elementToDrag,event)
{
	elementToDrag.className="glow";
  	//计算指针与left/top差值
  	var deltaX=event.clientX-parseInt(elementToDrag.style.left);
  	var deltaY=event.clientY-parseInt(elementToDrag.style.top);
  	if(document.addEventListener)
  	{
  		document.addEventListener("mousemove",moveHandler,true);
  		document.addEventListener("mouseup",upHandler,true);
  	}
  	else if(document.attachEvent)
  	{
  		document.attachEvent("onmousemove",moveHandler);//onmousemove 
  		document.attachEvent("onmouseup",upHandler);//onmouseup
  	}

 	function moveHandler(e){
  	if(!e)	e=window.event;
  	//通过差值按比例定位层
  	elementToDrag.style.left=(e.clientX-deltaX)+"px";
  	elementToDrag.style.top=(e.clientY-deltaY)+"px";
//    g_CCftHelper.SupportDiv();
  	HideBk(true);
 	}
 
 	function upHandler(e)
 	{
  		if(document.removeEventListener)
  		{
   			document.removeEventListener("mouseup",upHandler,true);
   			document.removeEventListener("mousemove",moveHandler,true);
   		}
  		else if(document.detachEvent)
  		{
   			document.detachEvent("onmouseup",upHandler) ;
   			document.detachEvent("onmousemove",moveHandler);
  		}
 	}
 }
 


/*
 *财付通小助手
 *  使用了CSELFURL类，用来抓取链接中传递过来的数据，需要在本js之前引入页面
 */
function CCftHelper()
{
  this.m_strSender  = ""; //触发者
  this.m_strSign    = ""; //签名
  this.m_strContent = ""; //显示内容
  this.m_nHeigth    = 0;  //高度
  this.m_nWidth     = 0;  //宽度
  this.m_nXPos      = 0;  //x坐标
  this.m_nYPos      = 0;  //y坐标
  
  this.m_nDisp      = 1;  //显示模式0不显示 1 显示按钮 2 显示窗口 3 显示按钮与窗口
  
  this.m_xmlRes     = null;
  
  this.SupportDiv    = CCftHelper_SupportDiv;
  
  this.Fetch        = CCftHelper_Fetch; //获取，验证数据
  this.CallBack     = CCftHelper_CallBack;
  this.Show         = CCftHelper_Show;  //显示助手页面
  this.Draw         = CCftHelper_Draw;
  this.FixButtonPos = CCftHelper_FixButtonPos;
  
  this.HtmlEscape   = CCftHelper_HtmlEscape;
  
}
function getInsideWindowHeight( ) 
{
  // Global variables
  var isCSS, isW3C, isIE4, isNN4, isIE6CSS;
  
  // Initialize upon load to let all browsers establish content objects
  
  if (document.images) 
  {
    isCSS = (document.body && document.body.style) ? true : false;
    isW3C = (isCSS && document.getElementById) ? true : false;
    isIE4 = (isCSS && document.all) ? true : false;
    isNN4 = (document.layers) ? true : false;
    isIE6CSS = (document.compatMode && document.compatMode.indexOf("CSS1") >= 0) ? 
      true : false;
  }
  
  
  if (window.innerHeight) 
  {
    return window.innerHeight;
  } 
  else if (isIE6CSS) 
  {
    // measure the html element's clientHeight
    return document.body.parentElement.clientHeight;
  } 
  else if (document.body && document.body.clientHeight) 
  {
    return document.body.clientHeight;
  }
  return 0;
}


function CCftHelper_SupportDiv()
{
  var o = document.getElementById("CftHelper_fram_bk")
  if(!o)
  {
    o = document.createElement('iframe');
    o.id = 'CftHelper_fram_bk';
    document.body.appendChild(o);
  }
  o.style.position = "absolute";
  o.style.zIndex =1;
    
  o.top = this.m_nYPos+100;
  o.left = this.m_nXPos;
  o.width = this.m_nWidth.toString()+"px";
  o.Height = this.m_nHeigth.toString()+"px";
  
//  var o = window.event?event.srcElement:e.target;
//  var p = getXY(e);
//  if (document.all){
//    if (!$('fram_bk')){initBK();}
//    with ($('fram_bk').style){
//      display='block';
//      top = p.y+"px";
//      left = p.x+"px";
//    }
//  }
//  with ($('menu').style){
//    display='block';
//    top = p.y+"px";
//    left = p.x+"px";
//  }
}




function CCftHelper_FixButtonPos()
{
  var obj = document.getElementById("Button_CftHelper");
  obj.style.top = document.body.parentNode.scrollTop+getInsideWindowHeight()/2 -100;
//  alert(document.body.offsetHeight);
}

function CCftHelper_Draw()
{
  /*
  if(this.m_nDisp == 0)
  {    
    return;
  }
  
  var strHtml = "";
  //按钮
  strHtml +="<div id=\"Button_CftHelper\" style=\"position:absolute;left:0px; top:30px; width:170px; height:80px; z-index:0;\">\r\n";
  strHtml +=" <table border=\"0\" align=\"left\" cellpadding=\"0\" cellspacing=\"0\"><tr><td><a href=\"#\" onClick=\"show_tips()\"><img src=\"/zft/images/help_tag.gif\" border=\"0\"></a></td></tr></table>\r\n";
  strHtml +="</div>\r\n\r\n";
  //隐藏iframe
  strHtml +="<iframe id=\"DivShim\" src=\"javascript:false;\" scrolling=\"no\" frameborder=\"0\" \r\n";
  strHtml +=" style=\"position:absolute; top:-80px; left:0px; display:none;filter=progid:DXImageTransform.Microsoft.Alpha(style=0,opacity=0);\"> \r\n";
  strHtml +="</iframe>\r\n\r\n";  
  //浮动窗口
  strHtml +="<div id=\"divHistory\" style=\"position:absolute;left:0px; top:-90px; width:"+ this.m_nWidth.toString() +"px; height:" + this.m_nHeigth.toString() +"px; z-index:1;display:none\">\r\n";
  strHtml +=" <table width=\"100%\"  border=\"0\" cellpadding=\"0\" cellspacing=\"1\" bgcolor=\"#ffffff\" align=\"center\" onMouseOver=\"this.style.cursor='move';\" onMouseDown=\"beginDrag(this.parentNode,event);\" style=\"border:1px solid #0079CA\">\r\n";
  strHtml +="  <tr><td background=\"/zft/images/help_tag_headbg.gif\" style=\"border-bottom:1px solid #5BBDFF\">\r\n";
  strHtml +="   <table  width=\"100%\"  border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\r\n";
  strHtml +="    <tr><td style=\"padding-left:8px;color:#3568B6\"><b>温馨提示：</b></td>\r\n";
  strHtml +="     <td height=\"20\" align=\"right\" style=\"padding-right:2px; \"><a href=\"javascript:toExit('hide','divHistory')\"><img src=\"/zft/images/spacer_1.gif\" width=\"8\" height=\"8\" border=\"0\"></a>&nbsp;</td>\r\n";
  strHtml +="    </tr></table>\r\n";
  strHtml +=" 	</td></tr>\r\n";
  strHtml +="   <tr><td align=\"left\" height=\"60\" bgcolor=\"ffffff\" style=\"padding:6px;color:#3568B6;line-height:18px; font-size:12px;\">\r\n";
  strHtml +="     <div style=\"padding:3px;overflow-y:auto;overflow-x:hidden;width:"+ this.m_nWidth.toString() +"PX;word-wrap:break-word;height:" + this.m_nHeigth.toString() +"px;bgColor=\"E7F5FF\";padding:6px;color:#3568B6;line-height:18px;\">&nbsp;&nbsp;&nbsp;&nbsp;"+ this.m_strContent + "</div>\r\n";
  strHtml +=" 	</td></tr>\r\n";
  strHtml +=" </table>\r\n";
  strHtml +="</div>\r\n";
//  alert(strHtml);
  document.getElementById("DIV_HELPER").innerHTML = (strHtml);
 
//    var obj = document.getElementById("Table_CftHelper");
//     alert(obj.style.posLeft );
//  alert(obj.style.posTop  );
  //调整位置
  var elementToDrag = document.getElementById("divHistory");  
  
  elementToDrag.style.left=(this.m_nXPos)+"px";
  elementToDrag.style.top=(this.m_nYPos)+"px";  
  HideBk(true);
  
  
  this.FixButtonPos();
  document.body.onmousewheel   = this.FixButtonPos;
  document.body.onscroll     = this.FixButtonPos;
  
  if(this.m_nDisp == 2)
  {
    var obj = document.getElementById("Button_CftHelper");
    obj.style.display = "none";
//		lay_ifr.style.display="block"
    if(g_CCookie.GetCookie("CftHelper_disp") != "hide")
    {  
      divHistory.style.display="block";
      HideBk(true);
    }
      
      
  }
  */
  if(this.m_nDisp == 3)
  {
    /*
	if(g_CCookie.GetCookie("CftHelper_disp") != "hide")
    {
      divHistory.style.display="block";
      HideBk(true);
    }
//		lay_ifr.style.display="block"
	*/	
	//注册成功页面显示成功1分钱按钮
	if(this.m_xmlRes.GetValue("location")=="reg_tip.shtml" &&  this.m_strContent.indexOf("donate_money.shtml")>=0){
		if(TFL.cookie.get("qbase") != "1")
		   document.getElementById("OneMoneyAct").style.display="";		
	}
  }
  else
  {
    return;
  }
}
function CCftHelper_Show()
{
//  if((this.m_strContent == "") && (this.m_xmlRes == null))
//  {
//    this.Fetch();
//    return ;
//  }
  
  this.m_strSender  = this.m_xmlRes.GetValue("sender"); //触发者
  this.m_strSign    = this.m_xmlRes.GetValue("sign"); //签名
  this.m_strContent = this.m_xmlRes.GetValue("content"); //显示内容
  this.m_nHeigth    = this.m_xmlRes.GetValue("height");  //高度
  this.m_nWidth     = this.m_xmlRes.GetValue("width");  //宽度
  this.m_nXPos      = this.m_xmlRes.GetValue("x");  //x坐标
  this.m_nYPos      = this.m_xmlRes.GetValue("y");  //y坐标
  
  this.m_nDisp      = this.m_xmlRes.GetValue("disp");  //显示模式0不显示 1 显示按钮 2 显示窗口 3 显示按钮与窗口
  

  this.Draw();  
}
/*
 * 定义全局变量g_CCftHelper
 */
var g_CCftHelper =null ;
if(!g_CCftHelper)
	g_CCftHelper = new CCftHelper();
	

	
function CCftHelper_CallBack(state,sts,str)
{
  try
  {
    switch(state)
  	{	
  		case 4://complete
  			switch(sts)
  			{
  				case 200://success
  					g_CCftHelper.m_xmlRes = new CXml(str);	
  					if((g_CCftHelper.m_xmlRes.GetValue("retcode") == "") ||
  					  (parseInt(g_CCftHelper.m_xmlRes.GetValue("retcode"),10) != 0))
  					  return false;
  					else
  					  g_CCftHelper.Show();
  					break;
  				default:
  					break;					
  			}
  		default:
  			break;
  	} 
  }
  catch(exp){}; 
}
function CCftHelper_HtmlEscape(str)
{
  var result = str;
  
  var searchStr = ">";
  var replaceStr = "%3e";
  var re = new RegExp(searchStr , "g");
  var result = result.replace(re, replaceStr);
  
  searchStr = "<";
  replaceStr = "%3c";
  re = new RegExp(searchStr , "g");
  result = result.replace(re, replaceStr);
  
  searchStr = "'";
  replaceStr = "%27";
  re = new RegExp(searchStr , "g");
  result = result.replace(re, replaceStr);
  
  searchStr = "\"";
  replaceStr = "%22";
  re = new RegExp(searchStr , "g");
  result = result.replace(re, replaceStr);
  
  searchStr = "=";
  replaceStr = "%3d";
  re = new RegExp(searchStr , "g");
  result = result.replace(re, replaceStr);
  
  searchStr = "\\\\";
  replaceStr = "%5c";
  re = new RegExp(searchStr , "g");
  result = result.replace(re, replaceStr);
  
  searchStr = "/";
  replaceStr = "%2f";
  re = new RegExp(searchStr , "g");
  result = result.replace(re, replaceStr);
  searchStr = " ";
  replaceStr = "%20";
  re = new RegExp(searchStr , "g");
  result = result.replace(re, replaceStr);
//  alert(result);
  return result;
}
function CCftHelper_Fetch()
{
try{  
	var reqdat = "tid=00004001";
	var http = new CHttpRequest(this.CallBack,true,2);	
  
  if(g_Helper_CSelfUrl.GetPara("Sender") == "")
  {
    //获取财付通自有的帮助主题    
    reqdat += "&location="+g_Helper_CSelfUrl.m_sFile;
	  http.Get("/cgi-bin/v1.0/cft_helper.cgi",reqdat);
  }
  else
  {
    //获取链接数据，并验证有效性
    g_CCookie.SetCookie("CftHelper_disp","show");
    
    reqdat +="&sender="+g_Helper_CSelfUrl.GetPara("Sender");
    reqdat +="&sign="+g_Helper_CSelfUrl.GetPara("Sign");
    reqdat +="&content="+this.HtmlEscape(g_Helper_CSelfUrl.GetPara("Content"));
    reqdat +="&height="+g_Helper_CSelfUrl.GetPara("Height");
    reqdat +="&width="+g_Helper_CSelfUrl.GetPara("Width");
    reqdat +="&x="+g_Helper_CSelfUrl.GetPara("x");
    reqdat +="&y="+g_Helper_CSelfUrl.GetPara("y");
    reqdat +="&disp="+g_Helper_CSelfUrl.GetPara("disp");
    //验证链接参数有效性 
//    alert(reqdat);
	  http.Get("/cgi-bin/v1.0/cft_helper.cgi",reqdat);
  } 
}catch(exp){}; 
}
