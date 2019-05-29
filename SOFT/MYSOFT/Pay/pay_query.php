<html>
	<TITLE>My-Soft,订单查询入口</TITLE>				
		<meta name="description" content="到My-Soft定制软件，恰如您所需!" />
		<meta name="keywords" content="软件，原创软件，定制软件，发布需求，发布软件，开发者，消费者，管理员，直通车" />
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
	商户号信息:2000000000/abc12345;2000000501/123456;1200062401/;	
		2000001240/49a3f0d9ac8065342f7a9ca1d208baf7;
    2000001204/06040350901b89328c085b727a26ee69;
    2100000020/1234567890123456;
		2000000002/4554d100495342a6d8854c88ff2d6339
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
			//取签名机构key	
		  if($tmp == "1200062401")      
		    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*商户密钥,测试时即为商户号,正式上线后需修改*/
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
			else
		  	Exit("未配置的商户号:".$strSpid);
		}
		//function GenPayQueryPage($spid,$agentid,$keyind,$ver,$key,$tid,$date,$sp_bill)
  	/*财付通订单查询时为"2" */
	  $strCmdNo   = "2";
	  /*交易日期 (yyyymmdd)*/
	  $strBillDate= $date;
	  /*商户号*/	
	  $strSaler   = $strSpid;				
	  /*商户生成的订单号(最多10位)*/	
	  $strSpBillNo= $sp_bill;
	  /*重要: 交易单号
		  交易单号(28位): 商户号(10位) + 日期(8位) + 流水号(10位), 必须按此格式生成, 且不能重复
		  如果sp_billno超过10位, 则截取其中的流水号部分加到transaction_id后部(不足10位左补0)
		  如果sp_billno不足10位, 则左补0, 加到transaction_id后部*/
		$strTransactionId = $tid;
		/*财付通回调页面地址, 推荐使用ip地址的方式(最长255个字符)*/
		$strRetUrl  = "http://www.my-soft.net.cn/Pay/pay_notify_handler.php";
		/*商户私有数据, 请求回调页面时原样返回*/
		$strAttach  = "my_magic_string";	
		
		if(!isset($strVersion) || $strVersion=="" || $strVersion<2)
		{				  
			/*生成MD5签名*/
			$strSignText = "cmdno=" . $strCmdNo . "&date=" . $strBillDate . "&bargainor_id=" . $strSaler .
			      "&transaction_id=" . $strTransactionId . "&sp_billno=" . $strSpBillNo .        
			      "&return_url=" . $strRetUrl .
			      "&attach=" . $strAttach . "&key=" . $strSpkey;
		  $strSign = strtoupper(md5($strSignText));
		  
		  /*请求支付串*/
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
	  	$res .= "<input type=submit value=\"财付通订单查询\">";
	  	$res .= "</form>";
	  }
	  else if($strVersion == 3)
	  {
			/*生成MD5签名*/
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
		  
		  /*请求支付串*/
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
	  	$res .= "<input type=submit value=\"财付通订单查询\">";
	  	$res .= "</form>";
	  }
	  
	  else
	  	$res = "不支持的版本：".$strVersion."<br>请重新输入";
		
		
		echo "参与签名的字串<br><textarea >".$strSignText."</textarea><br>";
		echo "计算出来的摘要<br><textarea >".$strSign."</textarea><br>";
		
		
		return  $res;
		
		//return $strTransactionId;
  }



	import_request_variables("gpc","frm_");
	
	if(!isset($frm_spid))			
	{
?>
	<form action="/Pay/pay_query.php">
		<label>平台商</label><input name="agentid" value="<? echo $frm_agentid; ?>"><br>
		<label>供应商</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>财付通订单号</label><input name="tid" value="<? echo $frm_tid; ?>"><br>
		<label>商户订单号 </label><input name="spbill" value="<? echo $frm_spbill; ?>"><br>
		<label>日期 </label><input name="date" value="<? echo $frm_date; ?>"><br>
		<label>版  本</label><input name="ver" value="<? echo $frm_ver; ?>"><br>
		<label>key索引</label><input name="keyind" value="<? echo $frm_keyind; ?>"><br>
		<label>签名key</label><input name="key" value="<? echo $frm_key; ?>"><br>
		<input type="submit" value="确认"><br>
<?php
	}
	else
	{
		
  
  
?>
		<form action="/Pay/pay_query.php">
		<label>平台商</label><input name="agentid" value="<? echo $frm_agentid; ?>"><br>
		<label>供应商</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>财付通订单号</label><input name="tid" value="<? echo $frm_tid; ?>"><br>
		<label>商户订单号 </label><input name="spbill" value="<? echo $frm_spbill; ?>"><br>
		<label>日期 </label><input name="date" value="<? echo $frm_date; ?>"><br>
		<label>版  本</label><input name="ver" value="<? echo $frm_ver; ?>"><br>
		<label>key索引</label><input name="keyind" value="<? echo $frm_keyind; ?>"><br>
		<label>签名key</label><input name="key" value="<? echo $frm_key; ?>"><br>
		<input type="submit" value="确认以上信息"><br>
	</form>
<?php

	//function GenPayQueryPage($spid,$agentid,$keyind,$ver,$key,$tid,$date,$sp_bill)
		echo GenPayQueryPage($frm_spid,$frm_agentid,$frm_keyind,$frm_ver,$frm_key,$frm_tid,$frm_date,$frm_spbill);
	}
?>
</body>
</html>