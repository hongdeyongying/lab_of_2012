<html>
	<head>
		<TITLE>My-Soft,ԭ�����������������������������������</TITLE>
		<meta http-equiv="pragma" content="no-cache" />
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
		<meta name="description" content="��My-Soft�����������������������������!" />
		<meta name="keywords" content="My-Soft,����,ԭ������,������������,��������������������������󣬷��������������ߣ������ߣ�����Ա��ֱͨ��" />
		<link rel="stylesheet" href="/Style/layout.css" type="text/css" media="all" />
		<style type="text/css">
		input{
			width:400px;
		}
		label{
			width:100px;
		}				
		textarea{
			width:100%;
			height:100px;
			}
	</style>
	</head>
	<body >
<div class="Body" >		
<!--	-->
	<div class="Header">
		<div class="Logo" >
			<a href="/"><div id="LOGO"><h1>My-Soft</h1><h3>.net.cn</h3></div></a>
		</div>
		<div class="Nav">		
			<uL><li class="NavSplit"> </li>				
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"
					onclick="javascript:document.location.href='/index.php';">
					��ҳ</li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>	
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>	
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>					
			</ul>
		</div>
		<div class="Nav">		
			<uL><li class="NavSplit"> </li>				
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"></li>			<li class="NavSplit"> </li>					
				<li class="Cur_SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='Cur_SeleBtn';"
					
					>����֧��</li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"
					onclick="javascript:window.external.AddFavorite('http://www.my-soft.net.cn','My-Soft,����ǡ��������')"
					>�ղر�վ</li>					<li class="NavSplit"> </li>
			</ul>
		</div>
	</div>

	<div class="Welcome" >
		
		<p>&nbsp;&nbsp;&nbsp;&nbsp;����֧����˾Ϊ���������ṩ���ʽ���ת�ı�����������һ������֧����˾������֧��ȫ����������е����������󷽱������Ӫ��
			ƽ̨���ر�������ṩ�˱����У������ȴ�ͳ���ڻ�����ƽ�׽��˵ķ��񣬸��ӿ��ţ������������ܹ����ٸ�����Ը���������Ӧ�ó�����֧���������ŵ�����֧
			��ƽ̨����һ���ḻ�ճ������е�֧���ֶΣ�������֧�������㣡
		</P>
		
		<p>&nbsp;&nbsp;&nbsp;&nbsp;�������ʹ����Ѷ�Ƹ�ͨ�����ṩ�ĸ��ֹ��ܵ�ʵ��ʾ���������������������Ӧ�ó�������Ҫ��
		</P>		
	</div>
	<div class="Content">
<?php

function genNameVal($n,$v)
	{
		static $g_first = 1;
		$tmp_res = "";
		//echo "now:".$g_first."<br>";
		if(isset($n)&&isset($v)&&($n!="")&&($v!=""))
		{
			if($g_first == 1)
			{	
				$tmp_res = $n ."=".$v;
				$g_first = 0;
			}
			else
			{
				$tmp_res = "&".$n ."=".$v;
			}
		}
		return $tmp_res;
	}
	
	import_request_variables("gp","frm_");
	import_request_variables("c","ck_");	
	
	if($frm_ver != 4)
		Exit("��֧�ֵİ汾��:".$frm_ver);
	
		$strVersion = $frm_ver;
	 /*�̻����ɵĶ�����(���10λ)*/	
	  $strSpBillNo= $frm_billno;
	  /*ԭʼ���׵���*/
		$strTransactionId = $frm_tid;
		/*�����˿�Ϊ3*/
	  $strCmdNo   = "3";
	  /*�̻���*/	
	  $strSaler   = $frm_spid;				
		/*�ܽ��, ��Ϊ��λ*/
		$strTotalFee = $frm_fee;
		/*��������: 1 �C RMB(�����) 2 - USD(��Ԫ) 3 - HKD(�۱�)*/
		$strFeeType  = "1";
		/*�Ƹ�ͨ�ص�ҳ���ַ, �Ƽ�ʹ��ip��ַ�ķ�ʽ(�255���ַ�)*/
		$strRetUrl  = "http://www.my-soft.net.cn/Pay/pay_split_respond.php";
		//ȡǩ������key	
		  if($strSaler == "1200062401")      
		    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*�̻���Կ,����ʱ��Ϊ�̻���,��ʽ���ߺ����޸�*/
			else if($strSaler == "2000000000")      
				$strSpkey = "abc12345";
			else if($strSaler == "2000000501")
				$strSpkey = "123456";
			else if($strSaler == "2000001240")
				$strSpkey = "49a3f0d9ac8065342f7a9ca1d208baf7";
			else if($strSaler == "2000001204")
				$strSpkey = "06040350901b89328c085b727a26ee69";
			else if($strSaler == "2100000020")
				$strSpkey = "1234567890123456";
			else if($strSaler == "2000000002")
				$strSpkey = "4554d100495342a6d8854c88ff2d6339";
			else if($strSaler == "1202952101")
				$strSpkey = "8fef4ff29cab34775c2c4c62374b5297";
			else if($strSaler == "1202119401")
				$strSpkey = "comd4f16b4ec3d7aaf082bab5194cfcn";
			else
		  	Exit("δ���õ��̻���:".$strSpid);
		/*����MD5ǩ��*/
			$strSignText = 
						genNameVal("bargainor_id",$strSaler).
						genNameVal("bus_args",$frm_bus_args).
						genNameVal("bus_desc",$frm_bus_desc).
						genNameVal("bus_type",$frm_bus_type).
						genNameVal("cmdno",$strCmdNo).
						genNameVal("fee_type",$strFeeType).
						genNameVal("return_url",$strRetUrl).
						genNameVal("sp_billno",$strSpBillNo).
						genNameVal("total_fee",$strTotalFee).
						genNameVal("transaction_id",$strTransactionId).
						genNameVal("version",$strVersion).
						genNameVal("key",$strSpkey)
						;
									
		  $strSign = strtoupper(md5($strSignText));
?>
<form target="_blank" action="https://mch.tenpay.com/cgi-bin/split.cgi">
	<fieldset ><legend>֧����Ϣ</legend>
		<label>ҵ�����</label><input readonly name="cmdno" value="<? echo $strCmdNo; ?>"><br>
		<label>����</label><input readonly name="bargainor_id" value="<? echo $strSaler; ?>"><br>
		<label>�Ƹ�ͨ����</label><input readonly name="transaction_id" value="<? echo $strTransactionId; ?>"><br>
		<label>�̻�����</label><input readonly name="sp_billno" value="<? echo $strSpBillNo; ?>"><br>
		<label>�����ܶ�</label><input readonly name="total_fee" value="<? echo $strTotalFee; ?>"><br>
		<label>����</label><input readonly name="fee_type" value="<? echo $strFeeType; ?>"><br>
		<label>�ص�URL</label><input readonly name="return_url" value="<? echo $strRetUrl ; ?>"><br>
		<label>��  ��</label><input readonly name="version" value="<? echo $strVersion; ?>"><br>
	</fieldset>
	<fieldset ><legend>������Ϣ</legend>
		<label>����</label><input readonly name="bus_type" value="<? echo $frm_bus_type; ?>"><br>
		<label>����</label><input readonly name="bus_args" value="<? echo $frm_bus_args; ?>"><br>
		<label>��Ϣ</label><input readonly name="bus_desc" value="<? echo $frm_bus_desc; ?>"><br>
	</fieldset>
	<fieldset ><legend>ǩ����Ϣ</legend>
		<label>ǩ������</label><textarea readonly > <? echo $strSignText;  ?></textarea>
		<label>ǩ��</label><input readonly name="sign" value="<? echo $strSign; ?>"><br>		
	</fieldset>
		<label></label><input type="submit" value="ȷ��������Ϣ"><br>
		<label></label><input type="button" value="������һ��������д" onclick="javascript:window.history.back();"><br>
</form>
	</div>
		<!-- 
	<div class="Foot">
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved ԭ������ ��Ȩ���� <br />
					������ţ���ICP��08019531��
	</div>	-->

</div><!-- Body -->
</body>
</html>