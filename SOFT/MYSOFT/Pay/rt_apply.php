<html>
	<head>
	<TITLE>My-Soft,�̻�ʵʱ�������</TITLE>				
	<meta name="description" content="��My-Soft���������ǡ��������!" />
	<meta name="keywords" content="�����ԭ�����������������������󣬷�������������ߣ������ߣ�����Ա��ֱͨ��" />
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
	�̻�����Ϣ:
		1900000666/19a1cae5dfd0d2296b0fd80ab65b975d
</pre>		

<form name="ReqForm" action="http://union.tenpay.com/cgi-bin/mch/mch_juniorreginf.cgi" 
	target="_blank" onSubmit="return SubmitForm();">
	<table>
		<tr>
		  <td align="right">�汾��:</td>
		  <td align="left"><input type="text" name="ver" value="1"></td></tr>
		<tr>
		  <td align="right">ƽ̨���̻���:</td>
		  <td align="left"><input type="text" name="spid" id="spid"  value="1900000666"></td></tr>
		
		<tr>
	  <td align="right">key:</td>
	  <td align="left"><input type="text" name="req_key" id="req_key"  value="19a1cae5dfd0d2296b0fd80ab65b975d"></td></tr>
	    
		<tr><td align="right"> url:</td>
		<td align="left"><input type="text" name="url"  id="url" value="http://www.my-soft.net.cn"></td></tr>
		<tr><td align="right">����:</td>
		<td align="left"><input type="text" name="name" id="name" value="����"></td></tr>
		<tr><td align="right"> ��ַ :</td>
		<td align="left"><input type="text" name="address"  id="address" value="������ɽ�Ƽ�԰"></td></tr>
		<tr><td align="right"> �ʱ� :</td>
		<td align="left"><input type="text" name="postcode" id="postcode" value="518000"></td></tr>
		<tr><td align="right"> ������ :</td>
		<td align="left"><input type="text" name="owner" id="owner" value="����"></td></tr>
		<tr><td align="right"> �绰���� :</td>
		<td align="left"><input type="text" name="telno" id="telno" value="0755-86086869"></td></tr>
		<tr><td align="right"> �ֻ����� :</td>
		<td align="left"><input type="text" name="mobile" id="mobile" value="13510414906"></td></tr>
		<tr><td align="right"> qq :</td>
		<td align="left"><input type="text" name="qq" id="qq" value="123456"></td></tr>
		<tr><td align="right"> email :</td>
		<td align="left"><input type="text" name="email"  id="email" value="gaussgao@tencent.com"></td></tr>
		<tr><td align="right"> �����ִ� :</td><td align="left"><input type="text" name="req_src" value=""></td></tr>
		<tr><td align="right"> ǩ�� :</td><td align="left"><input type="text" name="sign" value=""></td></tr>
		<tr><td align="right"></td><td align="left"><input type="submit"  value="�ύ"></td></tr>
	</table>
</form>
</body>
<html>