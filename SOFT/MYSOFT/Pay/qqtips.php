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
	
<pre>
商户号信息:2000000000/abc12345;
	2000000501/123456;                           财付通费率0.1%
	2000001240/49a3f0d9ac8065342f7a9ca1d208baf7; 财付通费率0.1%，每笔最高500
	2000001204/06040350901b89328c085b727a26ee69; 财付通费率0.1%，每笔最低100
	2100000020/1234567890123456;                 
	2000000002/4554d100495342a6d8854c88ff2d6339; 财付通费率0.1%，每笔最低100，最高500
	1200062401/;	
	1201166701/;
	1202952101/8fef4ff29cab34775c2c4c62374b5297 ;
	
		
</pre>	
<script>
	function cmf_submit()
	{
		var pwd = document.getElementById('frm').hidval.value;//prompt("请输入口令;");
		if(pwd.length ==10)
		{			
			return true;
		}
		return false;
	}	
	</script>
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
	function GenQQtipsPage($spid,$amid,$seq,$mask,$uintype,$uin,$mdata,$pwd)
  {
  	if($pwd != "hdsy100200")
  	{
  		Exit("你无权发送消息:".$pwd);
  	}
  	if(isset($spid) && ($spid!=""))
		{
			$tmp = $spid;
			//取签名机构key	
		  if($tmp == "1200062401")      
		    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*商户密钥,测试时即为商户号,正式上线后需修改*/
			else if($tmp == "2000000000")      
				$strSpkey = "abc12345";
			else if($tmp == "2000000501")
				$strSpkey = "123456";
			else if($tmp == "2000001240")
				$strSpkey = "49a3f0d9ac8065342f7a9ca1d208baf7";
			else if($tmp == "2000001204")
				$strSpkey = "06040350901b89328c085b727a26ee69";
			else if($tmp == "2100000020")
				$strSpkey = "1234567890123456";
			else if($tmp == "2000000002")
				$strSpkey = "4554d100495342a6d8854c88ff2d6339";
			else if($tmp == "1202952101")
				$strSpkey = "8fef4ff29cab34775c2c4c62374b5297";
			else
		  	Exit("未配置的商户号:".$spid);
		}
		/*生成MD5签名*/
		//$mdata1=  ereg_replace("=","%3D",$mdata);
		//$mdata = ereg_replace("&","%26",$mdata1);
			
		$strSignText = $spid.$amid.$seq.$mask.$uin.$uintype.$mdata.$strSpkey;
											
	  $strSign = strtoupper(md5($strSignText));//UPCASE(MD5(spid+amid+seq+mask+uin+uintype+mdata+sp_key))
	  
	  /*请求支付串*/
	  $strRequest = "内容".$strSignText. "\r\n签名" . $strSign ; 
  	  	
  	$res  = "<form   method='get' target=\"_blank\" action=\"http://app.tenpay.com/cgi-bin/mams/AMSender.cgi\">";
  	$res .= "<input type=hidden name=\"spid\"				value=\"".$spid."\">";
  	$res .= "<input type=hidden name=\"amid\"				value=\"".$amid."\">";
  	$res .= "<input type=hidden name=\"seq\"				value=\"".$seq."\">";
  	$res .= "<input type=hidden name=\"mask\"				value=\"".$mask."\">";
  	$res .= "<input type=hidden name=\"uintype\"				value=\"".$uintype."\">";	  	
  	$res .= "<input type=hidden name=\"uin\"				value=\"".$uin."\">";
  	$res .= "<input type=hidden name=\"mdata\"				value=\"".$mdata."\">";
  	$res .= "<input type=hidden name=\"sign\"				value=\"".$strSign."\">";
  	$res .= "<input type=submit value=\"发送消息\">";
  	$res .= "</form>";
		
		echo "参与签名的字串<br><textarea >".$strSignText."</textarea><br>";
		echo "计算出来的摘要<br><textarea >".$strSign."</textarea><br>";
		
		
		return  $res;
		
		//return $strTransactionId;
  }



	import_request_variables("gpc","frm_");
	
	if(!isset($frm_spid))			
	{
		$frm_spid = "1202952101";
		$frm_amid = "M200810";
		$frm_mask = "7";
		$frm_seq = time();
		$frm_uintype = "1";
		$frm_uin = "605311966";
		$frm_mdata = "airno=CZ9988&frm=shenzhen&end=beijing&datetime=2009-10-01 10:30:00&datetime2=2009-10-01 13:30:00&url=url";
?>
	<form id="frm" method='post'  action="/Pay/qqtips.php"  onsubmit="javascript:cmf_submit();">
		<label>商户号</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>消息号</label><input name="amid" value="<? echo $frm_amid; ?>"><br>
		<label>消息序号</label><input name="seq" value="<? echo $frm_seq; ?>"><br>
		<label>消息掩码</label><input name="mask" value="<? echo $frm_mask; ?>"><br>
		<label>用户类型</label><input name="uintype" value="<? echo $frm_uintype; ?>">1：uin为用户账户名；2：uin为账户名的加密串；3：uin为用户内部id。<br>
		<label>用户ID  </label><input name="uin" value="<? echo $frm_uin; ?>"><br>
		<label>消息体  </label><input name="mdata" value="<? echo $frm_mdata; ?>"><br>
		<label>密码  </label><input type="password"  name="hidval" value=""><br>
		<input type="submit" value="确认"><br>
	</form>
<?php
	}
	else
	{
		
  
  
?>
	<form id="frm"  method='post'  action="/Pay/qqtips.php" onsubmit="javascript:cmf_submit();">
		<input type=hidden  name="hidval" value="err"><br>
		<label>商户号</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>消息号</label><input name="amid" value="<? echo $frm_amid; ?>"><br>
		<label>消息序号</label><input name="seq" value="<? echo $frm_seq; ?>"><br>
		<label>消息掩码</label><input name="mask" value="<? echo $frm_mask; ?>"><br>
		<label>用户类型</label><input name="uintype" value="<? echo $frm_uintype; ?>">1：uin为用户账户名；2：uin为账户名的加密串；3：uin为用户内部id。默认为1。<br>
		<label>用户ID  </label><input name="uin" value="<? echo $frm_uin; ?>"><br>
		<label>消息体  </label><input name="mdata" value="<? echo $frm_mdata; ?>"><br>
		<label>密码  </label><input type="password"  name="hidval" value=""><br>
		<input type="submit" value="确认以上信息"><br>
	</form>
<?php

	//function GenPayQueryPage($spid,$agentid,$keyind,$ver,$key,$tid,$date,$sp_bill)
		echo GenQQtipsPage($frm_spid,$frm_amid,$frm_seq,$frm_mask,$frm_uintype,$frm_uin,$frm_mdata,$frm_hidval);
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
