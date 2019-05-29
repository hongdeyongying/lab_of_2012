<?php	

/*
<meta name="TENCENT_ONLINE_PAYMENT" content="China TENCENT">
<html>
<script language=javascript>
window.location.href='http://back_url';
</script>
</html>

*/
	function ExitWithInfo($cd,$url)
	{
		$sHead   = "<meta name=\"TENCENT_ONLINE_PAYMENT\" content=\"China TENCENT\">" ;
		$sFormat = "<html>" .
							"<script language=javascript>" .
							"window.location.href='http://www.my-soft.net.cn/Pay/pay_notify_displayer.php?%s';" .
							"</script></html>";
		
	$filename = "/webhome/h188709/web/www/Log/pay_respones.xml";
	
	$url1  = ereg_replace("&","%26",$url);
	$tm = date('Y-m-d H:m:s');
	$reqstr = "\r\n<row>" .
						"<time>" . $tm . "</time>".
						"<paras>". $url1 ."</paras>".
						"</row>";
	
		$handle = fopen($filename, "a+");
		flock($handle,LOCK_EX);
		fwrite($handle, $reqstr);
		flock($handle,LOCK_UN);
		fclose($handle);			
		
		if($cd == 0)
		{
			exit( sprintf($sHead.$sFormat,$url));
		}
		else
		{
			exit(sprintf($sFormat,$url));
		}
		
	}

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
  /*取返回参数*/
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



$strSignText1 = 
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
						genNameVal("key",$strSpkey).
						genNameVal("sign",$strMd5Sign)
						;
  /*本地参数*/
  //商户号信息:2000000000/abc12345;2000000501/123456
  //if((!isset($strVersion)) || ($strVersion=="") ||($strVersion < 2) || ($strKeyIdex == 1))
  //{
  	$strSpid = $strBargainorId;
  //}
  if(($strVersion == 3) && ($strKeyIndex == 2))
  {
  	$strSpid = $strAgentid;
  }
  //else
  //	ShowExitMsg("不支持的版本号:".$strVersion);
  
  //取签名机构key	
  if($strSpid == "1200062401")      
    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*商户密钥,测试时即为商户号,正式上线后需修改*/
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
		ExitWithInfo(1,$strSignText1);
  	
  }
  	
  /*返回值定义*/
  $iRetOK       = 0;		// 成功					
  $iInvalidSpid = 1;		// 商户号错误
  $iInvalidSign = 2;		// 签名错误
  $iTenpayErr	  = 3;		// 财付通返回支付失败

  /*验签*/
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
		ExitWithInfo(1,$strSignText1);
	}
		
	$strLocalSign = strtoupper(md5($strSignText));     
  
  if( $strLocalSign  != $strMd5Sign)
  {
  	ExitWithInfo(1,$strSignText1);
  }  
  
  if(( $strSpid != $strBargainorId ) && ($strSpid != $strAgentid))
  {
  	ExitWithInfo(1,$strSignText1);
  }

  if( $strPayResult != "0" )
  {
  	ExitWithInfo(1,$strSignText1);
  }
  else
  {
  	ExitWithInfo(0,$strSignText1);
  }
  
?>
</body>
</html>