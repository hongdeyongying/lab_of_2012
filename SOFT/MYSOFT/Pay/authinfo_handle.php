<html>
	<head>
		<TITLE>My-Soft,ԭ�����������������������������������</TITLE>
		<meta http-equiv="pragma" content="no-cache" />
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
		<meta name="description" content="��My-Soft�����������������������������!" />
		<meta name="keywords" content="My-Soft,����,ԭ������,������������,��������������������������󣬷��������������ߣ������ߣ�����Ա��ֱͨ��" />
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
					��ҳ</li>			<li class="NavSplit"> </li>
				<li class="SeleBtn"
					onmouseover="this.className='SeleBtnFocus';" 
					onMouseOut="this.className='SeleBtn';"
					onclick="javascript:document.location.href='/myDownloader/';"
					>���ع���</li>			<li class="NavSplit"> </li>
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
					onclick="javascript:window.external.AddFavorite('http://www.my-soft.net.cn','My-Soft,����ǡ��������')"
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
			echo "<label>��֤ͨ��</label><br>";
		}
		else
		{
			echo "<label>��֤ʧ��</label><br>";
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
  
  //ȡǩ������key	
  if($frm_spid == "1200062401")      
    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*�̻���Կ,����ʱ��Ϊ�̻���,��ʽ���ߺ����޸�*/
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
		ExitWithInfo(1,"ȡǩ���̻�keyʧ��");
  	
  }
  	
  /*����ֵ����*/
  $iRetOK       = 0;		// �ɹ�					
  $iInvalidSpid = 1;		// �̻��Ŵ���
  $iInvalidSign = 2;		// ǩ������
  $iTenpayErr	  = 3;		// �Ƹ�ͨ����֧��ʧ��

  /*��ǩ*/
  
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
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved ԭ������ ��Ȩ���� <br />
					������ţ���ICP��08019531��
	</div>	

</div><!-- Body -->
</body>
</html>