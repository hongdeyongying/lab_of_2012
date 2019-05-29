var objZTCLib;
var frmZtcSale;	
var infRetMsg;
var tblZtcSaleLog;

try
{
	infRetMsg = document.getElementById("INF_RETMSG");	
	infRetMsg.innerText = ("");
	//objClientLicense = new ActiveXObject("CLIENTLICENSE.Validate");
	objZTCLib= new ActiveXObject("CFTMCHINTERFACE.ZTCSale");
	frmZtcSale = document.getElementById("FRM_ZTC_SALE");	
	
	
	tblZtcSaleLog = document.getElementById("TBL_ZTC_SALE_RES");	
		
	frmZtcSale.btn_event_sale.onclick = CZtc_Sale;
	frmZtcSale.ServiceCode.onchange = CZtc_onSelectServiceCode;
}
catch(ex)
{
	infRetMsg.innerHTML =  "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
};

/*ȡ��ǰʱ��*/
function GetCurrentTime()
{
	var now= new Date();
	var year=now.getYear();
	var month=now.getMonth()+1;
	var day=now.getDate();
	var hour=now.getHours();
	var minute=now.getMinutes();
	var second=now.getSeconds();
	
	var result = year+"-"+month+"-"+day+" "+hour+":"+minute+":"+second;
	
	return result;

}
function CZtc_onSelectServiceCode()
{
	try
	{
		var frm = frmZtcSale; 

		var tips_buycount = document.getElementById("Tips_BuyCount"); 
		
		var tips_comm1 = document.getElementById("Tips_comm1"); 

		tips_buycount.innerText ="";
		tips_comm1.innerText ="";

		switch(frm.ServiceCode.value)
		{
		case "QQACCT_SAVE" : //��BuyCount��ʾ������ȡֵ��Χ[1, 1000]
			tips_buycount.innerText = "* Q�ҵĸ�����ȡֵ��Χ[1,1000]" ;
			break;
		case "-QQPOINT":
			tips_buycount.innerText = "* Q��ĸ�����������10����������ȡֵ��Χ��[10, 10000]" ;
			break;
		case "LTMCLUB":
		case "XXJZGW":
		case "XXQGAME":
		case "XXQQF":
		case "PETVIP":
		case "XXQQT":
		case "XXZXYY":
		case "XXLOVE":
		case "QQR2BY":
		case "DNFHZ":
		case "QQFCZZ":
		case "QTD512M":
		case "-XXYXLB":
			tips_buycount.innerText = "* ��ʾ������ȡֵ��Χ[1, 24]" ;
			break;
		case "QQKDC":
			tips_buycount.innerText = "* ��ʾ������������100����������ȡֵ��Χ��[100, 100000]" ;
			tips_comm1.innerText = "* ��ҽ�����ɫ�Ĵ�����Ŀǰ1Ϊ��������2Ϊ��ͨ����3Ϊ���Ŷ���" ;
			break;
		case "-DNFDQ":
			tips_buycount.innerText = "* ��ʾ������������100����������ȡֵ��Χ��[100, 100000]" ;
			break;
			
		}
	}
	catch(ex)
	{
		infRetMsg.innerHTML =  "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
			
	}
}
function CZtc_RtInsertToDB(dt,au,p,c,cm1,cm2,bn,st,msg,dt1)
{		

		var retcd = objZTCLib.OpenLog("");
		if(retcd != 0) 
		{
			infRetMsg.innerText = ("Err:�����ݿ�ʧ��");
			return ;
		}
			
		retcd = objZTCLib.AddLog(dt,au,p,c,cm1,cm2,bn,st,msg,dt1);
		
		if(retcd != 0) 
		{
			infRetMsg.innerText = ("Err:�������ݿ�ʧ��");
			//alert(objZTCLib.GetLastError());
		}
		retcd = objZTCLib.CloseLog();
		if(retcd != 0) 
		{
			infRetMsg.innerText = ("Err:�ر����ݿ�ʧ��");
		}
	
}

function CZtc_InsertIoTable(dt,au,p,c,cm1,cm2,bn,st,msg,dt1)
{
	try
	{
		var tbody = tblZtcSaleLog;
		var objTempRow = tbody.rows[0];        //ȡ��ģ����
		//var objNewRow = tbody.insertRow( tbody.rows.length );
		var objNewRow = tbody.insertRow( 1 );
		objNewRow.id = tbody.rows.length-1; 

		for ( var i=0 ; i<objTempRow.cells.length ; i++ ) 
		{ 
			var objNewCell = objNewRow.insertCell( i ); 
			switch(i+1)
			{
			case 1:
			{
				objNewCell.innerHTML = dt;
				break;
			}
			case 2:
			{
				objNewCell.innerHTML = au;
				break;
			}
			case 3:
			{
				objNewCell.innerHTML = p;
				break;
			}
			case 4:
			{
				objNewCell.innerHTML = c;
				break;
			}
			case 5:
			{
				objNewCell.innerHTML = cm1;
				break;
			}
			case 6:
			{
				objNewCell.innerHTML = bn;
				break;
			}
			case 7:
			{
				objNewCell.innerHTML = st;
				break;
			}
			case 8:
			{
				objNewCell.innerHTML = msg;
				break;
			}
			case 9:
			{
				objNewCell.innerHTML = dt1;
				break;
			}
			}
		}
	}
	catch(ex)
	{
		infRetMsg.innerText = ("Err:������־���ʧ��");
		infRetMsg.innerHTML =  "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
	}
}

function CZtc_Sale()
{
	try
	{
		var datetime = GetCurrentTime();
		
		var sts,msg ,sno ;		

		var frm = frmZtcSale; 
		//δ������֮ǰ�������ٴε���������δ�������ɶ�η���
		frm.btn_event_sale.disabled  = true;

		//��ʼ������
		var ZTCLib = objZTCLib;
		ZTCLib.Clear();			
		//��д����
		ZTCLib.SetPara("ServiceCode",frm.ServiceCode.value);
		ZTCLib.SetPara("QQuin",frm.QQuin.value);
		ZTCLib.SetPara("BuyCount",frm.BuyCount.value);
		ZTCLib.SetPara("comm1",frm.comm1.value);
		ZTCLib.SetPara("comm2",frm.comm2.value);	

		//var url= ZTCLib.GetUrl();
		//alert(url);
		//�ύ�����������ͨѶ�ɹ����򷵻���Ϊ0.��ͨ���������صı��Ĳ鿴���
		var retcd= ZTCLib.SendAndRecv();	
		
		//CftMchLib.ShowMsg("ֱͨ������","\r\n����ֵ��"+retcd+"��\r\n"+url);
		
		if(retcd == 0)	
		{
			//CftMchLib.ShowMsg("ֱͨ������",ZTCLib.GetResult());
			var xml =new CXml(ZTCLib.GetResult());

			 sts = ( xml.GetValue("status"));
			 msg = ( xml.GetValue("msg"));
			 sno = ( xml.GetValue("serialno"));	 
			 
		}
		else
		{
			sts = "1";
			msg = "ͨѶ�쳣";
			sno = "";	 
		}
		var datetime1 = GetCurrentTime();
		
		//��¼��������־
		CZtc_RtInsertToDB(datetime,frm.QQuin.value,frm.ServiceCode.value,frm.BuyCount.value,
			frm.comm1.value,frm.comm1.value,sno,sts,msg,datetime1);
		
		//����ҳ����ʱ������־���
		CZtc_InsertIoTable(datetime,frm.QQuin.value,frm.ServiceCode.value,frm.BuyCount.value,
			frm.comm1.value,frm.comm1.value,sno,sts,msg,datetime1);
		//��ʾ������Ϣ
			infRetMsg.innerText = ("OK��������ϡ�");
			
		frm.btn_event_sale.disabled  = false;
	}
	catch(ex)
	{
		infRetMsg.innerText = ("Err:���������쳣");
		infRetMsg.innerHTML =  "Err:" + ex.description+"<br />"+ ex.fileName + "<br />" + ex.lineNumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
	};	
	
	frm.btn_event_sale.disabled  = false;
	
}
