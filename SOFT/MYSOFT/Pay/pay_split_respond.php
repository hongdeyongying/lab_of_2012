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
  /*ȡ���ز���*/
  $strCmdno			= $frm_cmdno;
  $strPayResult		= $frm_pay_result;
  $strPayInfo		= $frm_pay_info;
  $strBillDate		= $frm_date;
  $strBargainorId	= $frm_bargainor_id;
  $strTransactionId	= $frm_transaction_id;
  $strSpBillno		= $frm_sp_billno;
  $strTotalFee		= $frm_total_fee;
  $strFeeType		= $frm_fee_type;
  $strAttach			= $frm_attach;
  $strMd5Sign		= $frm_sign;
  
  $strAgentid = $frm_agentid;
  $strKeyIndex= $frm_key_index;
  
  $strVersion = $frm_version;
  $strBusType = $frm_bus_type;
  $strBusArgs = $frm_bus_args;

	echo  "�汾�ţ�".$strVersion;
  /*���ز���*/
  //�̻�����Ϣ:2000000000/abc12345;2000000501/123456
  //if((!isset($strVersion)) || ($strVersion=="") ||($strVersion < 2) || ($strKeyIdex == 1))
  //{
  	$strSpid = $strBargainorId;
  //}
  if(($strVersion == 3) && ($strKeyIndex == 2))
  {
  	$strSpid = $strAgentid;
  }
  //else
  //	ShowExitMsg("��֧�ֵİ汾��:".$strVersion);
  
  //ȡǩ������key	
  if($strSpid == "1200062401")      
    $strSpkey = "56D554A0B6C3CEDCFF8503DD32818725"; /*�̻���Կ,����ʱ��Ϊ�̻���,��ʽ���ߺ����޸�*/
	else if($strSpid == "2000000000")      
		$strSpkey = "abc12345";
	else if($strSpid == "2000000501")
		$strSpkey = "123456";
	else if($strSpid == "2000001240")
		$strSpkey = "49a3f0d9ac8065342f7a9ca1d208baf7";
	else if($strSpid == "2000001204")
		$strSpkey = "06040350901b89328c085b727a26ee69";
	else if($strSpid == "2100000020")
		$strSpkey = "1234567890123456";
	else if($strSpid == "2000000002")
		$strSpkey = "4554d100495342a6d8854c88ff2d6339";
			else if($strSpid == "1202952101")
				$strSpkey = "8fef4ff29cab34775c2c4c62374b5297";
			else if($strSaler == "1202119401")
				$strSpkey = "comd4f16b4ec3d7aaf082bab5194cfcn";
			else if($strSpid == "1900000107")
				$strSpkey = "82d2f8b9fd7695aec51415ab2900a755";

	else
	{
		echo "<p>δ���õ��̻���</p><br>";
  	echo "����ǩ�����̻�<br><textarea >".$strSpid."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
  	
  }
  	
  /*����ֵ����*/
  $iRetOK       = 0;		// �ɹ�					
  $iInvalidSpid = 1;		// �̻��Ŵ���
  $iInvalidSign = 2;		// ǩ������
  $iTenpayErr	  = 3;		// �Ƹ�ͨ����֧��ʧ��

  /*��ǩ*/
  if((!isset($strVersion)) || ($strVersion=="") ||($strVersion < 2))
  {
	  $strSignText  = "cmdno=" . $strCmdno . "&pay_result=" . $strPayResult . 
			                  "&date=" . $strBillDate . "&transaction_id=" . $strTransactionId .
				                "&sp_billno=" . $strSpBillno . "&total_fee=" . $strTotalFee .
				                "&fee_type=" . $strFeeType . "&attach=" . $strAttach .
				                "&key=" . $strSpkey;
	}
	else if($strVersion == 3)
	{
			$strSignText = 
						genNameVal("agentid",$strAgentid,1).
						genNameVal("attach",$strAttach).
						genNameVal("bargainor_id",$strBargainorId).
						genNameVal("cmdno",$strCmdno).
						genNameVal("date",$strBillDate).
						genNameVal("fee_type",$strFeeType).
						genNameVal("key_index",$strKeyIndex).
						genNameVal("pay_info",$strPayInfo).
						genNameVal("pay_result",$strPayResult).						
						genNameVal("sp_billno",$strSpBillno).
						genNameVal("total_fee",$strTotalFee).
						genNameVal("transaction_id",$strTransactionId).
						genNameVal("ver",$strVersion).
						genNameVal("key",$strSpkey)
						;
	}
	else if($strVersion == 4)
	{
			$strSignText = 
						genNameVal("agentid",$strAgentid,1).
						genNameVal("attach",$strAttach).
						genNameVal("bargainor_id",$strBargainorId).
						genNameVal("bus_args",$strBusArgs).
						genNameVal("bus_type",$strBusType).
						genNameVal("cmdno",$strCmdno).
						genNameVal("date",$strBillDate).
						genNameVal("fee_type",$strFeeType).
						genNameVal("key_index",$strKeyIndex).
						genNameVal("pay_info",$strPayInfo).
						genNameVal("pay_result",$strPayResult).		
						genNameVal("purchaser_id",$frm_purchaser_id).						
						genNameVal("sp_billno",$strSpBillno).
						genNameVal("total_fee",$strTotalFee).
						genNameVal("transaction_id",$strTransactionId).
						genNameVal("version",$strVersion). 
						genNameVal("key",$strSpkey)
						;
	}
	else
	{
		echo "<p>��֧�ֵİ汾</p><br>";
  	echo "֪ͨ����İ汾<br><textarea >".$strVersion."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
	}
		
	$strLocalSign = strtoupper(md5($strSignText));     
  
  if( $strLocalSign  != $strMd5Sign)
  {
  	echo "<p>��֤MD5ǩ��ʧ��</p><br>";
  	echo "֪ͨ�����KEY<br><textarea >".$strMd5Sign."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		
		Exit();
    //ShowExitMsg( "��֤MD5ǩ��ʧ��."); 
  }  
  
  if(( $strSpid != $strBargainorId ) && ($strSpid != $strAgentid))
  {
    echo "<p>�̻��Ŵ���</p><br>";
  	echo "�̻���<br><textarea >".$strBargainorId.":".$strAgentid."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }

  if( $strPayResult != "0" )
  {
    //ShowExitMsg( "֧��ʧ��."); 
    echo "<p>֧��ʧ��</p><br>";
  	echo "֧����ʾ  ��Ϣ<br><textarea >".$strPayInfo."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }
  else
  {
  	echo "<p>֧���ɹ�</p><br>";
  	echo "֧����ʾ  ��Ϣ<br><textarea >".$strPayInfo."</textarea><br>";
  	echo "����ǩ�����ִ�<br><textarea >".$strSignText."</textarea><br>";
		echo "���������ժҪ<br><textarea >".$strLocalSign."</textarea><br>";
		Exit();
  }
  
?>
	</div>
		<!--
	<div class="Foot">
					Copyright&copy; 2007 - 2008 My-Soft All Rights Reserved ԭ����� ��Ȩ���� <br />
					������ţ���ICP��08019531��
	</div>	 -->

</div><!-- Body -->
</body>
</html>