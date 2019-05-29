
function CAutoJustForm()
{	
	this.GetPageSize = CAutoJustForm_GetPageSize;
	this.GetAbsPos = CAutoJustForm_GetAbsPos;
	this.SetPageHeightById = CAutoJustForm_SetPageHeightById;
	this.refresh = CAutoJustForm_refresh;
	
	this.refresh();
	
}
function CAutoJustForm_refresh()
{
	this.GetPageSize();
	this.SetPageHeightById();
}

function CAutoJustForm_GetPageSize(){

	var windowWidth, windowHeight;
	var xScroll, yScroll;
	
	if (window.innerHeight && window.scrollMaxY) 
	{
		xScroll = document.body.scrollWidth;
		yScroll = window.innerHeight + window.scrollMaxY;
	} 
	else if (document.body.scrollHeight > document.body.offsetHeight)
	{ // all but Explorer Mac
		xScroll = document.body.scrollWidth;
		yScroll = document.body.scrollHeight;
	} 
	else 
	{ // Explorer Mac...would also work in Explorer 6 Strict, Mozilla and Safari
		xScroll = document.body.offsetWidth;
		yScroll = document.body.offsetHeight;
	}
	
	if (self.innerHeight) 
	{ // all except Explorer
		windowWidth = self.innerWidth;
		windowHeight = self.innerHeight;
	} 
	else if (document.documentElement && document.documentElement.clientHeight) 
	{ // Explorer 6 Strict Mode
		windowWidth = document.documentElement.clientWidth;
		windowHeight = document.documentElement.clientHeight;
	} 
	else if (document.body) 
	{ // other Explorers
		windowWidth = document.body.clientWidth;
		windowHeight = document.body.clientHeight;
	}
	
	// for small pages with total height less then height of the viewport
	if(yScroll < windowHeight)
	{
		pageHeight = windowHeight;
	} 
	else 
	{
		pageHeight = yScroll;
	}
	
	// for small pages with total width less then width of the viewport
	if(xScroll < windowWidth)
	{
		pageWidth = windowWidth;
	} 
	else 
	{
		pageWidth = xScroll;
	}
	
	this.m_iPageWidth = parseInt(pageWidth,10);
	this.m_iPageHeight = parseInt(pageHeight,10);
	this.m_iWindowWidth = parseInt(windowWidth,10);
	this.m_iWindowHeight = parseInt(windowHeight,10);
	
	var msg = "PageWidth : " + this.m_iPageWidth + "\tPageHeight:" + this.m_iPageHeight + "\r\n"
			 +"WindowWidth:" +  this.m_iWindowWidth +"\tWindowHeight:" + this.m_iWindowHeight;
	//alert(msg);
	//arrayPageSize = new Array(pageWidth,pageHeight,windowWidth,windowHeight)
	//return arrayPageSize;
}


function CAutoJustForm_GetAbsPos(BaseId)
{
	var objRet = null;
	var objBase=document.getElementById(BaseId);
	if(objBase){
		objRet = new Object();
		objRet.height=objBase.offsetHeight;
		objRet.width=objBase.offsetWidth;
		objRet.left=objBase.offsetLeft;
		objRet.top=objBase.offsetTop;
		while(objBase = objBase.offsetParent){
			objRet.left += objBase.offsetLeft;
			objRet.top += objBase.offsetTop;
		}
	}
	//var msg = "OBJ:"+BaseId+"\r\nWidth : " + objRet.width + "\tHeight:" + objRet.height + "\r\n"
	//		 +"Left:" +  objRet.left +"\tTop:" + objRet.top;
	//alert(msg);
	return objRet;
}
function CAutoJustForm_SetNoScrollRectById(objid)
{
	var obj=document.getElementById(objid);

	//alert("!width:"+obj.offsetWidth+"\theight:"+obj.offsetHeight+"\r\n"+"scrollwidth:"+obj.document.body.scrollWidth+"\theight:"+obj.document.body.scrollHeight+"\r\n");
	/*
	if(obj.offsetWidth < obj.document.body.scrollWidth)
		obj.style.width = obj.document.body.scrollWidth;
	if(obj.offsetHeight < obj.document.body.scrollHeight )
		obj.style.height = obj.document.body.scrollHeight ;
		
		
	if(obj.offsetWidth < obj.contentDocument.body.scrollWidth)
		obj.style.width = obj.contentDocument.body.scrollWidth;
	if(obj.offsetHeight < obj.contentDocument.body.scrollHeight )
		obj.style.height = obj.contentDocument.body.scrollHeight ;
	*/
	//alert("!width:"+obj.offsetWidth+"\theight:"+obj.offsetHeight+"\r\n"+"scrollwidth:"+obj.contentDocument.body.scrollWidth+"\theight:"+obj.contentDocument.body.scrollHeight+"\r\n");
}
function CAutoJustForm_SetPageHeightById()
{
	//CAutoJustForm_SetNoScrollRectById("content");
	
	//var navPosObj = this.GetAbsPos("nav");
	var langbarObj = document.getElementById("langbar");
	var menubarObj = document.getElementById("menubar");
	var logobarObj = document.getElementById("logobar");
	var contentObj = document.getElementById("content");
	var footObj    = document.getElementById("footbar");
	
	var contPosObj = this.GetAbsPos('content');
	var footPosObj = this.GetAbsPos('footbar');
	
	
	
	var height = (this.m_iPageHeight < this.m_iWindowHeight)?this.m_iWindowHeight:this.m_iPageHeight;	
	var width = (this.m_iPageWidth < this.m_iWindowWidth)?this.m_iWindowWidth:this.m_iPageWidth;
	
	//alert(width + " " + height);
	
	var minWidth = 1400;
	var minHeight = 300;
	if(width < minWidth)
	{
		langbarObj.style.width = minWidth + 'px';
		logobarObj.style.width = minWidth + 'px';
		menubarObj.style.width = minWidth + 'px';
		contentObj.style.width = minWidth + 'px';
		footObj.style.width    = minWidth + 'px';
		
		//alert(width + " " + height);
	}
	else
	{
		langbarObj.style.width = 100 + '%';
		logobarObj.style.width = 100 + '%';
		menubarObj.style.width = 100 + '%';
		contentObj.style.width = 100 + '%';
		footObj.style.width    = 100 + '%';
			
	}
	
	if(height < minHeight)
	{
		contentObj.style.height = minHeight - langbarObj.style.height  - menubarObj.style.height - footObj.style.height ;
		
		if(objL.style.display != "none")
			contentObj.style.height -= logobarObj.style.height;	

		//alert(minHeight + " " + height + " " + contentObj.style.height);
	
		return;
	}
	
	height -= footPosObj.height;
	
	//alert(width + " " + height);
	//var width = (this.m_iPageWidth < this.m_iWindowWidth)?this.m_iWindowWidth:this.m_iPageWidth;
	
	
	//var navobj = document.getElementById("nav");
	
	//alert("nav.height:"+navobj.style.height.toString() +"\r\ncontent.height:"+ contentobj.style.height.toString());
	
	contentObj.style.height = ((height - contPosObj.top ) > contPosObj.height?(height - contPosObj.top):contPosObj.height) +'px';	
	
	//alert(footPosObj.height + " " + contentobj.style.height + " " +  height + " " + contPosObj.top);
	//navobj.style.height = ((height - navPosObj.top) > navPosObj.height?(height - navPosObj.top):navPosObj.height) +'px';
	
	//contentobj.style.width = width - navPosObj.left - navPosObj.width -2  +'px';
	
	
	
	
	/*
	if(contentobj.document)
	{
		contentobj.style.height=(contentobj.document.body.scrollHeight<contentobj.style.height?contentobj.style.height:contentobj.document.body.scrollHeight) + "px";
		
		//contentobj.document.body.style.overflowX='auto';
		contentobj.style.overflowY='auto'; 
	}
	
	if(navobj.style.height < contentobj.style.height)
		navobj.style.height = contentobj.style.height;
	
	//alert("nav.height:"+navobj.style.height.toString() +"\r\ncontent.height:"+ contentobj.style.height.toString());
	*/
}

var g_CAutoJustForm =null ;

try
{
	if(!g_CAutoJustForm)
	{
		//var contentobj = document.getElementById("content");
		
		//g_CAutoAjustFood =new 
		CAutoJustForm();
		
		window.onresize =  CAutoJustForm;
		//contentobj.onload = CAutoJustForm;
	}		
}
catch(e) 
{
	if (e instanceof Error) {  // Is it an instance of Error or a subclass?
        //alert(e.name + ": " + e.message);
    }
}


	
