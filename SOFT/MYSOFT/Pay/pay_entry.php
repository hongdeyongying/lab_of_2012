<html>
	<TITLE>My-Soft,����֧�����</TITLE>				
		<meta name="description" content="��My-Soft���������ǡ��������!" />
		<meta name="keywords" content="�����ԭ�����������������������󣬷�������������ߣ������ߣ�����Ա��ֱͨ��" />
		<link rel="stylesheet" href="Style/layout.css" type="text/css" media="all" />
		<link rel="stylesheet" href="Style/register.css" type="text/css" media="all" />		
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
</head>
<body>
<pre>
	�̻�����Ϣ:2000000000/abc12345;2000000501/123456;
		2000001240/49a3f0d9ac8065342f7a9ca1d208baf7;
    2000001204/06040350901b89328c085b727a26ee69;
    2100000020/1234567890123456;
		2000000002/4554d100495342a6d8854c88ff2d6339;
		1200062401/;	
		1201166701/;
		1202952101/8fef4ff29cab34775c2c4c62374b5297 ;
		2201117801/111111/71d869cb7cf34ad6251c3625ae30454f
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
	function GenPayRequestPage($spid,$agentid,$keyind,$ver,$key,$mname,$totalfee,$buyer)
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
		
  	/*�Ƹ�֧ͨ��Ϊ"1" (��ǰֻ֧�� cmdno=1)*/
	  $strCmdNo   = "1";
	  /*�������� (yyyymmdd)*/
	  $strBillDate= date('Ymd');  
	  /*��������:	
	      0		  �Ƹ�ͨ
	  		1001	��������   
	  		1002	�й���������  
	  		1003	�й���������  
	  		1004	�Ϻ��ֶ���չ����   
	  		1005	�й�ũҵ����  
	  		1006	�й���������  
	  		1008	���ڷ�չ����   
	  		1009	��ҵ����   */
	  $strBankType= "0";  
	  /*��Ʒ����*/
	  $strDesc    = $mname; 		
	  /*�û�QQ����, ������Ϊ�մ�*/
	  $strBuyerId = $buyer;
	  /*�̻���*/	
	  $strSaler   = $strSpid;				
	  /*�̻����ɵĶ�����(���10λ)*/	
	  $strSpBillNo= sprintf("%010d",time());
	  /*��Ҫ: ���׵���
		  ���׵���(28λ): �̻���(10λ) + ����(8λ) + ��ˮ��(10λ), ���밴�˸�ʽ����, �Ҳ����ظ�
		  ���sp_billno����10λ, ���ȡ���е���ˮ�Ų��ּӵ�transaction_id��(����10λ��0)
		  ���sp_billno����10λ, ����0, �ӵ�transaction_id��*/
		$strTransactionId = $strSpid . $strBillDate . $strSpBillNo;
	  $strSpBillNo= sprintf("1234567890");
		/*�ܽ��, ��Ϊ��λ*/
		$strTotalFee = $totalfee;
		/*��������: 1 �C RMB(�����) 2 - USD(��Ԫ) 3 - HKD(�۱�)*/
		$strFeeType  = "1";
		/*�Ƹ�ͨ�ص�ҳ���ַ, �Ƽ�ʹ��ip��ַ�ķ�ʽ(�255���ַ�)*/
		$strRetUrl  = "http://www.my-soft.net.cn/Pay/pay_notify_handler.php";
		/*�̻�˽������, ����ص�ҳ��ʱԭ������*/
		$strAttach  = "my_magic_string";	
		
		if(!isset($strVersion) || $strVersion=="" || $strVersion<2)
		{				  
			/*����MD5ǩ��*/
			$strSignText = "cmdno=" . $strCmdNo . "&date=" . $strBillDate . "&bargainor_id=" . $strSaler .
			      "&transaction_id=" . $strTransactionId . "&sp_billno=" . $strSpBillNo .        
			      "&total_fee=" . $strTotalFee . "&fee_type=" . $strFeeType . "&return_url=" . $strRetUrl .
			      "&attach=" . $strAttach . "&key=" . $strSpkey;
		  $strSign = strtoupper(md5($strSignText));
		  
		  /*����֧����*/
		  $strRequest = "cmdno=" . $strCmdNo . "&date=" . $strBillDate . "&bargainor_id=" . $strSaler .        
			  "&transaction_id=" . $strTransactionId . "&sp_billno=" . $strSpBillNo .        
			  "&total_fee=" . $strTotalFee . "&fee_type=" . $strFeeType . "&return_url=" . $strRetUrl .        
			  "&attach=" . $strAttach . "&bank_type=" . $strBankType . "&desc=" . $strDesc .        
			  "&purchaser_id=" . $strBuyerId .        
			  "&sign=" . $strSign ; 
	  	  	
	  	$res  = "<form target=\"_blank\"  action=\"http://www.tenpay.com/cgi-bin/v1.0/pay_gate.cgi\">";
	  	$res .= "<input type=hidden name=\"cmdno\"				value=\"".$strCmdNo."\">";
	  	$res .= "<input type=hidden name=\"date\"				value=\"".$strBillDate."\">";
	  	$res .= "<input type=hidden name=\"bank_type\"				value=\"".$strBankType."\">";
	  	$res .= "<input type=hidden name=\"desc\"				value=\"".$strDesc."\">";
	  	$res .= "<input type=hidden name=\"purchaser_id\"				value=\"".$strBuyerId."\">";
	  	$res .= "<input type=hidden name=\"bargainor_id\"				value=\"".$strSaler."\">";
	  	$res .= "<input type=hidden name=\"transaction_id\"				value=\"".$strTransactionId."\">";
	  	$res .= "<input type=hidden name=\"sp_billno\"				value=\"".$strSpBillNo."\">";
	  	$res .= "<input type=hidden name=\"total_fee\"				value=\"".$strTotalFee."\">";
	  	$res .= "<input type=hidden name=\"fee_type\"				value=\"".$strFeeType."\">";
	  	$res .= "<input type=hidden name=\"return_url\"				value=\"".$strRetUrl."\">";
	  	$res .= "<input type=hidden name=\"attach\"				value=\"".$strAttach."\">";
	  	$res .= "<input type=hidden name=\"sign\"				value=\"".$strSign."\">";
	  	$res .= "<input type=submit value=\"ʹ�òƸ�֧ͨ��\">";
	  	$res .= "</form>";
	  }
	  else if($strVersion == 3)
	  {
			/*����MD5ǩ��*/
			$strSignText = 
						genNameVal("agentid",$strAgentid,1).
						genNameVal("attach",$strAttach).
						genNameVal("bank_type",$strBankType).
						genNameVal("bargainor_id",$strSaler).
						genNameVal("cmdno",$strCmdNo).
						genNameVal("date",$strBillDate).
						genNameVal("desc",$strDesc).
						genNameVal("fee_type",$strFeeType).
						genNameVal("key_index",$strKeyIndex).
						genNameVal("purchaser_id",$strBuyerId).
						genNameVal("return_url",$strRetUrl).
						genNameVal("sp_billno",$strSpBillNo).
						genNameVal("total_fee",$strTotalFee).
						genNameVal("transaction_id",$strTransactionId).
						genNameVal("ver",$strVersion).
						genNameVal("key",$strSpkey)
						;
			
						
		  $strSign = strtoupper(md5($strSignText));
		  
		  /*����֧����*/
		  $strRequest = $strSignText. "&sign=" . $strSign ; 
	  	  	
	  	$res  = "<form target=\"_blank\" action=\"http://www.tenpay.com/cgi-bin/v1.0/pay_gate.cgi\">";
	  	$res .= "<input type=hidden name=\"agentid\"				value=\"".$strAgentid."\">";
	  	$res .= "<input type=hidden name=\"attach\"				value=\"".$strAttach."\">";
	  	$res .= "<input type=hidden name=\"bank_type\"				value=\"".$strBankType."\">";
	  	$res .= "<input type=hidden name=\"bargainor_id\"				value=\"".$strSaler."\">";
	  	$res .= "<input type=hidden name=\"cmdno\"				value=\"".$strCmdNo."\">";
	  	$res .= "<input type=hidden name=\"date\"				value=\"".$strBillDate."\">";	  	
	  	$res .= "<input type=hidden name=\"desc\"				value=\"".$strDesc."\">";
	  	$res .= "<input type=hidden name=\"fee_type\"				value=\"".$strFeeType."\">";
	  	$res .= "<input type=hidden name=\"key_index\"				value=\"".$strKeyIndex."\">";
	  	$res .= "<input type=hidden name=\"purchaser_id\"				value=\"".$strBuyerId."\">";
	  	$res .= "<input type=hidden name=\"return_url\"				value=\"".$strRetUrl."\">";
	  	$res .= "<input type=hidden name=\"sp_billno\"				value=\"".$strSpBillNo."\">";
	  	$res .= "<input type=hidden name=\"total_fee\"				value=\"".$strTotalFee."\">";
	  	$res .= "<input type=hidden name=\"transaction_id\"				value=\"".$strTransactionId."\">";
	  	$res .= "<input type=hidden name=\"ver\"				value=\"".$strVersion."\">";	  	
	  	$res .= "<input type=hidden name=\"sign\"				value=\"".$strSign."\">";
	  	$res .= "<input type=submit value=\"ʹ�òƸ�֧ͨ��\">";
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
	<form action="/Pay/pay_entry.php">
		<label>ƽ̨��</label><input name="agentid" value="<? echo $frm_agentid; ?>"><br>
		<label>��Ӧ��</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>��Ʒ��</label><input name="desc" value="<? echo $frm_desc; ?>"><br>
		<label>��  ��</label><input name="fee" value="<? echo $frm_fee; ?>"><br>
		<label>��  ��</label><input name="ver" value="<? echo $frm_ver; ?>"><br>
		<label>key����</label><input name="keyind" value="<? echo $frm_keyind; ?>"><br>
		<label>ǩ��key</label><input name="key" value="<? echo $frm_key; ?>"><br>
		<input type="submit" value="ȷ��"><br>
	</form>
<?php
	}
	else
	{
		
  
  
?>
		<form action="/Pay/pay_entry.php">
		<label>ƽ̨��</label><input name="agentid" value="<? echo $frm_agentid; ?>"><br>
		<label>��Ӧ��</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>��Ʒ��</label><input name="desc" value="<? echo $frm_desc; ?>"><br>
		<label>��  ��</label><input name="fee" value="<? echo $frm_fee; ?>"><br>
		<label>��  ��</label><input name="ver" value="<? echo $frm_ver; ?>"><br>
		<label>key����</label><input name="keyind" value="<? echo $frm_keyind; ?>"><br>
		<label>ǩ��key</label><input name="key" value="<? echo $frm_key; ?>"><br>
		<input type="submit" value="ȷ��������Ϣ"><br>
	</form>
<?php

	//function GenPayRequestPage($spid,$agentid,$keyind,$ver,$key,$mname,$totalfee,$buyer,$tid)
		echo GenPayRequestPage($frm_spid,$frm_agentid,$frm_keyind,$frm_ver,$frm_key,$frm_desc,$frm_fee,"");
	}
?>
</body>
</html>