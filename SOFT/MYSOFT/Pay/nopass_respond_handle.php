<?php
	//委托代扣接收
	//1202952101/8fef4ff29cab34775c2c4c62374b5297 ;
	//trust_uin.xml
	import_request_variables("gp","frm_");
	

	$reqstr = "<rec cmdno='".$cmdno."' spid='".$spid."' uin='".$uin."' status='".$status."' cftsign='".$cftsign."' time='".time()."' ></rec>\r\n";
	
	
	
	$filename = "/webhome/h188709/web/www/Log/trust_uin.xml";
	
	$handle = fopen($filename, "a+");
	flock($handle,LOCK_EX);
	fwrite($handle, $reqstr);
	flock($handle,LOCK_UN);
	fclose($handle);			
?>