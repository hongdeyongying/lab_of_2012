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
	
	import_request_variables("gp","frm_");
	import_request_variables("c","ck_");	
	
	if($frm_ver != 4)
		Exit("不支持的版本号:".$frm_ver);
	
		$strVersion = $frm_ver;
	 /*商户生成的订单号(最多10位)*/	
	  $strSpBillNo= $frm_billno;
	  /*原始交易单号*/
		$strTransactionId = $frm_tid;
		/*分账退款为3*/
	  $strCmdNo   = "3";
	  /*商户号*/	
	  $strSaler   = $frm_spid;				
		/*总金额, 分为单位*/
		$strTotalFee = $frm_fee;
		/*货币类型: 1 – RMB(人民币) 2 - USD(美元) 3 - HKD(港币)*/
		$strFeeType  = "1";
		/*财付通回调页面地址, 推荐使用ip地址的方式(最长255个字符)*/
		$strRetUrl  = "http://www.my-soft.net.cn/Pay/pay_split_respond.php";
		//取签名机构key	
		  if($strSaler == "1200062401")      
		    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*商户密钥,测试时即为商户号,正式上线后需修改*/
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
		  	Exit("未配置的商户号:".$strSpid);
		/*生成MD5签名*/
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
	<fieldset ><legend>支付信息</legend>
		<label>业务代码</label><input readonly name="cmdno" value="<? echo $strCmdNo; ?>"><br>
		<label>卖方</label><input readonly name="bargainor_id" value="<? echo $strSaler; ?>"><br>
		<label>财付通订单</label><input readonly name="transaction_id" value="<? echo $strTransactionId; ?>"><br>
		<label>商户订单</label><input readonly name="sp_billno" value="<? echo $strSpBillNo; ?>"><br>
		<label>订单总额</label><input readonly name="total_fee" value="<? echo $strTotalFee; ?>"><br>
		<label>币种</label><input readonly name="fee_type" value="<? echo $strFeeType; ?>"><br>
		<label>回调URL</label><input readonly name="return_url" value="<? echo $strRetUrl ; ?>"><br>
		<label>版  本</label><input readonly name="version" value="<? echo $strVersion; ?>"><br>
	</fieldset>
	<fieldset ><legend>分账信息</legend>
		<label>类型</label><input readonly name="bus_type" value="<? echo $frm_bus_type; ?>"><br>
		<label>参数</label><input readonly name="bus_args" value="<? echo $frm_bus_args; ?>"><br>
		<label>信息</label><input readonly name="bus_desc" value="<? echo $frm_bus_desc; ?>"><br>
	</fieldset>
	<fieldset ><legend>签名信息</legend>
		<label>签名内容</label><textarea readonly > <? echo $strSignText;  ?></textarea>
		<label>签名</label><input readonly name="sign" value="<? echo $strSign; ?>"><br>		
	</fieldset>
		<label></label><input type="submit" value="确认上述信息"><br>
		<label></label><input type="button" value="返回上一步重新填写" onclick="javascript:window.history.back();"><br>
</form>
	</div>
		<!-- 
	<div class="Foot">
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved 原创软件 版权所有 <br />
					备案序号：粤ICP备08019531号
	</div>	-->

</div><!-- Body -->
</body>
</html>
