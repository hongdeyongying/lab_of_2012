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
		if($cd == 0)
		{
			echo "<label>验证通过</label><br>";
		}
		else
		{
			echo "<label>验证失败</label><br>";
		}
			echo "<textarea>".$url."</textarea><br>";
			
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
  
  //取签名机构key	
  if($frm_spid == "1200062401")      
    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*商户密钥,测试时即为商户号,正式上线后需修改*/
	else if($frm_spid == "2000000000")      
		$strSpkey = "abc12345";
	else if($frm_spid == "2000000501")
		$strSpkey = "123456";
	else if($frm_spid == "2000001240")
		$strSpkey = "49a3f0d9ac8065342f7a9ca1d208baf7";
	else if($frm_spid == "2000001204")
		$strSpkey = "06040350901b89328c085b727a26ee69";
	else if($frm_spid == "2100000020")
		$strSpkey = "1234567890123456";
	else if($frm_spid == "2000000002")
		$strSpkey = "4554d100495342a6d8854c88ff2d6339";
			else if($frm_spid == "1202952101")
				$strSpkey = "8fef4ff29cab34775c2c4c62374b5297";
	else
	{
		ExitWithInfo(1,"取签名商户key失败");
  	
  }
  	
  /*返回值定义*/
  $iRetOK       = 0;		// 成功					
  $iInvalidSpid = 1;		// 商户号错误
  $iInvalidSign = 2;		// 签名错误
  $iTenpayErr	  = 3;		// 财付通返回支付失败

  /*验签*/
  
			$strSignText = 
						genNameVal("bank_id",$frm_bank_id).
						genNameVal("cmdno",$frm_cmdno).
						genNameVal("cre_id",$frm_cre_id).
						genNameVal("name",$frm_name).
						genNameVal("retcd",$frm_retcd).
						genNameVal("retmsg",$frm_retmsg).
						genNameVal("return_url",$frm_return_url).
						genNameVal("spid",$frm_spid).
						genNameVal("uin",$frm_uin).
						genNameVal("key",$strSpkey)
						;
	$strLocalSign = strtoupper(md5($strSignText));     
  
  if( $strLocalSign  != $frm_sign)
  {
  	ExitWithInfo(1,$strSignText."\r\n[".$strLocalSign);
  }  
  

  else if( $frm_retcd != "0" )
  {
  	ExitWithInfo(1,$strSignText);
  }
  else
  {
  	ExitWithInfo(0,$strSignText);
  }
  
?>

</div>
		<!-- -->
	<div class="Foot">
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved 原创软件 版权所有 <br />
					备案序号：粤ICP备08019531号
	</div>	

</div><!-- Body -->
</body>
</html>
