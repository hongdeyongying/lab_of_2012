/*
 * 操作XML文件，避免不存在的节点抛出异常
 */
function CXml(indat)
{
//	alert(typeof(indat));
	if(typeof(indat) == "string")
	{
      if("undefined" != typeof(DOMParser))
	   	{
            var parser = new DOMParser();
            this.m_xmlObj = parser.parseFromString(indat, "application/xml");
	   	}
	    else if(window.ActiveXObject)
	    {
	        this.m_xmlObj = new ActiveXObject("Microsoft.XMLDOM");
	        this.m_xmlObj.async = false;
            this.m_xmlObj.loadXML(indat);
	        //while(obj.readyState != 4) {};//
	    }
        else
        {
            var url = "data:text/xml;charset=utf-8," + encodeURIComponent(indat);
            var request = new XMLHttpRequest( );
            request.open("GET", url, false);
            request.send(null);
            this.m_xmlObj = request.responseXML;
            request = null;
        }

	}
	else if(typeof(indat) == "object")
	{
		this.m_xmlObj = indat;
	}
	else
	{
		throw new Error("CHttpRequest Return an Object not recogonaized");
	}
	/*
	else
	{
		throw new Error("CHttpRequest 返回一个不能识别的对象.");
		
	}*/

	this.GetValue = CXml_GetValue;
	this.GetNodes = CXml_GetNodes;
	this.GetChildValue = CXml_GetChildValue;
	this.GetChildNodes = CXml_GetChildNodes;
	this.GetParentNode = CXml_GetParentNode;
	this.GetAttValue = CXml_GetAttValue;
	this.GetNodeValue = CXml_GetNodeValue;
}


function CXml_GetValue(node_name)
{
	var res;
	try
	{
		res = this.m_xmlObj.getElementsByTagName(node_name)[0].firstChild.data
	}
	catch(ex)
	{
		res = "";
	}
	return res;
}

function CXml_GetNodes(node_name)
{
	var res;
	try
	{
		res = this.m_xmlObj.getElementsByTagName(node_name);
	}
	catch(ex)
	{
		res = "";
	}
	return res;
}
function CXml_GetChildNodes(node,node_name)
{
	var res;
	try
	{
		res = node.getElementsByTagName(node_name);
	}
	catch(ex)
	{
		res = "";
	}
	return res;
}

function CXml_GetChildValue(node, child_node_name)
{
	var res;
	try
	{
		res = node.getElementsByTagName(child_node_name)[0].firstChild.data
	}
	catch(ex)
	{
		res = "";
	}
	return res;
}function CXml_GetParentNode(node)
{
	var res;
	try
	{
		res = node.parentNode;
	}
	catch(ex)
	{
		res = "";
	}
	return res;
}

function CXml_GetAttValue(node, att_name)
{


	var res = "";
	try
	{
		for(var i=0; i<node.attributes.length; i++)
		{
			if(node.attributes[i].nodeName == att_name)
			{
				res = node.attributes[i].nodeValue;
				break;
			}
		}
	}
	catch(ex)
	{
		res = "";
	}

	return res;
}
function CXml_GetNodeValue(node)
{
	var res;
	try
	{
		res = node.firstChild.data
	}
	catch(ex)
	{
		res = "";
	}
	return res;
}
