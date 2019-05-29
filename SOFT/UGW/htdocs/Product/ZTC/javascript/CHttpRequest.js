/* ----------------------------------------------------------------
 * 封装XMLHttpRequest对象,提供一致的接口供系统其他模块使用
 * CHttpRequest.js
 * gaussgao 20060518
 * ----------------------------------------------------------------
 XMLHttpRequest 对象方法 方法 描述 
	abort() 				
		停止当前请求 
	getAllResponseHeaders() 
		作为字符串返问完整的headers 
	getResponseHeader("headerLabel") 
		作为字符串返问单个的header标签 
	open("method","URL"[,asyncFlag[,"userName"[, "password"]]]) 
		设置未决的请求的目标 URL, 方法, 和其他参数 
	send(content) 
		发送请求 
	setRequestHeader("label", "value") 
		设置header并和请求一起发送 
	
  XMLHttpRequest 对象属性 属性 描述 
	onreadystatechange 
		状态改变的事件触发器 
	readyState 		
		对象状态(integer):
			0 = 未初始化
			1 = 读取中
			2 = 已读取
			3 = 交互中
			4 = 完成 
	responseText 	1
		服务器进程返回数据的文本版本 
	responseXML 	2
		服务器进程返回数据的兼容DOM的XML文档对象 
	status 			
		服务器返回的状态码, 如：404 = "文件末找到" 、200 ="成功" 
	statusText 		
		服务器返回的状态文本信息 
 */

/*功能:创建对象,并设置属性
 */
function CHttpRequest(fCallback,mode,restype)
{
	//创建对象
	this.m_HttpRequest = createXMLHttpRequest();	
	//属性
	this.m_bAsyncFlag = mode;	
	if( restype )
		this.m_iResType	= restype;
	else
		this.m_iResType	= 2;	//responseXml
	
	//方法
	this.Post = CHttpRequest_Post;
	this.Get  = CHttpRequest_Get;
	this.m_fCallBack = fCallback;
	
}

function CHttpRequest_Get(dst,para)
{
	var now = new Date();
	var rnd = Math.floor(Math.random() * 100000);
	var ptm = now.getSeconds().toString()+rnd.toString()+now.getMinutes().toString();
	para += "&ptm="+ptm.toString();
	
	var http = this;
	function tm_back()
	{
		if(http.m_HttpRequest.readyState == 4)
		{
			if(http.m_HttpRequest.status == 200)
			{
				if(http.m_iResType == 1)
					http.m_fCallBack(4,200,http.m_HttpRequest.responseText);
				else
					http.m_fCallBack(4,200,http.m_HttpRequest.responseXML);
			}	
			else
			{
				http.m_fCallBack(4,http.m_HttpRequest.status,null);		
			}
		}
		else
		{
			http.m_fCallBack(http.m_HttpRequest.readyState,null,null);		
		}
	}
	this.m_HttpRequest.onreadystatechange = tm_back;
	this.m_HttpRequest.open("GET",dst+"?"+para,this.m_bAsyncFlag);
	this.m_HttpRequest.setRequestHeader("Content-Type","application/x-www-form-urlencoded;charset=GB2312");
	this.m_HttpRequest.setRequestHeader("Cache-Control","no-cache");
	this.m_HttpRequest.send("");	
}

function CHttpRequest_Post(dst,para)
{
	var http = this;
	function tm_back()
	{
		if(http.m_HttpRequest.readyState == 4)
		{
			if(http.m_HttpRequest.status == 200)
			{
				if(http.m_iResType == 1)
					http.m_fCallBack(4,200,http.m_HttpRequest.responseText);
				else
					http.m_fCallBack(4,200,http.m_HttpRequest.responseXML);
			}	
			else
			{
				http.m_fCallBack(4,http.m_HttpRequest.status,null);		
			}
		}
		else
		{
			http.m_fCallBack(http.m_HttpRequest.readyState,null,null);		
		}
	}
	this.m_HttpRequest.onreadystatechange = tm_back;
	
	this.m_HttpRequest.open("POST",dst,this.m_bAsyncFlag);
	this.m_HttpRequest.setRequestHeader("Content-Length",para.length);
	this.m_HttpRequest.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
	//this.m_HttpRequest.setRequestHeader("Content_Type","text/xml;charset=GB2312");
	this.m_HttpRequest.send(para);	
}

function getXMLPrefix() 
{
	if (getXMLPrefix.prefix)
		return getXMLPrefix.prefix;
	
	var prefixes = ["MSXML3", "MSXML2", "MSXML", "Microsoft"];
	
	var obj, obj2;
	
	for(var i = 0; i < prefixes.length; i++) 
	{
		try 
		{
			//Attempt to create an XmlHttp object using the current prefix
			obj = new ActiveXObject(prefixes[i] + ".XmlHttp");
			return getXMLPrefix.prefix = prefixes[i];
		}
		catch (ex) 
		{};
	}
		
	throw new Error("您没有安装XML解析器,请使用INTERNET EXPLORE 5以上的浏览器.");
}

function createXMLHttpRequest()
{
	try 
	{
		// Attempt to create it "the Mozilla way" 
		if (window.XMLHttpRequest) 
		{
			return new XMLHttpRequest();
		}
		// Guess not - now the IE way
		if (window.ActiveXObject) 
		{
			return new ActiveXObject(getXMLPrefix() + ".XmlHttp");
		}
	}
	catch (ex) 
	{
		alert(ex.message);
	};
	
	return false;
}


//examples
/*-------------------------------------------------------
//回调函数:执行状态,返回码,返回内容
function CallBack_Test(state,sts,str)
{
	switch(state)
	{
	case 0://initting			
	case 1://reading
	case 2://readed
	case 3://interact
		alert(state);
		break;
	case 4://complete
		switch(sts)
		{
		case 200://success
			alert(str);break;				
		case 404://notfound
			alert(sts);
		default:
			break;
		}
	default:
		break;
	}
	
}
//执行过程
function GetTest()
{
	var http = new CHttpRequest(CallBack_Test,false,1);
	http.Get("/test.xml","a=1&b=2");
}
GetTest();
-------------------------------------------------------------*/
