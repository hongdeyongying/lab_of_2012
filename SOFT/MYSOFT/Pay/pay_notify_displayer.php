<html>
	<TITLE>My-Soft,����֧�����</TITLE>				
		<meta name="description" content="��My-Soft���������ǡ��������!" />
		<meta name="keywords" content="�����ԭ�����������������������󣬷�������������ߣ������ߣ�����Ա��ֱͨ��" />
		<link rel="stylesheet" href="Style/layout.css" type="text/css" media="all" />
		<link rel="stylesheet" href="Style/register.css" type="text/css" media="all" />		
<head>
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

  import_request_variables("gpc", "frm_");
  /*ȡ���ز���*/
  $strCmdno			= $frm_cmdno;
  $strPayResult		= $frm_pay_result;
  $strPayInfo		= $frm_pay_info;
  $strBillDate		= $frm_date;
  $strBargainorId	= $frm_bargainor_id;
  $strTransactionId	= $frm_transaction_id;
  $strSpBillno		= $frm_sp_billno;
  $strTotalFee		= $frm_total_fee;
  $strFeeType		= $frm_fee_type;
  $strAttach			= $frm_attach;
  $strMd5Sign		= $frm_sign;
  
  $strAgentid = $frm_agentid;
  $strKeyIndex= $frm_key_index;
  $strVersion = $frm_ver;

  /*���ز���*/
  //�̻�����Ϣ:2000000000/abc12345;2000000501/123456
  //if((!isset($strVersion)) || ($strVersion=="") ||($strVersion < 2) || ($strKeyIdex == 1))
  //{
  	$strSpid = $strBargainorId;
  //}
  if(($strVersion == 3) && ($strKeyIndex == 2))
  {
  	$strSpid = $strAgentid;
  }
  //else
  //	ShowExitMsg("��֧�ֵİ汾��:".$strVersion);
  
  //ȡǩ������key	
  if($strSpid == "1200062401")      
    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*�̻���Կ,����ʱ��Ϊ�̻���,��ʽ���ߺ����޸�*/
	else if($strSpid == "2000000000")      
		$strSpkey = "abc12345";
	else if($strSpid == "2000000501")
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
	{
		echo "<p>δ���õ��̻���</p><br>";
  	echo "����ǩ�����̻�<br><textarea >".$strSpid."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
  	
  }
  	
  /*����ֵ����*/
  $iRetOK       = 0;		// �ɹ�					
  $iInvalidSpid = 1;		// �̻��Ŵ���
  $iInvalidSign = 2;		// ǩ������
  $iTenpayErr	  = 3;		// �Ƹ�ͨ����֧��ʧ��

  /*��ǩ*/
  if((!isset($strVersion)) || ($strVersion=="") ||($strVersion < 2))
  {
	  $strSignText  = "cmdno=" . $strCmdno . "&pay_result=" . $strPayResult . 
			                  "&date=" . $strBillDate . "&transaction_id=" . $strTransactionId .
				                "&sp_billno=" . $strSpBillno . "&total_fee=" . $strTotalFee .
				                "&fee_type=" . $strFeeType . "&attach=" . $strAttach .
				                "&key=" . $strSpkey;
	}
	else if($strVersion == 3)
	{
			$strSignText = 
						genNameVal("agentid",$strAgentid,1).
						genNameVal("attach",$strAttach).
						genNameVal("bargainor_id",$strBargainorId).
						genNameVal("cmdno",$strCmdno).
						genNameVal("date",$strBillDate).
						genNameVal("fee_type",$strFeeType).
						genNameVal("key_index",$strKeyIndex).
						genNameVal("pay_info",$strPayInfo).
						genNameVal("pay_result",$strPayResult).						
						genNameVal("sp_billno",$strSpBillno).
						genNameVal("total_fee",$strTotalFee).
						genNameVal("transaction_id",$strTransactionId).
						genNameVal("ver",$strVersion).
						genNameVal("key",$strSpkey)
						;
	}
	else
	{
		echo "<p>��֧�ֵİ汾</p><br>";
  	echo "֪ͨ����İ汾<br><textarea >".$strVersion."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
	}
		
	$strLocalSign = strtoupper(md5($strSignText));     
  
  if( $strLocalSign  != $strMd5Sign)
  {
  	echo "<p>��֤MD5ǩ��ʧ��</p><br>";
  	echo "֪ͨ�����KEY<br><textarea >".$strMd5Sign."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
    //ShowExitMsg( "��֤MD5ǩ��ʧ��."); 
  }  
  
  if(( $strSpid != $strBargainorId ) && ($strSpid != $strAgentid))
  {
    echo "<p>�̻��Ŵ���</p><br>";
  	echo "�̻���<br><textarea >".$strBargainorId.":".$strAgentid."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }

  if( $strPayResult != "0" )
  {
    //ShowExitMsg( "֧��ʧ��."); 
    echo "<p>֧��ʧ��</p><br>";
  	echo "֧����ʾ  ��Ϣ<br><textarea >".$strPayInfo."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }
  else
  {
  	echo "<p>֧���ɹ�</p><br>";
  	echo "֧����ʾ  ��Ϣ<br><textarea >".$strPayInfo."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }
  
?>
</body>
</html>