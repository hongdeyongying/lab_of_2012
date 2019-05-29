<html>
	<TITLE>My-Soft,在线支付入口</TITLE>				
		<meta name="description" content="到My-Soft定制软件，恰如您所需!" />
		<meta name="keywords" content="软件，原创软件，定制软件，发布需求，发布软件，开发者，消费者，管理员，直通车" />
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
		echo "<p>未配置的商户号</p><br>";
  	echo "用来签名的商户<br><textarea >".$strSpid."</textarea><br>";
  	echo "参与签名的字串<br><textarea >".$strSignText."</textarea><br>";
		echo "计算出来的摘要<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
  	
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
		echo "<p>不支持的版本</p><br>";
  	echo "通知请求的版本<br><textarea >".$strVersion."</textarea><br>";
  	echo "参与签名的字串<br><textarea >".$strSignText."</textarea><br>";
		echo "计算出来的摘要<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
	}
		
	$strLocalSign = strtoupper(md5($strSignText));     
  
  if( $strLocalSign  != $strMd5Sign)
  {
  	echo "<p>验证MD5签名失败</p><br>";
  	echo "通知请求的KEY<br><textarea >".$strMd5Sign."</textarea><br>";
  	echo "参与签名的字串<br><textarea >".$strSignText."</textarea><br>";
		echo "计算出来的摘要<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
    //ShowExitMsg( "验证MD5签名失败."); 
  }  
  
  if(( $strSpid != $strBargainorId ) && ($strSpid != $strAgentid))
  {
    echo "<p>商户号错误</p><br>";
  	echo "商户号<br><textarea >".$strBargainorId.":".$strAgentid."</textarea><br>";
  	echo "参与签名的字串<br><textarea >".$strSignText."</textarea><br>";
		echo "计算出来的摘要<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }

  if( $strPayResult != "0" )
  {
    //ShowExitMsg( "支付失败."); 
    echo "<p>支付失败</p><br>";
  	echo "支付提示  信息<br><textarea >".$strPayInfo."</textarea><br>";
  	echo "参与签名的字串<br><textarea >".$strSignText."</textarea><br>";
		echo "计算出来的摘要<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }
  else
  {
  	echo "<p>支付成功</p><br>";
  	echo "支付提示  信息<br><textarea >".$strPayInfo."</textarea><br>";
  	echo "参与签名的字串<br><textarea >".$strSignText."</textarea><br>";
		echo "计算出来的摘要<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }
  
?>
</body>
</html>