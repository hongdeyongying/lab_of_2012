<?php
	import_request_variables("gp","frm_");
	import_request_variables("c","ck_");
	
	$filename = '/webhome/h188709/web/www/License/'.$frm_uin.'/'.$frm_acd.'/'.$frm_net.$frm_stg.'.xml';
	$filename_test = '/webhome/h188709/web/www/License/test.xml';

	$log = fopen("/webhome/h188709/web/www/License/apply_log.txt", 'a');
	if (!file_exists($filename)) 
	{
	    $filename = $filename_test;
	    
	    $cnt  = strftime("%b %d %Y %X", time());
	    $cnt .= " vno: ".$frm_vno;
	    $cnt .= " uin:".$frm_uin;
	    $cnt .= " acd:".$frm_acd;
	    $cnt .= " net:".$frm_net;
	    $cnt .= " stg:".$frm_stg;
	    $cnt .= " sgn:".$frm_sgn;
	    $cnt .= "\r\n";
	    
	    fwrite($log, $cnt); 
	    
	} 
	fclose($log);
	
	$fp = fopen($filename, 'r');

	header("Content-Type: application/xml");
	header("Content-Length: " . filesize($name));
	
	fpassthru($fp);

	fclose($fp);
	
?>
