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
					onclick="javascript:document.location.href='/';">
					首页</li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"
					onclick="javascript:document.location.href='/myDownloader/';"
					>下载工具</li>			<li class="NavSplit"> </li>
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
	
	if($frm_ver != 1)
		Exit("不支持的版本号:".$frm_ver);
	
		$strVersion = 4;
	 /*商户生成的订单号(最多10位)*/	
	  $strSpBillNo= sprintf("%010d",time());
	  /*重要: 交易单号
		  交易单号(28位): 商户号(10位) + 日期(8位) + 流水号(10位), 必须按此格式生成, 且不能重复
		  如果sp_billno超过10位, 则截取其中的流水号部分加到transaction_id后部(不足10位左补0)
		  如果sp_billno不足10位, 则左补0, 加到transaction_id后部*/
		$strTransactionId = $strSpid . $strBillDate . $strSpBillNo;
		/*财付通支付为"1" (当前只支持 cmdno=1)*/
	  $strCmdNo   = "1";
	  /*交易日期 (yyyymmdd)*/
	  $strBillDate= date('Ymd');  
	  /*银行类型:	
	      0		  财付通
	  		1001	招商银行   
	  		1002	中国工商银行  
	  		1003	中国建设银行  
	  		1004	上海浦东发展银行   
	  		1005	中国农业银行  
	  		1006	中国民生银行  
	  		1008	深圳发展银行   
	  		1009	兴业银行   */
			  		
	  $strBankType= $frm_bank_type;  
	  /*商品名称*/
	  $strDesc    = $frm_desc; 		
	  /*用户QQ号码, 现在置为空串*/
	  $strBuyerId = $frm_purchaser_id;
	  /*商户号*/	
	  $strSaler   = $frm_spid;				
	  /*商户生成的订单号(最多10位)*/	
	  $strSpBillNo= sprintf("%010d",time());
	  /*重要: 交易单号
		  交易单号(28位): 商户号(10位) + 日期(8位) + 流水号(10位), 必须按此格式生成, 且不能重复
		  如果sp_billno超过10位, 则截取其中的流水号部分加到transaction_id后部(不足10位左补0)
		  如果sp_billno不足10位, 则左补0, 加到transaction_id后部*/
		$strTransactionId = $strSaler . $strBillDate . $strSpBillNo;
		/*总金额, 分为单位*/
		$strTotalFee = $frm_fee;
		/*货币类型: 1 – RMB(人民币) 2 - USD(美元) 3 - HKD(港币)*/
		$strFeeType  = "1";
		/*财付通回调页面地址, 推荐使用ip地址的方式(最长255个字符)*/
		$strRetUrl  = "http://www.my-soft.net.cn/Pay/pay_split_respond.php";
		/*商户私有数据, 请求回调页面时原样返回*/
		$strAttach  = "my_magic_string";	
	  $strSpBillNo= sprintf("gaussgao%010d",time());
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
			else if($strSaler == "1900000107")
				$strSpkey = "82d2f8b9fd7695aec51415ab2900a755";

			else
		  	Exit("未配置的商户号:".$strSpid);
		/*生成MD5签名*/
			$strSignText = 
						//genNameVal("agentid",$strAgentid,1).
						genNameVal("attach",$strAttach).
						genNameVal("bank_type",$strBankType).
						genNameVal("bargainor_id",$strSaler).
						genNameVal("bus_args",$frm_bus_args).
						genNameVal("bus_desc",$frm_bus_desc).
						genNameVal("bus_type",$frm_bus_type).
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
						genNameVal("version",$strVersion).
						genNameVal("key",$strSpkey)
						;
									
		  $strSign = strtoupper(md5($strSignText));
?>
<script>
	function SubMit()
	{
		alert(1);
		var buyer=document.getElementById('frm').purchaser_id.value;
		alert(buyer);
		if(buyer.length <=5)
		{
			alert("error 买家ID="+buyer);
			return;
		}
		alert(document.getElementById('frm').action);
		document.getElementById('frm').action="https://mch.tenpay.com/cgi-bin/trust_pay.cgi";
		alert(document.getElementById('frm').action);
		document.getElementById('frm').submit();
		return false;
	}	
</script>
<form id="frm"  target="_blank" action="https://www.tenpay.com/cgi-bin/v4.0/pay_set.cgi">
	<fieldset ><legend>支付信息</legend>
		<label>业务代码</label><input readonly name="cmdno" value="<? echo $strCmdNo; ?>"><br>
		<label>交易日期</label><input readonly name="date" value="<? echo $strBillDate; ?>"><br>
		<label>支付渠道</label><input readonly name="bank_type" value="<? echo $strBankType; ?>"><br>
		<label>商品名</label><input readonly name="desc" value="<? echo $strDesc; ?>"><br>
		<label>买方</label><input readonly name="purchaser_id" value="<? echo $strBuyerId; ?>"><br>
		<label>卖方</label><input readonly name="bargainor_id" value="<? echo $strSaler; ?>"><br>
		<label>财付通订单</label><input readonly name="transaction_id" value="<? echo $strTransactionId; ?>"><br>
		<label>商户订单</label><input readonly name="sp_billno" value="<? echo $strSpBillNo; ?>"><br>
		<label>订单总额</label><input readonly name="total_fee" value="<? echo $strTotalFee; ?>"><br>
		<label>币种</label><input readonly name="fee_type" value="<? echo $strFeeType; ?>"><br>
		<label>回调URL</label><input readonly name="return_url" value="<? echo $strRetUrl ; ?>"><br>
		<label>商家数据标志</label><input readonly name="attach" value="<? echo $strAttach; ?>"><br>
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
		<label></label><input type="submit" value="确认上述信息">
		<input type="button" value="确认上述信息(委托代扣)" onclick="javascript:return SubMit();"><br>
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
