<html>
	<head>
		<TITLE>My-Soft,ԭ������������������������������</TITLE>
		<meta http-equiv="pragma" content="no-cache" />
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
		<meta name="description" content="��My-Soft�������������������������!" />
		<meta name="keywords" content="My-Soft,���,ԭ�����,���������,������������������������󣬷�������������ߣ������ߣ�����Ա��ֱͨ��" />
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
					onclick="javascript:window.external.AddFavorite('http://www.my-soft.net.cn','My-Soft,���ǡ��������')"
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
		<pre>
	�̻�����Ϣ:2000000000/abc12345;2000000501/123456;1200062401/;	
		2000001240/49a3f0d9ac8065342f7a9ca1d208baf7;
    2000001204/06040350901b89328c085b727a26ee69;
    2100000020/1234567890123456;
		2000000002/4554d100495342a6d8854c88ff2d6339
		1202952101/8fef4ff29cab34775c2c4c62374b5297 ;
	</pre>
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
	function GenPayQueryPage($spid,$agentid,$keyind,$ver,$key,$tid,$date,$sp_bill)
  {
  	if(isset($spid) && ($spid!=""))
  	  $strSpid    = $spid;
		
		if(isset($agentid)&& ($agentid!=""))
			$strAgentid = $agentid;
			
		if(isset($keyind)&& ($keyind!=""))
			$strKeyIndex = $keyind;
		
		if(isset($ver)&& ($ver!=""))
			$strVersion  = $ver;
					
		if(isset($key)&& ($key!=""))
		{	
			$strSpkey   = $key; 
		}
		else
		{
			$tmp = $strSpid;
			if(($strKeyIndex == 2) && ($strVersion == 3))
			{
				$tmp = $strAgentid;
			}	
			//ȡǩ������key	
		  if($tmp == "1200062401")      
		    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*�̻���Կ,����ʱ��Ϊ�̻���,��ʽ���ߺ����޸�*/
			else if($tmp == "2000000000")      
				$strSpkey = "abc12345";
			else if($tmp == "2000000501")
				$strSpkey = "123456";
			else if($strSpid == "2000001240")
				$strSpkey = "49a3f0d9ac8065342f7a9ca1d208baf7";
			else if($strSpid == "2000001204")
				$strSpkey = "06040350901b89328c085b727a26ee69";
			else if($strSpid == "2100000020")
				$strSpkey = "1234567890123456";
			else if($strSpid == "2000000002")
				$strSpkey = "4554d100495342a6d8854c88ff2d6339";
			else if($strSpid == "1202952101")
				$strSpkey = "8fef4ff29cab34775c2c4c62374b5297";
			else
		  	Exit("δ���õ��̻���:".$strSpid);
		}
		//function GenPayQueryPage($spid,$agentid,$keyind,$ver,$key,$tid,$date,$sp_bill)
  	/*�Ƹ�ͨ������ѯʱΪ"2" */
	  $strCmdNo   = "96";
	  /*�������� (yyyymmdd)*/
	  $strBillDate= $date;
	  /*�̻���*/	
	  $strSaler   = $strSpid;				
	  /*�̻����ɵĶ�����(���10λ)*/	
	  $strSpBillNo= $sp_bill;
	  /*��Ҫ: ���׵���
		  ���׵���(28λ): �̻���(10λ) + ����(8λ) + ��ˮ��(10λ), ���밴�˸�ʽ����, �Ҳ����ظ�
		  ���sp_billno����10λ, ���ȡ���е���ˮ�Ų��ּӵ�transaction_id��(����10λ��0)
		  ���sp_billno����10λ, ����0, �ӵ�transaction_id��*/
		$strTransactionId = $tid;
		/*�Ƹ�ͨ�ص�ҳ���ַ, �Ƽ�ʹ��ip��ַ�ķ�ʽ(�255���ַ�)*/
		$strRetUrl  = "http://www.my-soft.net.cn/Pay/pay_notify_handler.php";
		/*�̻�˽������, ����ص�ҳ��ʱԭ������*/
		$strAttach  = "";	
		
		if(!isset($strVersion) || $strVersion=="" || $strVersion<2)
		{				  
			/*����MD5ǩ��*/
			$strSignText = "cmdno=" . $strCmdNo . "&date=" . $strBillDate . "&bargainor_id=" . $strSaler .
			      "&transaction_id=" . $strTransactionId . "&sp_billno=" . $strSpBillNo .        
			      "&return_url=" . $strRetUrl .
			      "&attach=" . $strAttach . "&key=" . $strSpkey;
		  $strSign = strtoupper(md5($strSignText));
		  
		  /*����֧����*/
		  $strRequest = "cmdno=" . $strCmdNo . "&date=" . $strBillDate . "&bargainor_id=" . $strSaler .        
			  "&transaction_id=" . $strTransactionId . "&sp_billno=" . $strSpBillNo .        
			  "&return_url=" . $strRetUrl .        
			  "&attach=" . $strAttach . "&bank_type=" . $strBankType . "&desc=" . $strDesc .        
			  "&sign=" . $strSign ; 
	  	  	
	  	$res  = "<form target=\"_blank\"  action=\"http://mch.tenpay.com/cgi-bin/cfbi_query_order.cgi\">";
	  	$res .= "<input type=hidden name=\"cmdno\"				value=\"".$strCmdNo."\">";
	  	$res .= "<input type=hidden name=\"date\"				value=\"".$strBillDate."\">";
	  	$res .= "<input type=hidden name=\"bargainor_id\"				value=\"".$strSaler."\">";
	  	$res .= "<input type=hidden name=\"transaction_id\"				value=\"".$strTransactionId."\">";
	  	$res .= "<input type=hidden name=\"sp_billno\"				value=\"".$strSpBillNo."\">";
	  	$res .= "<input type=hidden name=\"return_url\"				value=\"".$strRetUrl."\">";
	  	$res .= "<input type=hidden name=\"attach\"				value=\"".$strAttach."\">";
	  	$res .= "<input type=hidden name=\"sign\"				value=\"".$strSign."\">";
	  	$res .= "<input type=submit value=\"�Ƹ�ͨ������ѯ\">";
	  	$res .= "</form>";
	  }
	  else if($strVersion == 3)
	  {
			/*����MD5ǩ��*/
			$strSignText = 
						genNameVal("agentid",$strAgentid,1).
						genNameVal("attach",$strAttach).
						genNameVal("bargainor_id",$strSaler).
						genNameVal("cmdno",$strCmdNo).
						genNameVal("date",$strBillDate).
						genNameVal("key_index",$strKeyIndex).
						genNameVal("return_url",$strRetUrl).
						genNameVal("sp_billno",$strSpBillNo).
						genNameVal("transaction_id",$strTransactionId).
						genNameVal("ver",$strVersion).
						genNameVal("key",$strSpkey)
						;
			
						
		  $strSign = strtoupper(md5($strSignText));
		  
		  /*����֧����*/
		  $strRequest = $strSignText. "&sign=" . $strSign ; 
	  	  	
	  	$res  = "<form target=\"_blank\" action=\"http://mch.tenpay.com/cgi-bin/cfbi_query_order_v2.cgi\">";
	  	$res .= "<input type=hidden name=\"agentid\"				value=\"".$strAgentid."\">";
	  	$res .= "<input type=hidden name=\"attach\"				value=\"".$strAttach."\">";
	  	$res .= "<input type=hidden name=\"bargainor_id\"				value=\"".$strSaler."\">";
	  	$res .= "<input type=hidden name=\"cmdno\"				value=\"".$strCmdNo."\">";
	  	$res .= "<input type=hidden name=\"date\"				value=\"".$strBillDate."\">";	  	
	  	$res .= "<input type=hidden name=\"key_index\"				value=\"".$strKeyIndex."\">";
	  	$res .= "<input type=hidden name=\"return_url\"				value=\"".$strRetUrl."\">";
	  	$res .= "<input type=hidden name=\"sp_billno\"				value=\"".$strSpBillNo."\">";
	  	$res .= "<input type=hidden name=\"transaction_id\"				value=\"".$strTransactionId."\">";
	  	$res .= "<input type=hidden name=\"ver\"				value=\"".$strVersion."\">";	  	
	  	$res .= "<input type=hidden name=\"sign\"				value=\"".$strSign."\">";
	  	$res .= "<input type=submit value=\"�Ƹ�ͨ������ѯ\">";
	  	$res .= "</form>";
	  }
	  
	  else if($strVersion == 4)
	  {
			$strRetUrl  = "http://www.my-soft.net.cn/Pay/pay_notify_handler_4.php";
			/*����MD5ǩ��*/
			$strSignText = 
						genNameVal("attach",$strAttach).
						genNameVal("bargainor_id",$strSaler).
						genNameVal("cmdno",$strCmdNo).
						genNameVal("date",$strBillDate).
						genNameVal("return_url",$strRetUrl).
						genNameVal("sp_billno",$strSpBillNo).
						genNameVal("transaction_id",$strTransactionId).
						genNameVal("version",$strVersion).
						genNameVal("key",$strSpkey)
						;
			
						
		  $strSign = strtoupper(md5($strSignText));
		  
		  /*����֧����*/
		  $strRequest = $strSignText. "&sign=" . $strSign ; 
	  	  	
	  	$res  = "<form target=\"_blank\" action=\"https://mch.tenpay.com/cgi-bin/inquire_res.cgi\">";
	  	$res .= "<input type=hidden name=\"attach\"				value=\"".$strAttach."\">";
	  	$res .= "<input type=hidden name=\"bargainor_id\"				value=\"".$strSaler."\">";
	  	$res .= "<input type=hidden name=\"cmdno\"				value=\"".$strCmdNo."\">";
	  	$res .= "<input type=hidden name=\"date\"				value=\"".$strBillDate."\">";	  	
	  	$res .= "<input type=hidden name=\"return_url\"				value=\"".$strRetUrl."\">";
	  	$res .= "<input type=hidden name=\"sp_billno\"				value=\"".$strSpBillNo."\">";
	  	$res .= "<input type=hidden name=\"transaction_id\"				value=\"".$strTransactionId."\">";
	  	$res .= "<input type=hidden name=\"version\"				value=\"".$strVersion."\">";	  	
	  	$res .= "<input type=hidden name=\"sign\"				value=\"".$strSign."\">";
	  	$res .= "<input type=submit value=\"�Ƹ�ͨ������ѯ\">";
	  	$res .= "</form>";
	  }
	  else
	  	$res = "��֧�ֵİ汾��".$strVersion."<br>����������";
		
		
		echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strSign."</textarea><br>";
		
		
		return  $res;
		
		//return $strTransactionId;
  }



	import_request_variables("gpc","frm_");
	
	if(!isset($frm_spid))			
	{
?>
	<form action="/Pay/pay_query_res_4.php">
		<label>ƽ̨��</label><input name="agentid" value="<? echo $frm_agentid; ?>"><br>
		<label>��Ӧ��</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>�Ƹ�ͨ������</label><input name="tid" value="<? echo $frm_tid; ?>"><br>
		<label>�̻������� </label><input name="spbill" value="<? echo $frm_spbill; ?>"><br>
		<label>���� </label><input name="date" value="<? echo $frm_date; ?>"><br>
		<label>��  ��</label><input name="ver" value="<? echo $frm_ver; ?>"><br>
		<label>key����</label><input name="keyind" value="<? echo $frm_keyind; ?>"><br>
		<label>ǩ��key</label><input name="key" value="<? echo $frm_key; ?>"><br>
		<input type="submit" value="ȷ��"><br>
<?php
	}
	else
	{
		
  
  
?>
		<form action="/Pay/pay_query_res_4.php">
		<label>ƽ̨��</label><input name="agentid" value="<? echo $frm_agentid; ?>"><br>
		<label>��Ӧ��</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>�Ƹ�ͨ������</label><input name="tid" value="<? echo $frm_tid; ?>"><br>
		<label>�̻������� </label><input name="spbill" value="<? echo $frm_spbill; ?>"><br>
		<label>���� </label><input name="date" value="<? echo $frm_date; ?>"><br>
		<label>��  ��</label><input name="ver" value="<? echo $frm_ver; ?>"><br>
		<label>key����</label><input name="keyind" value="<? echo $frm_keyind; ?>"><br>
		<label>ǩ��key</label><input name="key" value="<? echo $frm_key; ?>"><br>
		<input type="submit" value="ȷ��������Ϣ"><br>
	</form>
<?php

	//function GenPayQueryPage($spid,$agentid,$keyind,$ver,$key,$tid,$date,$sp_bill)
		echo GenPayQueryPage($frm_spid,$frm_agentid,$frm_keyind,$frm_ver,$frm_key,$frm_tid,$frm_date,$frm_spbill);
	}
?>

	</div>
		<!-- -->
	<div class="Foot">
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved ԭ����� ��Ȩ���� <br />
					������ţ���ICP��08019531��
	</div>	

</div><!-- Body -->
</body>
</html>