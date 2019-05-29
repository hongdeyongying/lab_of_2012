/*
 * 获取自身URL的参数内容和参数值
 * CSelfUrl.js
 */

function CSelfUrl()
{
	this.m_sUrl = "";
	this.m_sQueryString = "";
	this.m_sDomin = "";
	this.Init = CSelfUrl_Init;
	this.GetPara = CSelfUrl_GetPara;
	this.ParsePara = CSelfUrl_ParsePara;
	this.GetFormString = CSelfUrl_GetFormString;
	this.GetCookie = CSelfUrl_GetCookie;
} 

function CSelfUrl_Init()
{
	this.m_sUrl = window.document.URL.replace(/#$/g, "");
	this.m_sQueryString = this.m_sUrl.split("?")[1];
	this.m_sDomin = this.m_sUrl.split("?")[0];

}

function CSelfUrl_GetFormString(form)
{
	var reqdat = "";
	var first_flag = true;
	for(var i=0; i < form.length; i++)
	{
		if(form.elements[i].type.toUpperCase() == "CHECKBOX" && !form.elements[i].checked)
		{
			continue;
		}
		
		if(form.elements[i].type.toUpperCase() == "RADIO" && !form.elements[i].checked)
		{
			continue;
		}
		
		if(form.elements[i].name == "tm")
			continue;
		
		if(form.elements[i].name!="")
		{
			if(first_flag)
			{
				first_flag = false;
				//reqdat = reqdat + form.elements[i].name + "="+ (form.elements[i].value).replace("\r\n","%0D%0A");
				reqdat = reqdat + form.elements[i].name + "="+ encodeURIComponent(form.elements[i].value)
				
			}
			else
			{
				//reqdat = reqdat + "&" + form.elements[i].name + "="+ (form.elements[i].value).replace("\r\n","%0D%0A");
				reqdat = reqdat + "&" + form.elements[i].name + "="+ encodeURIComponent(form.elements[i].value)
			}
		}
	}
//	alert(reqdat);
	return reqdat;
}

function CSelfUrl_GetPara(para_name)
{
	var queryStr;
	var named;
	
	this.Init();
	
	queryStr = this.m_sQueryString; 
	if(queryStr == null)
	{
		queryStr = "";
	} 	  
	named = queryStr.split("&"); 
	
	var len = named.length;
	for (var i = 0; i < len; ++i)
	{
		//alert(named[i]);
		var nv = named[i];
		var j = nv.indexOf("=");
		if (j == -1)
			continue;
		
		var varName = nv.substring(0, j);
		var varVal = nv.substring(j+1, nv.length); 	
		
		if (varName==para_name)
		{		
			return decodeURIComponent(varVal);
		}
	}
	return "";   
}

function CSelfUrl_ParsePara()
{
	var queryStr;
	var named;
	
	this.Init();
	
	queryStr = this.m_sQueryString; 
	if(queryStr == null)
	{
		queryStr = "";
	} 	  
	named = queryStr.split("&"); 
	
	var len = named.length;
	for (var i = 0; i < len; ++i)
	{
		//alert(named[i]);
		var nv = named[i];
		var j = nv.indexOf("=");
		if (j == -1)
			continue;
		
		var varName = nv.substring(0, j);
		var varVal = nv.substring(j+1, nv.length); 	
		
		ele = document.getElementById(varName);
			
		if(!ele)
			continue;
			
		if (ele.tagName.toUpperCase() == 'TEXTAREA' || ele.tagName.toUpperCase() == 'INPUT' || ele.tagName.toUpperCase() == 'SELECT')
		{	
			if(ele.type.toUpperCase() == "RADIO")
			{
				ele = document.getElementsByName(varName);
				if(!ele)
					continue;
				for(var j=0; j<ele.length; j++)
				{
					if(ele[j].value == decodeURIComponent(varVal))
					{
						ele[j].checked = true;
						break;
					}
				}
			}
			else
				ele.value = decodeURIComponent(varVal);
		}
		else
		{
			ele.innerHTML = decodeURIComponent(varVal);
		}
		

	}
  
}

function CSelfUrl_GetCookie(cookiename)
{
 var allcookies=document.cookie;
 var pos=allcookies.indexOf(cookiename+"=") ; 

 if (pos!=-1)
 { 
 	var start=pos +cookiename.length+1 //从现有的cookie(字符串)中提现有值,(cookie名+"="的长度) 
 	var end=allcookies.indexOf(";",start); 
 	
 	if (end==-1) 
	 end=allcookies.length; 

  var value= allcookies.substring(start,end); //提取值 
  value=unescape(value); //解码 
  return value; 
 }
 
 return "";
}

var g_CSelfUrl = null ;
if(!g_CSelfUrl)
	g_CSelfUrl = new CSelfUrl();
