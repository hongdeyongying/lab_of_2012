// 全局的正则表达式验证
var global_ele_name_format = {};

global_ele_name_format["email"] = {};

global_ele_name_format["email"]["regex"] = /^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.?$/i;
global_ele_name_format["email"]["tips"] = "用户名：请填写一个有效的EMAIL，如gaoyong@my-soft.net.cn";

global_ele_name_format["vcd"] = {};
global_ele_name_format["vcd"]["regex"] = /^[0-9A-Z]{4,4}$/i;
global_ele_name_format["vcd"]["tips"] = "验证码：请输入正确的验证码"

global_ele_name_format["pwd"] = {};
global_ele_name_format["pwd"]["regex"] = /^[0-9a-zA-Z!#\$%&'\*\+\-\/=\?\^_`{\|}~]{4,16}$/i;
global_ele_name_format["pwd"]["tips"] = "密码：只可以是这些字符组成：0-9a-zA-Z!#\$%&'*+-/=?^_`{|}~";


global_ele_name_format["npwd"] = {};
global_ele_name_format["npwd"]["regex"] = /^[0-9a-zA-Z!#\$%&'\*\+\-\/=\?\^_`{\|}~]{4,16}$/i;
global_ele_name_format["npwd"]["tips"] = "新密码：只可以是这些字符组成：0-9a-zA-Z!#\$%&'*+-/=?^_`{|}~";

global_ele_name_format["display_name"] = {};
global_ele_name_format["display_name"]["regex"] = /^[a-zA-Z0-9\u4e00-\u9faf]{2,64}$/i;
global_ele_name_format["display_name"]["tips"] = "显示名：只能是汉字、字母与数字。且长度大约2小于64";



global_ele_name_format["addr"] = {};
global_ele_name_format["addr"]["regex"] = /^[a-zA-Z0-9, \u4e00-\u9faf]{4,125}$/i;
global_ele_name_format["addr"]["tips"] = "地址：只能是汉字、字母与数字。且长度大约4小于125";


global_ele_name_format["plate"] = {};
global_ele_name_format["plate"]["regex"] = /^[a-zA-Z0-9, \u4e00-\u9faf]{0,4}[A-Z]{0,1}[A-Z0-9]{0,5}$/i;
global_ele_name_format["plate"]["tips"] = "车牌号：如 粤B123AB";



global_ele_name_format["desc"] = {};
global_ele_name_format["desc"]["regex"] = /^[a-zA-Z0-9, \u4e00-\u9faf]{4,125}$/i;
global_ele_name_format["desc"]["tips"] = "自我介绍：显示名：只能是汉字、字母与数字。且长度大约4小于125";


global_ele_name_format["mobile"] = {};
global_ele_name_format["mobile"]["regex"] = /^[0-9]{11,11}$/i;
global_ele_name_format["mobile"]["tips"] = "手机：是11位的阿拉伯数字,如18603018921";


global_ele_name_format["qq"] = {};
global_ele_name_format["qq"]["regex"] = /^[0-9]{5,10}$/i;
global_ele_name_format["qq"]["tips"] = "QQ：是5到11位的阿拉伯数字,如7457222";


global_ele_name_format["telecode"] = {};
global_ele_name_format["telecode"]["regex"] = /^[0-9]{3,4}-[0-9]{7,8}$/i;
global_ele_name_format["telecode"]["tips"] = "固定电话：由区号和本地号码组成，如0755-86013381";


global_ele_name_format["protocol"] = {};
global_ele_name_format["protocol"]["regex"] = /^[0-9]{3,4}-[0-9]{7,8}$/i;
global_ele_name_format["protocol"]["tips"] = "固定电话：由区号和本地号码组成，如0755-86013381";



global_ele_name_format["imei"] = {};
global_ele_name_format["imei"]["regex"] = /^[0-9]{15,15}$/i;
global_ele_name_format["imei"]["tips"] = "IMEI:一个15位的数字";


global_ele_name_format["type"] = {};
global_ele_name_format["type"]["regex"] = /^[0-9]{1,3}$/i;
global_ele_name_format["type"]["tips"] = "型号:一个数字";


global_ele_name_format["iconid"] = {};
global_ele_name_format["iconid"]["regex"] = /^[0-9]{1,3}$/i;
global_ele_name_format["iconid"]["tips"] = "图标:一个数字";

function CheckRegex(n,v)
{
	if ((n in global_ele_name_format) && ("regex" in global_ele_name_format[n]))
	{		
		//alert(n + ":" +v);
		return global_ele_name_format[n]["regex"].test( v ) ;
	}
	return true;
}

function CheckRegexByForm(jq_frm,jq_tips)
{
	var result = true;
	var fields = jq_frm.serializeArray();
	
	jQuery.each(fields, function(i, field){
    	if(!CheckRegex(field.name,field.value))
		{			
			jq_tips.html(global_ele_name_format[field.name]["tips"]);
			result = false;
			return result; 	  	
		}
		
    });
	
	if (result)
		jq_tips.html("<span class=\"ui-icon ui-icon-circle-check\" style=\"float: left; margin: 0 7px 50px 0;\"></span>");
	
	return result;
}

