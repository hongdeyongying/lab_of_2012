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

	import_request_variables("gpc","frm_");
	
	
	if(!isset($frm_protcol)) $frm_protcol="SSL"; 
	if(!isset($frm_host)) $frm_host="mch.tenpay.com"; 
	if(!isset($frm_port)) $frm_port=443;
	if(!isset($frm_path)) $frm_path="/cgi-bin/mchbatchtransfer.cgi";
	
	
	if(!isset($frm_op_code)) $frm_op_code=1002;
	if(!isset($frm_op_name)) $frm_op_name="real_settlement";
	if(!isset($frm_op_user)) $frm_op_user="1202952101";
	if(!isset($frm_op_passwd)) $frm_op_passwd="111111";
	if(!isset($frm_op_time)) $frm_op_time="20080624131300000";
	if(!isset($frm_sp_id)) $frm_sp_id="1202952101";
	if(!isset($frm_package_id)) $frm_package_id="1";
	if(!isset($frm_trans_id)) $frm_trans_id="1202952101200806201213960340";
	
	if(!isset($frm_total_amt)) $frm_total_amt="1";
	if(!isset($frm_total_num)) $frm_total_num="1";
	if(!isset($frm_client_ip)) $frm_client_ip="192.168.0.102";
	
	if(!isset($frm_rec_acc)) $frm_rec_acc="7457222";
	if(!isset($frm_cur_type)) $frm_cur_type="1";
	if(!isset($frm_pay_amt)) $frm_pay_amt="1";
	if(!isset($frm_desc)) $frm_desc="测试用";
	?>
	
	<form action="/Pay/aft_split.php">
		<fieldset value="123">
		<label>op_code</label><input name="op_code" value="<? echo $frm_op_code; ?>"><br>
		<label>op_name</label><input name="op_name" value="<? echo $frm_op_name; ?>"><br>
		<label>op_user</label><input name="op_user" value="<? echo $frm_op_user; ?>"><br>
		<label>op_passwd</label><input name="op_passwd" value="<? echo $frm_op_passwd; ?>"><br>
		<label>op_time</label><input name="op_time" value="<? echo $frm_op_time; ?>"><br>
		<label>sp_id</label><input name="sp_id" value="<? echo $frm_sp_id; ?>"><br>
		<label>package_id</label><input name="package_id" value="<? echo $frm_package_id; ?>"><br>
		<label>tras_id</label><input name="trans_id" value="<? echo $frm_trans_id; ?>"><br>
		<label>total_amt</label><input name="total_amt" value="<? echo $frm_total_amt; ?>"><br>
		<label>total_num</label><input name="total_num" value="<? echo $frm_total_num; ?>"><br>
		<label>client_ip</label><input name="client_ip" value="<? echo $frm_client_ip; ?>"><br>
		
		<label>rec_acc</label><input name="rec_acc" value="<? echo $frm_rec_acc; ?>"><br>
		<label>cur_type</label><input name="cur_type" value="<? echo $frm_cur_type; ?>"><br>
		<label>pay_amt</label><input name="pay_amt" value="<? echo $frm_pay_amt; ?>"><br>
		<label>desc</label><input name="desc" value="<? echo $frm_desc; ?>"><br>
		
		
		<label></label><input type="submit" value="确认以上信息"><br>
	</fieldset>
	</form>
	
<?php
	//echo phpversion();
	
	if((!isset($frm_Content)) && (!isset($frm_abstract)))
	{
		if($frm_sp_id == "1202952101")
			$strKey = "8fef4ff29cab34775c2c4c62374b5297";		
		else
			$strKey = "123456";
		
		$strContent  =  $frm_trans_id . $frm_sp_id . $frm_rec_acc . $frm_pay_amt . $strKey;
		$strMd5Sign  =  (md5($strContent));
		
		$strLstCont  =  "<?xml version=\"1.0\" encoding = \"GB2312\"?>".
										"\r\n\r\n<root>".
										"\r\n	<op_code>".$frm_op_code."</op_code>".										
										"\r\n	<op_name>".$frm_op_name."</op_name>".
										"\r\n	<op_user>".$frm_op_user."</op_user>".
										"\r\n	<op_passwd>".$frm_op_passwd."</op_passwd>".
										"\r\n	<op_time>".$frm_op_time."</op_time>".
										"\r\n	<sp_id>".$frm_sp_id."</sp_id>".
										"\r\n	<package_id>".$frm_package_id."</package_id>".
										"\r\n	<trans_id>".$frm_trans_id."</trans_id>".
										"\r\n	<total_amt>".$frm_total_amt."</total_amt>".
										"\r\n	<total_num>".$frm_total_num."</total_num>".
										"\r\n	<client_ip>".$frm_client_ip."</client_ip>".
										"\r\n	<record_set>".
										"\r\n		<record>".
										"\r\n			<rec_acc>".$frm_rec_acc."</rec_acc>".
										"\r\n			<cur_type>".$frm_cur_type."</cur_type>".
										"\r\n			<pay_amt>".$frm_pay_amt."</pay_amt>	".
										"\r\n			<desc>".$frm_desc."</desc>".
										"\r\n		</record>".
										"\r\n	</record_set>".
										"\r\n	<sign>".$strMd5Sign."</sign>".
										"\r\n</root>";
	
		$frm_content = base64_encode($strLstCont);										
		
		$frm_content1 = ($strLstCont);										
		
		$frm_abstract = (md5(md5($frm_content).$strKey));
	}
	
	$frm_content_1 = ereg_replace("=","%3D",$frm_content);
			
			//echo $frm_content_1;
			
			$frm_content_2 = ereg_replace("\+","%2B",$frm_content_1);
	?>
	
	<form method="post" action="/Pay/aft_split.php">
		<label>协议(SSL)</label><input name="protocol" value="<? echo $frm_protcol; ?>"><br>
		<label>服务器IP或者域名</label><input name="host" value="<? echo $frm_host; ?>"><br>
		<label>端口</label><input name="port" value="<? echo $frm_port; ?>"><br>
		<label>路径</label><input name="path" value="<? echo $frm_path; ?>"><br>
		
		<label>摘要</label><input name="abstract" value="<? echo $frm_abstract; ?>"><br>		
		<label>内容</label><textarea name="content"><? echo $frm_content; ?></textarea><br>		
		<label>明文内容</label><textarea name="content1"><? echo $frm_content1; ?></textarea><br>		
	
		<label></label><input type="submit" value="调用财付通实时分账接口">
	</form>
		
		<form target="_blank" method="get" action="https://mch.tenpay.com/cgi-bin/mchbatchtransfer.cgi">
		<input type="hidden" name="abstract" value="<? echo $frm_abstract; ?>">		
		<input type="hidden" name="content" value="<? echo $frm_content; ?>">		
		<input type="submit" value="前台调用财付通实时分账接口">
	</form>
	
	<textarea>
	<?php
	if(isset($frm_protocol)&&($frm_protcol != "")&&isset($frm_content)&&isset($frm_abstract))
	{
			
	?>

<?php
	$timeout 		= 10;
	$context = stream_context_create();
	$result  = stream_context_set_option($context, 'ssl', 'local_cert', "/webhome/h188709/web/www/Pay/Cft/1202952101.crt");
	$result  = stream_context_set_option($context, 'ssl', 'passphrase', "12345");
	$result  = stream_context_set_option($context,'ssl','allow_self_signed',true); 
	$result  = stream_context_set_option($context,'ssl','verify_peer',false); 
//	$result  = stream_context_set_option($context,'ssl','capath',"./1900000666.pem"); 
	$result  = stream_context_set_option($context,'ssl','cafile',"/webhome/h188709/web/www/Pay/Cft/cacert.crt"); 
	
	if($frm_protocol =="SSL")
	{
		echo "stream_socket_client:".$frm_host." ".$frm_port."\r\n";
		$fp = stream_socket_client("ssl://".$frm_host.":".$frm_port,$errno,$errstr,$timeout,STREAM_CLIENT_CONNECT,$context);
	}
	else
	{
		echo "fsockopen:".$frm_host." ".$frm_port."\r\n";
		$fp = fsockopen($frm_host,$frm_port,$errno,$errstr,$timeout);
	}
	
	
	if (!$fp) 
	{
	    echo "$errstr ($errno)<br />\n";
	} 
	else 
	{
			//$trans = array("=" => "%3D", "+" => "%2B");
			//echo strtr("hi all, I said hello", $trans);
			
			//$frm_content_1 = strstr($frm_content,$trans);
			
			$frm_content_1 = ereg_replace("=","%3D",$frm_content);
			
			//echo $frm_content_1;
			
			$frm_content_2 = ereg_replace("\+","%2B",$frm_content_1);
			
			//echo $frm_content_2;
			
	    $out = "GET ".$frm_path."?content=".$frm_content_2."&abstract=".$frm_abstract." HTTP/1.1\r\n";
	    $out .= "Host: ".$frm_host."\r\n";
	    $out .= "Connection: Close\r\n\r\n";
	
			echo $out."[]\r\n";
	    fwrite($fp, $out);
	    while (!feof($fp)) 
	    {
	        echo fgets($fp, 128);
	    }
	    fclose($fp);
	}
?>
<?php
}
?>
</textarea>
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
