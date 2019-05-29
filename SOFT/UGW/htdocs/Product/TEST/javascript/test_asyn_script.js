var objAsyncall;
var button;

var foot;

try
{	
	objAsyncall= new ActiveXObject("ASYNCALL.IECaller");
	objAsyncall1= new ActiveXObject("ASYNCALL.IESync");
	
	
	objAsyncall.JustDo(document);
	
	button = document.getElementById("form_action");
	
	foot = document.getElementById("logo");
	
	button.BTN_Test.onclick = Test;
}
catch(ex)
{
	var msg=  "Err:" + ex.description+"<br />"+ ex.filename + "<br />" + ex.linenumber +"<br />" + ex.message +"<br />" + ex.name + "<br />" + ex.number;
	
	alert(msg);
};


function Test()
{
	//objAsyncall.JustDo(document);
	//objAsyncall.RunScript("Test1","Test11111111111111111111111(((((((((((!!!!!!!!");
	
	//objAsyncall.DoAsynWork(document);
	//alert(1);
	objAsyncall1.CallBack = Test1;
	objAsyncall1.Do(document,"1111111111111111111111",button.second.value);
	
	//objAsyncall.RunScript("Test1","(((((((((((!!!!!!!!");
}

function Test1(aa,jj)
{
	//alert(aa);
	
	var str = "参数一：【" + aa + "】\r\n" + "参数二：【" + jj + "】\r\n" ;
	foot.innerText = str;
}