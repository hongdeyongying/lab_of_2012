var objMsBpmlAsyn;
var frmLogin;	
var tblResult;
var imgVerify;

try
{

	objMsBpmlAsyn = new ActiveXObject("MSBPML.AsynFlow");
	
	frmLogin = document.getElementById("FRM_LOGIN");	
	
	imgVerify = document.getElementById("img_verify");
	
	frmLogin.btn_getimg.onclick = CB2BLogin_GetImg;
	frmLogin.btn_login.onclick = CB2BLogin_Login;
}
catch(ex)
{
alert(1);
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
	//alert(reqdat);
	return reqdat;
}
function CB2BLogin_GetImg()
{
	var file,inpara,result;
		
	//file = frmLogin.bpml_file.value;
	file   = "G:\\My-Soft\产品\\SETUP\Cnf\\AIRLINE\\GetVerifyImg_B2Bcsair.xml";
	//alert(file);
//	inpara = GenReqData(frmLogin);
//document.getElementById("debuginfo").value=inpara;	
	//FillResult(11,22);
	objMsBpmlAsyn.CallBack = FillResult;
//alert(2);
	objMsBpmlAsyn.Execute(file,inpara);
}
function FillResult(cnt ,sts)
{
	alert("call back");
	if(sts != 0)
	{
		alert("查询失败");
		return;
	}
	var xml = new CXml(cnt);		
	
	if(xml.GetValue("retcode") == "0")
	{
		imgVerify.src=xml.GetValue("url")   ;   
		frmLogin.v.value = xml.GetValue("v")     
	}	
//alert(sts+ " :"  +cnt);	
//document.getElementById("debuginfo").value=cnt;	
}
function CB2BLogin_Login()
{
	var file,inpara,result;
		
	//file = frmLogin.bpml_file.value;
	file   = "G:\\My-Soft\产品\\SETUP\Cnf\\AIRLINE\\Login_B2Bcsair.xml";
	//alert(file);
	inpara = GenReqData(frmLogin);
	//FillResult(11,22);
	objMsBpmlAsyn.CallBack = LoginPost;
//alert(2);
	objMsBpmlAsyn.Execute(file,inpara);
}
function LoginPost(cnt ,sts)
{	
	if(sts != 0)
	{
		alert("Err:Login");
		return;
	}
	var xml = new CXml(cnt);		
	
	if(xml.GetValue("retcode") == "0")
	{
		alert("OK:Login");     
	}	
	else
	{
		alert("Err:Login");
	}
document.getElementById("debuginfo").value=cnt;	
}