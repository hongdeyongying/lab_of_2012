<html>
	<head>
		<TITLE>My-Soft,原创软件，量身定制软件，如您所需的软件</TITLE>
		<meta http-equiv="pragma" content="no-cache" />
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
		<meta name="description" content="到My-Soft量身定制软件，做如您所需的软件!" />
		<meta name="keywords" content="My-Soft,软件,原创软件,量身定制软件,如您所需的软件，发布软件需求，发布软件，开发者，消费者，管理员，直通车" />
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
					首页</li>			<li class="NavSplit"> </li>
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
					
					>网上支付</li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"
					onclick="javascript:window.external.AddFavorite('http://www.my-soft.net.cn','My-Soft,软件恰如我所需')"
					>收藏本站</li>					<li class="NavSplit"> </li>
			</ul>
		</div>
	</div>

	<div class="Welcome" >
		
		<p>&nbsp;&nbsp;&nbsp;&nbsp;网上支付公司为电子商务提供了资金流转的便利，如今借助一家网上支付公司即可以支持全国大多数银行的网银，极大方便的网上营销
			平台。特别的他们提供了比银行，银联等传统金融机构更平易近人的服务，更加开放，以至于他们能够快速跟进并愿意满足各类应用场景的支付需求。相信第三方支
			付平台将进一步丰富日常生活中的支付手段，让人们支付更方便！
		</P>
		
		<p>&nbsp;&nbsp;&nbsp;&nbsp;这里给出使用腾讯财付通对外提供的各种功能的实现示例，可以组合以满足自身应用场景的需要。
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
  
  $strVersion = $frm_version;
  $strBusType = $frm_bus_type;
  $strBusArgs = $frm_bus_args;

	echo  "版本号：".$strVersion;
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
			else if($strSaler == "1202119401")
				$strSpkey = "comd4f16b4ec3d7aaf082bab5194cfcn";
			else if($strSpid == "1900000107")
				$strSpkey = "82d2f8b9fd7695aec51415ab2900a755";

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
	else if($strVersion == 4)
	{
			$strSignText = 
						genNameVal("agentid",$strAgentid,1).
						genNameVal("attach",$strAttach).
						genNameVal("bargainor_id",$strBargainorId).
						genNameVal("bus_args",$strBusArgs).
						genNameVal("bus_type",$strBusType).
						genNameVal("cmdno",$strCmdno).
						genNameVal("date",$strBillDate).
						genNameVal("fee_type",$strFeeType).
						genNameVal("key_index",$strKeyIndex).
						genNameVal("pay_info",$strPayInfo).
						genNameVal("pay_result",$strPayResult).		
						genNameVal("purchaser_id",$frm_purchaser_id).						
						genNameVal("sp_billno",$strSpBillno).
						genNameVal("total_fee",$strTotalFee).
						genNameVal("transaction_id",$strTransactionId).
						genNameVal("version",$strVersion). 
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
	</div>
		<!--
	<div class="Foot">
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved 原创软件 版权所有 <br />
					备案序号：粤ICP备08019531号
	</div>	 -->

</div><!-- Body -->
</body>
</html>