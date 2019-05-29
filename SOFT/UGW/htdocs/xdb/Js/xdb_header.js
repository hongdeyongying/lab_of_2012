function GetQueryString(name)
{
	 var reg = new RegExp("(^|&)"+ name +"=([^&]*)(&|$)");
	 var r = window.location.search.substr(1).match(reg);
	 if(r!=null)return  unescape(r[2]); return "";
}

function RedirIndexHtml()
{
	//alert(window.location.pathname);
	if(window.location.pathname.indexOf("index.html")>=0)
		return;
	
	window.location = "/xdb/index.html";
}
function RedirIndexHtml2()
{
	//alert(window.location.pathname);
	if(window.location.pathname.indexOf("index.html")>=0)
	{
		$("#div_content").html("点击<button onclick=\"slideout.toggle();\">这里</button>开始活动达人之旅，点左上角LOGO也可以哦！");
	}
	else
		return;
	
}

	function checkLogin()
	{
		try
		{		
			var xdh = (GetQueryString("id"));
			var wxh	= GetQueryString("vc");
						
			var xhdobj = document.getElementById('xdh');
			
			
			if((xdh == "") || (wxh == "") )
			{
				xdh = (g_CCookie.GetCookie("user_id"));	
				wxh = g_CCookie.GetCookie("openid");	
			}
			else
			{
				g_CCookie.SetCookie("user_id",xdh,"","/","","");                            
                g_CCookie.SetCookie("openid",wxh,"","/","","");
			}
			
			if((xdh == "") || (wxh == "") || (xdh <1) ) 
			{
				// window.location = "/xdb/index.html";
				return;
			}
			
			
			
			//document.getElementById("content").src="/cgi/ugw?tid=mybpml&method=task_grade_form";
			
			//*
			$.ajax({
			   url:"/cgi/ugw?tid=mysql&method=xdb_uinfo&openid="+wxh,
			   dataType:"xml",
			   type: "GET",
			   data:$("#frm_reg").serializeArray(),
			   contentType:"application/x-www-form-urlencoded; charset=UTF-8",
			   success:function (xmlRes){
				   if("1" == $("record_num",xmlRes).text() )
				   {
						$("#xdh").text($("f_user_name",xmlRes).text()+",您是第"+$("f_user_id",xmlRes).text()+"号行动达人");
					   	RedirIndexHtml2();
				   }
				   else
				   {
					   RedirIndexHtml();
				   }
			   },
			   error:function (xmlRes,errmsg,expobj){				   
					   RedirIndexHtml();
			   }
			});//*/
			
		}
		catch(exp)
		{
			alert(exp.description);
		};
	}