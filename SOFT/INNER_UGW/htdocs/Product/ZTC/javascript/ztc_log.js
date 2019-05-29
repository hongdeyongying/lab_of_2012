var objZTCSdoLib;
var infRetMsg;
var tblZtcSaleLog;
var frmZtcSaleLog;

try
{
	infRetMsg = document.getElementById("INF_RETMSG");	
	infRetMsg.innerText = ("");
	
	tblZtcSaleLog = document.getElementById("TBL_ZTC_SALE_LOG");	
	
	objZTCSdoLib= new ActiveXObject("MYSOFTSDO.ZTCSaleLog");
	
	frmZtcSaleLog = document.getElementById("FRM_ZTC_LOG");	
	//frmZtcSaleLog.btn_event_salelog.onclick = CZtc_OpenAccess;
	frmZtcSaleLog.btn_event_deleteall.onclick = CZtc_DeleteAll;
	
	var retcd = (objZTCSdoLib.Open(" "));
	
	if( retcd != 0)
	{
		alert("初始化数据库失败！");
	}
	else
	{
		//(objZTCSdoLib.MoveFirst());
		while(objZTCSdoLib.MoveNext() == 0)
		{		
			CZtc_InsertIoTable(objZTCSdoLib.GetFieldValue("FIndex"),
				objZTCSdoLib.GetFieldValue("FRequestTime"),
				objZTCSdoLib.GetFieldValue("FConsignee"),
				objZTCSdoLib.GetFieldValue("FProduct"),
				objZTCSdoLib.GetFieldValue("FCount"),
				objZTCSdoLib.GetFieldValue("FComm1"),
				objZTCSdoLib.GetFieldValue("FComm2"),
				objZTCSdoLib.GetFieldValue("FSNO"),
				objZTCSdoLib.GetFieldValue("FStatus"),
				objZTCSdoLib.GetFieldValue("FMessage"),
				objZTCSdoLib.GetFieldValue("FResponseTime")
				);
		};
	}
		
	
	
}
catch(ex)
{
	infRetMsg.innerHTML =  "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
};
function CZtc_DeleteAll()
{
	objZTCSdoLib.DeleteAll();
	
	window.location.reload();
}
function CZtc_OpenAccess()
{
	var oAccess = new ActiveXObject("Access.Application"); //创建应该对象
	oAccess.Visible = true;
	oAccess.OpenCurrentDatabase ("G:\\My-Soft\\软件\\MS_WS\\db2.mdb");
	
	//objZTCSdoLib.DeleteAll();
}

function CZtc_InsertIoTable(idx,dt,au,p,c,cm1,cm2,bn,st,msg,dt1)
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
			switch(i)
			{
			case 0:
			{
				objNewCell.innerHTML = idx;
				break;
			}
				
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
				objNewCell.innerHTML =cm2;
				break;
			}
			case 7:
			{
				objNewCell.innerHTML = bn;
				break;
			}
			case 8:
			{
				objNewCell.innerHTML = st;
				break;
			}
			case 9:
			{
				objNewCell.innerHTML = msg;
				break;
			}
			case 10:
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
