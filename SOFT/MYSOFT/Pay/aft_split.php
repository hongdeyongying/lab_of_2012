<html>
	<head>
		<TITLE>My-Soft,ԭ������������������������������</TITLE>
		<meta http-equiv="pragma" content="no-cache" />
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
		<meta name="description" content="��My-Soft�������������������������!" />
		<meta name="keywords" content="My-Soft,���,ԭ�����,���������,������������������������󣬷�������������ߣ������ߣ�����Ա��ֱͨ��" />
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
					��ҳ</li>			<li class="NavSplit"> </li>
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
					
					>����֧��</li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"
					onclick="javascript:window.external.AddFavorite('http://www.my-soft.net.cn','My-Soft,���ǡ��������')"
					>�ղر�վ</li>					<li class="NavSplit"> </li>
			</ul>
		</div>
	</div>

	<div class="Welcome" >
		
		<p>&nbsp;&nbsp;&nbsp;&nbsp;����֧����˾Ϊ���������ṩ���ʽ���ת�ı�����������һ������֧����˾������֧��ȫ����������е����������󷽱������Ӫ��
			ƽ̨���ر�������ṩ�˱����У������ȴ�ͳ���ڻ�����ƽ�׽��˵ķ��񣬸��ӿ��ţ������������ܹ����ٸ�����Ը���������Ӧ�ó�����֧���������ŵ�����֧
			��ƽ̨����һ���ḻ�ճ������е�֧���ֶΣ�������֧�������㣡
		</P>
		
		<p>&nbsp;&nbsp;&nbsp;&nbsp;�������ʹ����Ѷ�Ƹ�ͨ�����ṩ�ĸ��ֹ��ܵ�ʵ��ʾ���������������������Ӧ�ó�������Ҫ��
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
	if(!isset($frm_desc)) $frm_desc="������";
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
		
		
		<label></label><input type="submit" value="ȷ��������Ϣ"><br>
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
		<label>Э��(SSL)</label><input name="protocol" value="<? echo $frm_protcol; ?>"><br>
		<label>������IP��������</label><input name="host" value="<? echo $frm_host; ?>"><br>
		<label>�˿�</label><input name="port" value="<? echo $frm_port; ?>"><br>
		<label>·��</label><input name="path" value="<? echo $frm_path; ?>"><br>
		
		<label>ժҪ</label><input name="abstract" value="<? echo $frm_abstract; ?>"><br>		
		<label>����</label><textarea name="content"><? echo $frm_content; ?></textarea><br>		
		<label>��������</label><textarea name="content1"><? echo $frm_content1; ?></textarea><br>		
	
		<label></label><input type="submit" value="���òƸ�ͨʵʱ���˽ӿ�">
	</form>
		
		<form target="_blank" method="get" action="https://mch.tenpay.com/cgi-bin/mchbatchtransfer.cgi">
		<input type="hidden" name="abstract" value="<? echo $frm_abstract; ?>">		
		<input type="hidden" name="content" value="<? echo $frm_content; ?>">		
		<input type="submit" value="ǰ̨���òƸ�ͨʵʱ���˽ӿ�">
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
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved ԭ����� ��Ȩ���� <br />
					������ţ���ICP��08019531��
	</div>	-->

</div><!-- Body -->
</body>
</html>
