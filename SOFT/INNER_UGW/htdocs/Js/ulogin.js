var xmlUinfo ; 

var ulogin_html ="";

ulogin_html += "	<div id=\"dlg_login\" title=\"用户登录\">";
ulogin_html += "		<form action=\"/cgi/ugw\" method=\"post\"  id=\"frm_login\" target=\"_self\" >";
ulogin_html += "			<input type=\"hidden\" name=\"tid\" value=\"mysql\" />";
ulogin_html += "			<input type=\"hidden\" name=\"method\" value=\"ulog\" />";
ulogin_html += "		<table>";
ulogin_html += "			<tr>";
ulogin_html += "				<td class=\"label_login\">用户名</td>";
ulogin_html += "				<td class=\"value\"><input name=\"email\" type=\"text\" class=\"text ui-widget-content ui-corner-all email\"/></td>";
ulogin_html += "			</tr>";
ulogin_html += "			<tr>				";
ulogin_html += "				<td class=\"label_login\">密码</td>";
ulogin_html += "				<td class=\"value\"><input name=\"pwd\" type=\"password\" class=\"text ui-widget-content ui-corner-all pwd\"/></td>";
ulogin_html += "			</tr>";
ulogin_html += "			<tr>";
ulogin_html += "				<td class=\"label_login\">验证码</td>";
ulogin_html += "				<td class=\"value\"><input name=\"vcd\" type=\"text\" class=\"text ui-widget-content ui-corner-all vcd\"/>";
ulogin_html += "				<img id=\"vcdimg\" class=\"vcdimg\" src=\"/cgi/ugw?tid=vcdimg&rnd=0\"  onclick=\"javacript:changevcdimg(this);\" title=\"双击更换\" />";
ulogin_html += "				</td>";
ulogin_html += "			</tr>";
ulogin_html += "			<tr><td></td><td id=\"login_alert\" class=\"validateTips_login\"></td></tr>	";
ulogin_html += "		</table>";
ulogin_html += "		</form>";
ulogin_html += "	</div>";


$("#content").append(ulogin_html);

$( "#dlg_login" ).dialog({
	dialogClass: "no-close",
	autoOpen: false,
	height: 300,
	width: 390,
	modal: true,
	buttons: {
		"注册":function(){
			location.href="/reg.html";
		},
		"登录": function() {
			var bValid = true;
			bValid = CheckRegexByForm($( "#frm_login" ),$("#login_alert"));
			
			if ( bValid ) {
				$("#login_alert").html("");
				SubmitLoginForm();
			}
		},
	}
});

function changevcdimg(obj)
{
	obj.src = "/cgi/ugw?tid=vcdimg&rnd="+Math.random();
}

function Logout()
{
	//清除cookie
	g_CCookie.SetCookie("uid","");
	$("#welcome").html("");
	$( "#dlg_login" ).dialog("open");
	
}

function SubmitLoginForm() 
{
	//alert("1");
	$.ajax({
		   url:$("#frm_login").attr("action"),
		   dataType:"xml",
		   type: $("#frm_login").attr("method"),
		   data:$("#frm_login").serializeArray(),
		   success:function (xmlRes){
			   if(("0" == $("retcode",xmlRes).text() ) && ("" !=$("fid",xmlRes).text() ))
			   {
				   FillDataBase(xmlRes);
				    $( "#dlg_login" ).dialog("close");
			   }
			   else
			   {
				   if ("0" == $("retcode",xmlRes).text())
				   		$("#login_alert").html("密码错误,如果忘记密码，可凭借EMAIL找回");
				   else
					   $("#login_alert").html(($("retmsg",xmlRes).text()));
			   }
		   }
	});
	
	return false;
}
$.ajax({
		   url:"/cgi/ugw",
		   dataType:"xml",
		   type: "POST",
		   data:"tid=mysql&method=udisp",
		   success:function (xmlRes){
			   if(("0" == $("retcode",xmlRes).text() ) && ("" !=$("fid",xmlRes).text() ))
			   {
				   FillDataBase(xmlRes);
				    $( "#dlg_login" ).dialog("close");
			   }
			   else
			   {
				   $( "#dlg_login" ).dialog("open");
			   }
		   }
	});

/*可以定义自己的函数，用到用户信息的地方，函数原型 FillData(xmlUinfo)*/
function FillDataBase(xmlRes)
{
	if(("0" == $("retcode",xmlRes).text() ) && ("" !=$("fid",xmlRes).text() ))
   {
	  // xmlUinfo = xmlRes;
	   
	   $("#welcome").html("欢迎您，<a href='/profile.html' class='green'>"+ $("fdisplay_name",xmlRes).text() + "</a>. 使用完毕后，请<a title='点击退出' class='green' onclick='javascript:Logout();'>退出系统</a>" );
	  
	  try{FillData(xmlRes);}catch(e){};
   }
}