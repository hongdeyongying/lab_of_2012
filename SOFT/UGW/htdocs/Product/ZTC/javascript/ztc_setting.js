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

			infRetMsg.innerText = ("OK:ȡ��ǰ���óɹ�");
		}
		else
			infRetMsg.innerText = ("Err:ȡ��ǰ����ʧ��");
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
				infRetMsg.innerText = ("OK:�������óɹ�");
			}
			else
			{
				infRetMsg.innerText = ("Err����������ʧ��");
			}
		}
	}
	catch(ex){};
}