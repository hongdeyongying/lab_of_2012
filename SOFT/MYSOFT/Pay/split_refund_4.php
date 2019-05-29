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
	
	假设机票供应商：602023915
	假设独立分润方：605311966，372132908
	
	total_fee - 100 - 100 - 100 - iCftFee = 机票供应商应得票款
	iCftFee根据配置计算
	
	1	机票供应商 : 602023915
	2	平台服务方 : 605311966
	3	资金清算方 : 配置
	4	独立分润方 : 372132908
	5	机票销售商 : 支付确定

		
</pre>	
<script >
	
	function autoFill()
	{
		var f1 = document.getElementById('frm');
		
		if(iTotleFee < 300)
		{
			alert("金额太小");
			return;
		}
		
		var iTotleFee = f1.fee.value;
		var iRefundTotleFee = f1.refund_fee.value;
		var iRefundCnt = f1.refund_cnt.value;
		var iCftFee = 0;
		var iProviderFee = 0;
		var iCnt    = Math.floor(Math.random( )*10) +1;

		//
		if(iRefundTotleFee <= 0)
		{
			alert("退款总额要大于0");
			return;
		}
		//计算财付通要退的费用
			//1.先计算财付通收的总额
			switch(f1.spid.value)
			{
				case '2000000501':
					iCftFee =  Math.round(iTotleFee / 1000);break;
				case '2000001240':
					iCftFee = Math.min(Math.round(iTotleFee / 1000),500);break;
				case '2000001204':
					iCftFee = Math.max(Math.round(iTotleFee / 1000),100);break;
				case '2000000002':
					iCftFee = Math.min(500,Math.max(Math.round(iTotleFee / 1000),100));break;
				case '2000000000':
					iCftFee = 0;break;
				case '1202952101':
					iCftFee =  Math.round(iTotleFee*5 / 1000);break;
				case '1900000107':
	  				iCftFee = 0; break;

				default:
					alert("无此商户");return;
					
			}
		
		//alert(iCftFee);
		//计算机票供应商费用
		iProviderFee = iTotleFee - 100 - 100 - iCftFee;
		
		switch(f1.bus_type.value)
		{
			case '1':case '65':case '97':case '129'://立即分账，通用
			{
				//2.再计算财付通可以退的最大金额
				var iCftRefundFee = Math.round(iCftFee * (iRefundTotleFee / iTotleFee));
				var iOtherRefundFee = Math.round(100 * (iRefundTotleFee / iTotleFee));
				var iProviderRefundFee = iRefundTotleFee - iCftRefundFee - 2*iOtherRefundFee;
				
				f1.bus_args.value = iRefundTotleFee.toString()
													 +"|602023915^"+iProviderRefundFee.toString()
					                 +"|605311966^"+iOtherRefundFee.toString()
					                 +"|372132908^"+iOtherRefundFee.toString();
				break;				                 
			}
			case '2':case '66':case '98':case '130'://立即分账，51666用
			{				
				f1.bus_args.value = iRefundCnt.toString()+"|602023915|"+iRefundTotleFee.toString();
				break;
			}
			case '33'://延迟分账，通用
			{
				//2.再计算财付通可以退的最大金额
				var iCftRefundFee = Math.round(iCftFee * (iRefundTotleFee / iTotleFee));
				var iOtherRefundFee = Math.round(100 * (iRefundTotleFee / iTotleFee));
				var iProviderRefundFee = iRefundTotleFee - iCftRefundFee - 2*iOtherRefundFee;
				
				f1.bus_args.value = iRefundTotleFee.toString()
													 +"|602023915^"+iProviderFee.toString()
					                 +"|605311966^"+iOtherRefundFee.toString()
					                 +"|372132908^"+iOtherRefundFee.toString();
				break;				                 
			}
			case '34'://延迟分账，51666用
			{				
				f1.bus_args.value = iRefundCnt.toString()+"|602023915|"+iRefundTotleFee.toString();
				break;
			}
			default:
				alert("不支持的分账类型");return;
		}
	}
</script>	
<?php

	import_request_variables("gp","frm_");  
	import_request_variables("c","ck_");	
	
	if(!isset($frm_spid)) $frm_spid="1900000107"; 
	if(!isset($frm_fee)) $frm_fee="500";
	if(!isset($frm_ver)) $frm_ver="4";
	if(!isset($frm_tid)) $frm_tid="1900000107".date('Ymd').time();
	if(!isset($frm_billno)) $frm_billno="0000000001";
	if(!isset($frm_refund_fee)) $frm_refund_fee="0";
	if(!isset($frm_refund_cnt)) $frm_refund_cnt="1";
	if(!isset($frm_refundid)) $frm_refundid=sprintf("1091900000107%s%07d",date('Ymd'),time()%10000000);;
?>
<form id="frm" action="/Pay/split_refund_4_1.php">
	<fieldset ><legend>支付信息</legend>
		<label>供应商</label><input name="spid" value="<? echo $frm_spid; ?>"><br>
		<label>财付通交易单号</label><input name="tid" value="<? echo $frm_tid; ?>"><br>
		<label>商户交易单号</label><input name="billno" value="<? echo $frm_billno; ?>"><br>
		<label>订单金额</label><input name="fee" value="<? echo $frm_fee; ?>"><br>
		<label>版  本</label><input name="ver" value="<? echo $frm_ver; ?>"><br>
	</fieldset>
	<fieldset ><legend>分账信息</legend>
		<label>退款总额</label><input name="refund_fee" value="<? echo $frm_refund_fee; ?>"><br>
		<label>退票张数</label><input name="refund_cnt" value="<? echo $frm_refund_cnt; ?>"><br>
		<label>退款单号</label><input name="refundid" value="<? echo $frm_refundid; ?>"><br>
		<label>类型</label><input name="bus_type" value="<? echo $frm_bus_type; ?>" onchange="javascript:autoFill();"><br>
		<label>参数</label><input name="bus_args" value="<? echo $frm_bus_args; ?>"><br>
	</fieldset>
		<label></label><input type="submit" value="下一步"><br>
</form>

	</div>
		<!-- -->
	<div class="Foot">
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved 原创软件 版权所有 <br />
					备案序号：粤ICP备08019531号
	</div>	

</div><!-- Body -->
</body>
</html>