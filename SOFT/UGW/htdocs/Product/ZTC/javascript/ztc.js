var objClientLicense;
var frmZtcSetting;	

try
{
	objClientLicense = new ActiveXObject("CLIENTLICENSE.Validate");
	frmZtcSetting = document.getElementById("FRM_ZTC_SETTING");	
	frmZtcSetting.btn_event_save.onclick = CZtc_SetValue;
	frmZtcSetting.btn_event_read.onclick = CZtc_GetValue;
}
catch(ex)
{
};

function CZtc_GetValue()
{
	try
	{
		var retcd;
		if(objClientLicense.IsValid("MS_WS") == 0)
		{
			frmZtcSetting.datasrc.value = objClientLicense.GetVar("datasrc");
			frmZtcSetting.Key.value = objClientLicense.GetVar("Key");			
			frmZtcSetting.ztcUin.value = objClientLicense.GetVar("ztcUin");			
		}
	}
	catch(ex){};
}


function CZtc_SetValue()
{
	try
	{
		var retcd;
		if(objClientLicense.IsValid("MS_WS") == 0)
		{
			retcd = objClientLicense.SetVar("datasrc",frmZtcSetting.datasrc.value);
			retcd = objClientLicense.SetVar("Key",frmZtcSetting.Key.value);
			
			if(retcd == 0)
			{
				alert("数据修改成功");
			}
		}
	}
	catch(ex){};
}
