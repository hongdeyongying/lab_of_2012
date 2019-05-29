var objMsBpml,objMsBpmlAsyn;
var frmSearch;	
var tblResult;

var divInfo;

try
{
	objMsBpml = new ActiveXObject("MSBPML.myFlow");
	objMsBpmlAsyn = new ActiveXObject("MSBPML.AsynFlow");
	frmSearch = document.getElementById("ImSearch");	
	divInfo = document.getElementById("info");	
	tblResult = document.getElementById("Results");	
	frmSearch.btn_search.onclick = CViewFlight_Search;
	frmSearch.btn_search2.onclick = CViewFlight_Search2;
}
catch(ex)
{
	divInfo.innerHTML = "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
};
function CViewFlight_GenReqData(form)
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
//	alert(reqdat);
	return reqdat;
}
function CViewFlight_Search2()
{
//alert(1);
document.getElementById("debuginfo").value="";	
		CViewFlight_ClearTable();
	var file,inpara,result;
		
	file = frmSearch.bpml_file.value;
	inpara = CViewFlight_GenReqData(frmSearch);
	//FillResult(11,22);
	objMsBpmlAsyn.CallBack = FillResult;
//alert(2);
	objMsBpmlAsyn.Execute(file,inpara);
//alert(3);
}
function FillResult(cnt ,sts)
{
	if(sts != 0)
	{
		alert("查询失败");
		return;
	}
	var xml = new CXml(cnt);			
//alert(cnt);	
document.getElementById("debuginfo").value=cnt;		
	var rcds =xml.GetNodes("record");
	for(i =0;i <rcds.length; i++)
	{
		CViewFlight_InsertIoTable(xml.GetChildValue(rcds[i],"airways") +"/"+ xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"takeoff_location") +"<br>"+ xml.GetChildValue(rcds[i],"land_location"),
			xml.GetChildValue(rcds[i],"takeoff_datetime") +"<br>"+ xml.GetChildValue(rcds[i],"land_datetime"),
			xml.GetChildValue(rcds[i],"plane_type"),
			xml.GetChildValue(rcds[i],"fee_airport") +"/"+ xml.GetChildValue(rcds[i],"fee_fuel"),
			xml.GetChildValue(rcds[i],"price_1"),
			xml.GetChildValue(rcds[i],"berth_1"),
			xml.GetValue("channel_id"),
			xml.GetChildValue(rcds[i],"agent_id")
			);
		/*CViewFlight_InsertIoTable(
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
			);*/
	}
	
	if(rcds.length == 0)
		alert("无符合条件的航班");
	
}
function CViewFlight_Search()
{
		CViewFlight_ClearTable();
	try
	{
		var file,inpara,result;
		
		file = frmSearch.bpml_file.value;
		inpara = CViewFlight_GenReqData(frmSearch);
		
		result = objMsBpml.Execute(file,inpara);
		
		//alert(result);
		if(result != "NULL" )
		{
			var xml = new CXml(result);
			
			//alert(xml.GetNodes("record").length);
			//alert(xml.GetValue("record_num") );
			//alert(xml.GetValue("channel_id") );
			
			var rcds =xml.GetNodes("record");
			for(i =0;i <rcds.length; i++)
			{
				CViewFlight_InsertIoTable(xml.GetChildValue(rcds[i],"airways") +"/"+ xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"takeoff_location") +"<br>"+ xml.GetChildValue(rcds[i],"land_location"),
					xml.GetChildValue(rcds[i],"takeoff_datetime") +"<br>"+ xml.GetChildValue(rcds[i],"land_datetime"),
					xml.GetChildValue(rcds[i],"plane_type"),
					xml.GetChildValue(rcds[i],"fee_airport") +"/"+ xml.GetChildValue(rcds[i],"fee_fuel"),
					xml.GetChildValue(rcds[i],"price_1"),
					xml.GetChildValue(rcds[i],"berth_1"),
					xml.GetValue("channel_id"),
					xml.GetValue("agent_id")
					);
				/*CViewFlight_InsertIoTable(
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					xml.GetChildValue(rcds[i],"airways") + xml.GetChildValue(rcds[i],"airline_id"),
					);*/
			}
		}
	}
	catch(ex)
	{
		divInfo.innerHTML = "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
	};
}
function CViewFlight_ClearTable()
{
	var tbody = tblResult;
	
	for (var i=tbody.rows.length-1;i>0;i--)
		tbody.deleteRow( i );
}
function CViewFlight_InsertIoTable(airway,airport,datetime,plane,fee,price,berch,chnid,merch)
{
	try
	{
		var tbody = tblResult;
		var objTempRow = tbody.rows[0];        //取得模板行
		var objNewRow = tbody.insertRow( tbody.rows.length );
		//var objNewRow = tbody.insertRow( 1 );
		objNewRow.id = tbody.rows.length-1; 

		for ( var i=0 ; i<objTempRow.cells.length ; i++ ) 
		{ 
			var objNewCell = objNewRow.insertCell( i ); 
			switch(i)
			{
			case 0:
			{
				objNewCell.innerHTML = airway;
				break;
			}
				
			case 1:
			{
				objNewCell.innerHTML = airport;
				break;
			}
			case 2:
			{
				objNewCell.innerHTML = datetime;
				break;
			}
			case 3:
			{
				objNewCell.innerHTML = plane;
				break;
			}
			case 4:
			{
				objNewCell.innerHTML = fee;
				break;
			}
			case 5:
			{
				objNewCell.innerHTML = price;
				break;
			}
			case 6:
			{
				objNewCell.innerHTML =berch
				break;
			}
			case 7:
			{
				objNewCell.innerHTML = chnid;
				break;
			}
			case 8:
			{
				objNewCell.innerHTML = merch;
				break;
			}
			}
		}
	}
	catch(ex)
	{
		divInfo.innerHTML = "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
		//divInfo.innerText = ("Err:插入日志表格失败");
		//divInfo.innerHTML =  "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
	}
}
