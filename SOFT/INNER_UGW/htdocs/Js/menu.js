
var menu_item_html =  new Array();
var menu_begin_index = 1;

function menu_on_blur(evt,ui)
{
	dispear_menu();
	
}
function dispear_menu()
{
	for(i=menu_begin_index+1;i<=menu_item_html.length;i++)
	{
		var tagname = "#menu_"+i+"_item";
		
		$(tagname ).css("display","none");
	}
}

function menu_on_hover()
{
	try{
		//$( "#menu_1_item" ).css( "display", "");
		//ui.item.parent().css( "display", "");
		//if($("#"+$(this).attr("id")+"_item").css("display") == "none")
		dispear_menu();
		
		
		var tagname = "#"+$(this).attr("id")+"_item";
		
		$(tagname ).css( "display", "");
		$(tagname ).css( "clear", "both");
	}
	catch(e){alert(e.name  +": " + e.message);
	};
	
}

function menu_on_hout()
{
	try{
		//$( "#menu_1_item" ).css( "display", "");
		//ui.item.parent().css( "display", "");
		//if($("#"+$(this).attr("id")+"_item").css("display") == "none")
		//var tagname = "#"+$(this).attr("id")+"_item";
		//alert(tagname);
		//$(tagname).css("display", "none");
		
		//var tagname = "#"+$(this).attr("id")+"_item";
		//alert(tagname);
		//$(tagname).css("display", "");
		
		//alert("#"+$(this).attr("id")+"_item");
	}
	catch(e){alert(e.name  +": " + e.message);
	};
	
}


try{
menu_item_html[0]   = "<ul id=\"menu_1_item\" class=\"menu_item\">";
menu_item_html[0]   +="  <li><a href=\"#\"><span class=\"ui-icon ui-icon-disk\"></span>Save</a></li>";
menu_item_html[0]   +="  <li><a href=\"#\"><span class=\"ui-icon ui-icon-zoomin\"></span>Zoom In</a></li>";
menu_item_html[0]   +="  <li><a href=\"#\"><span class=\"ui-icon ui-icon-zoomout\"></span>Zoom Out</a></li>";
menu_item_html[0]   +="  <li class=\"ui-state-disabled\"><a href=\"#\"><span class=\"ui-icon ui-icon-print\"></span>Print...</a></li>";
menu_item_html[0]   +="  <li>";
menu_item_html[0]   +="    <a href=\"#\">Playback</a>";
menu_item_html[0]   +="    <ul>";
menu_item_html[0]   +="      <li><a href=\"#\"><span class=\"ui-icon ui-icon-seek-start\"></span>Prev</a></li>";
menu_item_html[0]   +="      <li><a href=\"#\"><span class=\"ui-icon ui-icon-stop\"></span>Stop</a></li>";
menu_item_html[0]   +="      <li><a href=\"#\"><span class=\"ui-icon ui-icon-play\"></span>Play</a></li>";
menu_item_html[0]   +="      <li><a href=\"#\"><span class=\"ui-icon ui-icon-seek-end\"></span>Next</a></li>";
menu_item_html[0]   +="    </ul>";
menu_item_html[0]   +="  </li>";
menu_item_html[0]   +="</ul>";

menu_item_html[1]   = "<ul id=\"menu_2_item\" class=\"menu_item\">";
menu_item_html[1]   +="  <li><a href=\"/profile.html\">基本信息</a></li>";
menu_item_html[1]   +="  <li><a href=\"/profile_passwd.html\">密码修改</a></li>";
menu_item_html[1]   +="</ul>";


menu_item_html[2]   = "<ul id=\"menu_3_item\" class=\"menu_item\">";
menu_item_html[2]   +="  <li><a href=\"/client.html\">设备列表</a></li>";
menu_item_html[2]   +="  <li><a href=\"#\">下级客户</a></li>";
menu_item_html[2]   +="  <li><a href=\"#\">我信任的客户</a></li>";
menu_item_html[2]   +="  <li><a href=\"#\">信任我的客户</a></li>";
menu_item_html[2]   +="</ul>";

menu_item_html[3]   = "<ul id=\"menu_4_item\" class=\"menu_item\">";
menu_item_html[3]   +="  <li><a href=\"#\">当前位置</li>";
menu_item_html[3]   +="  <li><a href=\"#\">历史轨迹</li>";
menu_item_html[3]   +="</ul>";

menu_item_html[4]   = "<ul id=\"menu_5_item\" class=\"menu_item\">";
menu_item_html[4]   +="  <li><a href=\"#\">里程统计</li>";
menu_item_html[4]   +="  <li><a href=\"#\">工时统计</li>";
menu_item_html[4]   +="  <li><a href=\"#\">油耗统计</a></li>";
menu_item_html[4]   +="</ul>";


menu_item_html[5]   = "<ul id=\"menu_6_item\" class=\"menu_item\">";
menu_item_html[5]   +="  <li><a href=\"#\">我的意见</li>";
menu_item_html[5]   +="  <li><a href=\"#\">我关注的需求</li>";
menu_item_html[5]   +="  <li><a href=\"#\">本月将上线的需求</li>";
menu_item_html[5]   +="</ul>";
/**/


$("#menu_item").html(menu_item_html.join(" "));
//alert(menu_item_html.join(" "));

//$("#arr").val(menu_item_html.join(" \r\n "));


//alert(menu_item_html.length);
for(i=menu_begin_index+1;i<=menu_item_html.length;i++)
{
	var tagname = "#menu_"+i+"_item";
	var tagof = "#menu_"+i;
	
	$(tagname ).menu();
	
	$(tagname).position({	my: "left top",	at: "left bottom ",	of: tagof});
	
	$(tagname).on( "menuselect", menu_on_blur );
	
	$(tagname ).css( "display", "none");
	$(tagname ).css( "z-index", "1024");
	
	$(tagof).hover(menu_on_hover,menu_on_hout);
	
	$("#logobar").hover(menu_on_blur);
	$("#langbar").hover(menu_on_blur);
	$("#footbar").hover(menu_on_blur);
	
	$("#content").click(menu_on_blur);
	
	//alert(tagname);
	
	//alert($( "#menu_1_item" ).menu( "option", "id" ));
}
}catch(e)
{
	alert(e.name  +": " + e.message);
};
