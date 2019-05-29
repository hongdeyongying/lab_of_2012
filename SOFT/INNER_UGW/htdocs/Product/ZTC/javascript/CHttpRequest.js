/* ----------------------------------------------------------------
 * ��װXMLHttpRequest����,�ṩһ�µĽӿڹ�ϵͳ����ģ��ʹ��
 * CHttpRequest.js
 * gaussgao 20060518
 * ----------------------------------------------------------------
 XMLHttpRequest ���󷽷� ���� ���� 
	abort() 				
		ֹͣ��ǰ���� 
	getAllResponseHeaders() 
		��Ϊ�ַ�������������headers 
	getResponseHeader("headerLabel") 
		��Ϊ�ַ������ʵ�����header��ǩ 
	open("method","URL"[,asyncFlag[,"userName"[, "password"]]]) 
		����δ���������Ŀ�� URL, ����, ���������� 
	send(content) 
		�������� 
	setRequestHeader("label", "value") 
		����header��������һ���� 
	
  XMLHttpRequest �������� ���� ���� 
	onreadystatechange 
		״̬�ı���¼������� 
	readyState 		
		����״̬(integer):
			0 = δ��ʼ��
			1 = ��ȡ��
			2 = �Ѷ�ȡ
			3 = ������
			4 = ��� 
	responseText 	1
		���������̷������ݵ��ı��汾 
	responseXML 	2
		���������̷������ݵļ���DOM��XML�ĵ����� 
	status 			
		���������ص�״̬��, �磺404 = "�ļ�ĩ�ҵ�" ��200 ="�ɹ�" 
	statusText 		
		���������ص�״̬�ı���Ϣ 
 */

/*����:��������,����������
 */
function CHttpRequest(fCallback,mode,restype)
{
	//��������
	this.m_HttpRequest = createXMLHttpRequest();	
	//����
	this.m_bAsyncFlag = mode;	
	if( restype )
		this.m_iResType	= restype;
	else
		this.m_iResType	= 2;	//responseXml
	
	//����
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
		
	throw new Error("��û�а�װXML������,��ʹ��INTERNET EXPLORE 5���ϵ������.");
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
//�ص�����:ִ��״̬,������,��������
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
//ִ�й���
function GetTest()
{
	var http = new CHttpRequest(CallBack_Test,false,1);
	http.Get("/test.xml","a=1&b=2");
}
GetTest();
-------------------------------------------------------------*/
