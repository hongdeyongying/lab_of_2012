var objMsBpmlAsyn;
var frmPnr;	
var tblResult;

try
{
	objMsBpmlAsyn = new ActiveXObject("MSBPML.AsynFlow");
	
	frmPnr = document.getElementById("FRM_PNR");	
	
	
	frmPnr.btn_pnrindb.onclick = CB2BPNRInDB_DO;
	frmPnr.btn_genorder.onclick = CB2BPNRInDB_GenOrder;
}
catch(ex)
{
	//document.getElementById("debuginfo").value = "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
};

function GenReqData(form)
{
	var reqdat = "";
	var first_flag = true;
	for(var i=0; i < form.length; i++)
	{
		if(form.elements[i].type.toUpperCase() == "CHECKBOX" && !form.elements[i].checked)
		{
			continue;
		}
		
		if(form.elements[i].name!="")
		{
			if(first_flag)
			{
				first_flag = false;
				reqdat = reqdat + form.elements[i].name + "="+ (form.elements[i].value).replace("\r\n","%0D%0A");
			}
			else
			{
				reqdat = reqdat + "&" + form.elements[i].name + "="+ (form.elements[i].value).replace("\r\n","%0D%0A");
			}
		}
	}
	alert(reqdat);
	return reqdat;
}

function CB2BPNRInDB_DO()
{
	document.getElementById("debuginfo").value="";	
	var file,inpara,result;
		
	//file = frmLogin.bpml_file.value;
	file   = "F:\\NEW_LIFE\\SETUP\\Cnf\\AIRLINE\\PNRInDb_B2Bcsair.xml";
	//alert(file);
	inpara = GenReqData(frmPnr);
	//FillResult(11,22);
	objMsBpmlAsyn.CallBack = DoPost;
//alert(2);
	objMsBpmlAsyn.Execute(file,inpara);
}
function DoPost(cnt ,sts)
{	
	if(sts != 0)
	{
		alert("Err:PNR In DB");
		return;
	}
	var xml = new CXml(cnt);		
	
	if(xml.GetValue("retcode") == "0")
	{
		alert("OK:PNR In DB");     
		
		frmPnr.contactor.value = xml.GetValue("contactor");
		frmPnr.name.value = xml.GetValue("name");
		frmPnr.orderid.value = xml.GetValue("order_id");
		frmPnr.total_fee.value = xml.GetValue("total_fee");
	}	
	else
	{
		alert("Err:PNR In DB");
	}
document.getElementById("debuginfo").value=cnt;	
}

function CB2BPNRInDB_GenOrder()
{
	document.getElementById("debuginfo").value="";	
	var file,inpara,result;
		
	//file = frmLogin.bpml_file.value;
	file   = "F:\\NEW_LIFE\\SETUP\\Cnf\\AIRLINE\\GenOrder_B2Bcsair.xml";
	//alert(file);
	inpara = GenReqData(frmPnr);
	//FillResult(11,22);
	objMsBpmlAsyn.CallBack = GenOrderPost;
//alert(2);
	objMsBpmlAsyn.Execute(file,inpara);
}
function GenOrderPost(cnt ,sts)
{	
	if(sts != 0)
	{
		alert("Err:GenOrder");
		return;
	}
	var xml = new CXml(cnt);		
	
	if(xml.GetValue("retcode") == "0")
	{
		alert("OK:GenOrder");     
		frmPnr.pay_orderid.value = xml.GetValue("billno");
		frmPnr.pay_url.value = xml.GetValue("url");
		
		
	}	
	else
	{
		alert("Err:GenOrder");
	}
document.getElementById("debuginfo").value=cnt;	
}