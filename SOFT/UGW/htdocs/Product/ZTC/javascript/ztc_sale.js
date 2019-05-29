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

/*取当前时间*/
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
		case "QQACCT_SAVE" : //则BuyCount表示个数，取值范围[1, 1000]
			tips_buycount.innerText = "* Q币的个数，取值范围[1,1000]" ;
			break;
		case "-QQPOINT":
			tips_buycount.innerText = "* Q点的个数，必须是10的整数倍，取值范围是[10, 10000]" ;
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
			tips_buycount.innerText = "* 表示月数，取值范围[1, 24]" ;
			break;
		case "QQKDC":
			tips_buycount.innerText = "* 表示点数，必须是100的整数倍，取值范围是[100, 100000]" ;
			tips_comm1.innerText = "* 玩家建立角色的大区，目前1为电信区，2为网通区，3为电信二区" ;
			break;
		case "-DNFDQ":
			tips_buycount.innerText = "* 表示点数，必须是100的整数倍，取值范围是[100, 100000]" ;
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
			infRetMsg.innerText = ("Err:打开数据库失败");
			return ;
		}
			
		retcd = objZTCLib.AddLog(dt,au,p,c,cm1,cm2,bn,st,msg,dt1);
		
		if(retcd != 0) 
		{
			infRetMsg.innerText = ("Err:插入数据库失败");
			//alert(objZTCLib.GetLastError());
		}
		retcd = objZTCLib.CloseLog();
		if(retcd != 0) 
		{
			infRetMsg.innerText = ("Err:关闭数据库失败");
		}
	
}

function CZtc_InsertIoTable(dt,au,p,c,cm1,cm2,bn,st,msg,dt1)
{
	try
	{
		var tbody = tblZtcSaleLog;
		var objTempRow = tbody.rows[0];        //取得模板行
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
		infRetMsg.innerText = ("Err:插入日志表格失败");
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
		//未处理完之前不允许再次点击，避免多次触发，造成多次发货
		frm.btn_event_sale.disabled  = true;

		//初始化参数
		var ZTCLib = objZTCLib;
		ZTCLib.Clear();			
		//填写参数
		ZTCLib.SetPara("ServiceCode",frm.ServiceCode.value);
		ZTCLib.SetPara("QQuin",frm.QQuin.value);
		ZTCLib.SetPara("BuyCount",frm.BuyCount.value);
		ZTCLib.SetPara("comm1",frm.comm1.value);
		ZTCLib.SetPara("comm2",frm.comm2.value);	

		//var url= ZTCLib.GetUrl();
		//alert(url);
		//提交请求，如果调用通讯成功，则返回码为0.可通过分析返回的报文查看结果
		var retcd= ZTCLib.SendAndRecv();	
		
		//CftMchLib.ShowMsg("直通车购买","\r\n返回值【"+retcd+"】\r\n"+url);
		
		if(retcd == 0)	
		{
			//CftMchLib.ShowMsg("直通车购买",ZTCLib.GetResult());
			var xml =new CXml(ZTCLib.GetResult());

			 sts = ( xml.GetValue("status"));
			 msg = ( xml.GetValue("msg"));
			 sno = ( xml.GetValue("serialno"));	 
			 
		}
		else
		{
			sts = "1";
			msg = "通讯异常";
			sno = "";	 
		}
		var datetime1 = GetCurrentTime();
		
		//记录到销售日志
		CZtc_RtInsertToDB(datetime,frm.QQuin.value,frm.ServiceCode.value,frm.BuyCount.value,
			frm.comm1.value,frm.comm1.value,sno,sts,msg,datetime1);
		
		//更新页面临时销售日志表格
		CZtc_InsertIoTable(datetime,frm.QQuin.value,frm.ServiceCode.value,frm.BuyCount.value,
			frm.comm1.value,frm.comm1.value,sno,sts,msg,datetime1);
		//显示返回信息
			infRetMsg.innerText = ("OK：调用完毕。");
			
		frm.btn_event_sale.disabled  = false;
	}
	catch(ex)
	{
		infRetMsg.innerText = ("Err:销售遇到异常");
		infRetMsg.innerHTML =  "Err:" + ex.description+"<br />"+ ex.fileName + "<br />" + ex.lineNumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
	};	
	
	frm.btn_event_sale.disabled  = false;
	
}
