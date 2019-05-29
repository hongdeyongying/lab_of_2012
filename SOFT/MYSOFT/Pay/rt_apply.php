<html>
	<head>
	<TITLE>My-Soft,商户实时申请入口</TITLE>				
	<meta name="description" content="到My-Soft定制软件，恰如您所需!" />
	<meta name="keywords" content="软件，原创软件，定制软件，发布需求，发布软件，开发者，消费者，管理员，直通车" />
	<link rel="stylesheet" href="/Style/layout.css" type="text/css" media="all" />
	<link rel="stylesheet" href="/Style/register.css" type="text/css" media="all" />		
	<style type="text/css">
		input{
			width:200px;
		}
		label{
			width:100px;
		}				
		textarea{
			width:400px;
			height:100px;
		}
	</style>
	<script language="javascript" src="/Script/md5.js"></script>
	<script language="javascript" src="/Script/CGbCode.js"></script>
	<script language="javascript">
		function SubmitForm()
		{
			with(document.ReqForm)
			{
				req_src.value = "" ;		
				if(address.value!="") req_src.value +="address=" + address.value;
				if(email.value!="") req_src.value +="&email=" + email.value;
				if(mobile.value!="") req_src.value +="&mobile=" + mobile.value;
				if(name.value!="") req_src.value +="&name=" + name.value;
				if(owner.value!="") req_src.value +="&owner=" + owner.value;
				if(postcode.value!="") req_src.value +="&postcode=" + postcode.value;
				if(qq.value!="") req_src.value +="&qq=" + qq.value;
				if(spid.value!="") req_src.value +="&spid=" + spid.value;
				if(telno.value!="") req_src.value +="&telno=" + telno.value;
				if(url.value!="") req_src.value +="&url=" + url.value;
				if(ver.value!="") req_src.value +="&ver=" + ver.value;
		
				req_src.value +="&key=" + req_key.value;
		        
				//alert(req_src.value);
				//sign.value =  md5(req_src.value);
				sign.value =  hex_md5(g_CGbCode.GetGbByteStream(req_src.value));
			}
			
			return true;
		}
	</script>
	</head>


<body>
<pre>
	商户号信息:
		1900000666/19a1cae5dfd0d2296b0fd80ab65b975d
</pre>		

<form name="ReqForm" action="http://union.tenpay.com/cgi-bin/mch/mch_juniorreginf.cgi" 
	target="_blank" onSubmit="return SubmitForm();">
	<table>
		<tr>
		  <td align="right">版本号:</td>
		  <td align="left"><input type="text" name="ver" value="1"></td></tr>
		<tr>
		  <td align="right">平台商商户号:</td>
		  <td align="left"><input type="text" name="spid" id="spid"  value="1900000666"></td></tr>
		
		<tr>
	  <td align="right">key:</td>
	  <td align="left"><input type="text" name="req_key" id="req_key"  value="19a1cae5dfd0d2296b0fd80ab65b975d"></td></tr>
	    
		<tr><td align="right"> url:</td>
		<td align="left"><input type="text" name="url"  id="url" value="http://www.my-soft.net.cn"></td></tr>
		<tr><td align="right">姓名:</td>
		<td align="left"><input type="text" name="name" id="name" value="高勇"></td></tr>
		<tr><td align="right"> 地址 :</td>
		<td align="left"><input type="text" name="address"  id="address" value="深圳南山科技园"></td></tr>
		<tr><td align="right"> 邮编 :</td>
		<td align="left"><input type="text" name="postcode" id="postcode" value="518000"></td></tr>
		<tr><td align="right"> 所有人 :</td>
		<td align="left"><input type="text" name="owner" id="owner" value="高勇"></td></tr>
		<tr><td align="right"> 电话号码 :</td>
		<td align="left"><input type="text" name="telno" id="telno" value="0755-86086869"></td></tr>
		<tr><td align="right"> 手机号码 :</td>
		<td align="left"><input type="text" name="mobile" id="mobile" value="13510414906"></td></tr>
		<tr><td align="right"> qq :</td>
		<td align="left"><input type="text" name="qq" id="qq" value="123456"></td></tr>
		<tr><td align="right"> email :</td>
		<td align="left"><input type="text" name="email"  id="email" value="gaussgao@tencent.com"></td></tr>
		<tr><td align="right"> 请求字串 :</td><td align="left"><input type="text" name="req_src" value=""></td></tr>
		<tr><td align="right"> 签名 :</td><td align="left"><input type="text" name="sign" value=""></td></tr>
		<tr><td align="right"></td><td align="left"><input type="submit"  value="提交"></td></tr>
	</table>
</form>
</body>
<html>