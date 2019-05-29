var tips_html ="<div id=\"dlg_tips\" title=\"信息提醒\"></div>";



$("#content").append(tips_html);

$( "#dlg_tips" ).dialog({
	autoOpen: false,
	height: 300,
	width: 400,
	modal: true,
	buttons: {
		"确认":function(){
			$( this ).dialog( "close" );
			
		}
	}
});

function DlgTIps(title,content)
{
	
	$( "#dlg_tips" ).append("<p>"+title+"</p><p>"+content+"</p>");
	
	$( "#dlg_tips" ).dialog("open");
}