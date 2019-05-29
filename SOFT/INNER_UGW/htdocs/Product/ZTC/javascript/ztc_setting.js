var objClientLicense;
var frmZtcSetting;	
var infRetMsg;

try
{
	objClientLicense = new ActiveXObject("CLIENTLICENSE.Validate");
	frmZtcSetting = document.getElementById("FRM_ZTC_SETTING");	
	
	
	
	frmZtcSetting.btn_event_save.onclick = CZtc_SetValue;
	frmZtcSetting.btn_event_read.onclick = CZtc_GetValue;
	
	infRetMsg = document.getElementById("INF_RETMSG");	
	infRetMsg.innerText = ("");
}
catch(ex)
{
};

function CZtc_GetValue()
{
	try
	{
		infRetMsg.innerText ="";
		var retcd;
		if(objClientLicense.IsValid("MS_WS") == 0)
		{
			//frmZtcSetting.datasrc.value = objClientLicense.GetVar("datasrc");
			frmZtcSetting.Key.value = objClientLicense.GetVar("Key");			
			frmZtcSetting.ztcUin.value = objClientLicense.GetVar("ztcUin");		

			infRetMsg.innerText = ("OK:取当前设置成功");
		}
		else
			infRetMsg.innerText = ("Err:取当前设置失败");
	}
	catch(ex){};
}


function CZtc_SetValue()
{
	try
	{
		infRetMsg.innerText ="";
		var retcd;
		if(objClientLicense.IsValid("MS_WS") == 0)
		{
			//retcd = objClientLicense.SetVar("datasrc",frmZtcSetting.datasrc.value);
			retcd = objClientLicense.SetVar("Key",frmZtcSetting.Key.value);
			
			if(retcd == 0)
			{
				infRetMsg.innerText = ("OK:保存设置成功");
			}
			else
			{
				infRetMsg.innerText = ("Err：保存设置失败");
			}
		}
	}
	catch(ex){};
}
