/*************************************************
 * md5相关处理函数
 *************************************************/
var hexcase = 1;
var b64pad = "";
var chrsz = 8;
var mode = 32;

function preprocess(form)
{
  var str = "";
  str += form.verifycode.value;
  str = str.toUpperCase();
  form.p.value = md5(md5_3(form.p.value)+str);
  return true;
}

function md5_3(s)
{
  var tmp = new Array;
  tmp = core_md5(str2binl(s), s.length * chrsz);
  tmp = core_md5(tmp, 16 * chrsz);
  tmp = core_md5(tmp, 16 * chrsz);
  return binl2hex(tmp);
}

function md5(s)
{
  return hex_md5(s);
}
function hex_md5(s)
{
  return binl2hex(core_md5(str2binl(s), s.length * chrsz));
}

function b64_md5(s)
{
  return binl2b64(core_md5(str2binl(s), s.length * chrsz));
}

function str_md5(s)
{
  return binl2str(core_md5(str2binl(s), s.length * chrsz));
}

function hex_hmac_md5(key, data)
{
  return binl2hex(core_hmac_md5(key, data));
}

function b64_hmac_md5(key, data)
{
  return binl2b64(core_hmac_md5(key, data));
}

function str_hmac_md5(key, data)
{
  return binl2str(core_hmac_md5(key, data));
}

function md5_vm_test()
{
  return hex_md5("abc") == "900150983cd24fb0d6963f7d28e17f72";
}

function core_md5(x, len)
{
  x[len >> 5] |= 0x80 << ((len) % 32);
  x[(((len + 64) >>> 9) << 4) + 14] = len;

  var a = 1732584193;
  var b =  - 271733879;
  var c =  - 1732584194;
  var d = 271733878;

  for (var i = 0; i < x.length; i += 16)
  {
    var olda = a;
    var oldb = b;
    var oldc = c;
    var oldd = d;

    a = md5_ff(a, b, c, d, x[i + 0], 7,  - 680876936);
    d = md5_ff(d, a, b, c, x[i + 1], 12,  - 389564586);
    c = md5_ff(c, d, a, b, x[i + 2], 17, 606105819);
    b = md5_ff(b, c, d, a, x[i + 3], 22,  - 1044525330);
    a = md5_ff(a, b, c, d, x[i + 4], 7,  - 176418897);
    d = md5_ff(d, a, b, c, x[i + 5], 12, 1200080426);
    c = md5_ff(c, d, a, b, x[i + 6], 17,  - 1473231341);
    b = md5_ff(b, c, d, a, x[i + 7], 22,  - 45705983);
    a = md5_ff(a, b, c, d, x[i + 8], 7, 1770035416);
    d = md5_ff(d, a, b, c, x[i + 9], 12,  - 1958414417);
    c = md5_ff(c, d, a, b, x[i + 10], 17,  - 42063);
    b = md5_ff(b, c, d, a, x[i + 11], 22,  - 1990404162);
    a = md5_ff(a, b, c, d, x[i + 12], 7, 1804603682);
    d = md5_ff(d, a, b, c, x[i + 13], 12,  - 40341101);
    c = md5_ff(c, d, a, b, x[i + 14], 17,  - 1502002290);
    b = md5_ff(b, c, d, a, x[i + 15], 22, 1236535329);

    a = md5_gg(a, b, c, d, x[i + 1], 5,  - 165796510);
    d = md5_gg(d, a, b, c, x[i + 6], 9,  - 1069501632);
    c = md5_gg(c, d, a, b, x[i + 11], 14, 643717713);
    b = md5_gg(b, c, d, a, x[i + 0], 20,  - 373897302);
    a = md5_gg(a, b, c, d, x[i + 5], 5,  - 701558691);
    d = md5_gg(d, a, b, c, x[i + 10], 9, 38016083);
    c = md5_gg(c, d, a, b, x[i + 15], 14,  - 660478335);
    b = md5_gg(b, c, d, a, x[i + 4], 20,  - 405537848);
    a = md5_gg(a, b, c, d, x[i + 9], 5, 568446438);
    d = md5_gg(d, a, b, c, x[i + 14], 9,  - 1019803690);
    c = md5_gg(c, d, a, b, x[i + 3], 14,  - 187363961);
    b = md5_gg(b, c, d, a, x[i + 8], 20, 1163531501);
    a = md5_gg(a, b, c, d, x[i + 13], 5,  - 1444681467);
    d = md5_gg(d, a, b, c, x[i + 2], 9,  - 51403784);
    c = md5_gg(c, d, a, b, x[i + 7], 14, 1735328473);
    b = md5_gg(b, c, d, a, x[i + 12], 20,  - 1926607734);

    a = md5_hh(a, b, c, d, x[i + 5], 4,  - 378558);
    d = md5_hh(d, a, b, c, x[i + 8], 11,  - 2022574463);
    c = md5_hh(c, d, a, b, x[i + 11], 16, 1839030562);
    b = md5_hh(b, c, d, a, x[i + 14], 23,  - 35309556);
    a = md5_hh(a, b, c, d, x[i + 1], 4,  - 1530992060);
    d = md5_hh(d, a, b, c, x[i + 4], 11, 1272893353);
    c = md5_hh(c, d, a, b, x[i + 7], 16,  - 155497632);
    b = md5_hh(b, c, d, a, x[i + 10], 23,  - 1094730640);
    a = md5_hh(a, b, c, d, x[i + 13], 4, 681279174);
    d = md5_hh(d, a, b, c, x[i + 0], 11,  - 358537222);
    c = md5_hh(c, d, a, b, x[i + 3], 16,  - 722521979);
    b = md5_hh(b, c, d, a, x[i + 6], 23, 76029189);
    a = md5_hh(a, b, c, d, x[i + 9], 4,  - 640364487);
    d = md5_hh(d, a, b, c, x[i + 12], 11,  - 421815835);
    c = md5_hh(c, d, a, b, x[i + 15], 16, 530742520);
    b = md5_hh(b, c, d, a, x[i + 2], 23,  - 995338651);

    a = md5_ii(a, b, c, d, x[i + 0], 6,  - 198630844);
    d = md5_ii(d, a, b, c, x[i + 7], 10, 1126891415);
    c = md5_ii(c, d, a, b, x[i + 14], 15,  - 1416354905);
    b = md5_ii(b, c, d, a, x[i + 5], 21,  - 57434055);
    a = md5_ii(a, b, c, d, x[i + 12], 6, 1700485571);
    d = md5_ii(d, a, b, c, x[i + 3], 10,  - 1894986606);
    c = md5_ii(c, d, a, b, x[i + 10], 15,  - 1051523);
    b = md5_ii(b, c, d, a, x[i + 1], 21,  - 2054922799);
    a = md5_ii(a, b, c, d, x[i + 8], 6, 1873313359);
    d = md5_ii(d, a, b, c, x[i + 15], 10,  - 30611744);
    c = md5_ii(c, d, a, b, x[i + 6], 15,  - 1560198380);
    b = md5_ii(b, c, d, a, x[i + 13], 21, 1309151649);
    a = md5_ii(a, b, c, d, x[i + 4], 6,  - 145523070);
    d = md5_ii(d, a, b, c, x[i + 11], 10,  - 1120210379);
    c = md5_ii(c, d, a, b, x[i + 2], 15, 718787259);
    b = md5_ii(b, c, d, a, x[i + 9], 21,  - 343485551);

    a = safe_add(a, olda);
    b = safe_add(b, oldb);
    c = safe_add(c, oldc);
    d = safe_add(d, oldd);
  }
  if (mode == 16)
  {
    return Array(b, c);
  }
  else
  {
    return Array(a, b, c, d);
  }
}

function md5_cmn(q, a, b, x, s, t)
{
  return safe_add(bit_rol(safe_add(safe_add(a, q), safe_add(x, t)), s), b);
}

function md5_ff(a, b, c, d, x, s, t)
{
  return md5_cmn((b & c) | ((~b) & d), a, b, x, s, t);
}

function md5_gg(a, b, c, d, x, s, t)
{
  return md5_cmn((b & d) | (c & (~d)), a, b, x, s, t);
}

function md5_hh(a, b, c, d, x, s, t)
{
  return md5_cmn(b ^ c ^ d, a, b, x, s, t);
}

function md5_ii(a, b, c, d, x, s, t)
{
  return md5_cmn(c ^ (b | (~d)), a, b, x, s, t);
}

function core_hmac_md5(key, data)
{
  var bkey = str2binl(key);
  if (bkey.length > 16)
    bkey = core_md5(bkey, key.length * chrsz);

  var ipad = Array(16), opad = Array(16);
  for (var i = 0; i < 16; i++)
  {
    ipad[i] = bkey[i] ^ 0x36363636;
    opad[i] = bkey[i] ^ 0x5C5C5C5C;
  }

  var hash = core_md5(ipad.concat(str2binl(data)), 512+data.length * chrsz);
  return core_md5(opad.concat(hash), 512+128);
}

function safe_add(x, y)
{
  var lsw = (x & 0xFFFF) + (y & 0xFFFF);
  var msw = (x >> 16) + (y >> 16) + (lsw >> 16);
  return (msw << 16) | (lsw & 0xFFFF);
}

function bit_rol(num, cnt)
{
  return (num << cnt) | (num  >>> (32-cnt));
}

function str2binl(str)
{
  var bin = Array();
  var mask = (1 << chrsz) - 1;
  for (var i = 0; i < str.length * chrsz; i += chrsz)
    bin[i >> 5] |= (str.charCodeAt(i / chrsz) & mask) << (i % 32);
  return bin;
}

function binl2str(bin)
{
  var str = "";
  var mask = (1 << chrsz) - 1;
  for (var i = 0; i < bin.length * 32; i += chrsz)
    str += String.fromCharCode((bin[i >> 5] >>> (i % 32)) & mask);
  return str;
}

function binl2hex(binarray)
{
  var hex_tab = hexcase ? "0123456789ABCDEF" : "0123456789abcdef";
  var str = "";

  for (var i = 0; i < binarray.length * 4; i++)
  {
    str += hex_tab.charAt((binarray[i >> 2] >> ((i % 4) * 8+4)) & 0xF) +
      hex_tab.charAt((binarray[i >> 2] >> ((i % 4) * 8)) & 0xF);
  }
  return str;
}

function binl2b64(binarray)
{
  var tab = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  var str = "";
  for (var i = 0; i < binarray.length * 4; i += 3)
  {
    var triplet = (((binarray[i >> 2] >> 8 * (i % 4)) & 0xFF) << 16) | ((
      (binarray[i + 1 >> 2] >> 8 * ((i + 1) % 4)) & 0xFF) << 8) | ((binarray[i
      + 2 >> 2] >> 8 * ((i + 2) % 4)) & 0xFF);
    for (var j = 0; j < 4; j++)
    {
      if (i * 8+j * 6 > binarray.length * 32)
        str += b64pad;
      else
        str += tab.charAt((triplet >> 6 * (3-j)) & 0x3F);
    }
  }
  return str;
}
/*************************************************
 * 财付通COOKIE相关处理函数
 *************************************************/
function CCookie()
{
  this.SetCookie = setCookie;
  this.GetCookie = getCookie;
  this.DelCookie = deleteCookie;
}
function getExpDate(days, hours, minutes) 
{
    var expDate = new Date( );
    if (typeof days == "number" && typeof hours == "number" && 
        typeof hours == "number") 
    {
        expDate.setDate(expDate.getDate( ) + parseInt(days));
        expDate.setHours(expDate.getHours( ) + parseInt(hours));
        expDate.setMinutes(expDate.getMinutes( ) + parseInt(minutes));
        return expDate.toGMTString( );
    }
}
   
// utility function called by getCookie( )
function getCookieVal(offset) 
{
    var endstr = document.cookie.indexOf (";", offset);
    if (endstr == -1) 
    {
        endstr = document.cookie.length;
    }
    return unescape(document.cookie.substring(offset, endstr));
}
   
// primary function to retrieve cookie by name
function getCookie(name) 
{
    var arg = name + "=";
    var alen = arg.length;
    var clen = document.cookie.length;
    var i = 0;
    while (i < clen) 
    {
        var j = i + alen;
        if (document.cookie.substring(i, j) == arg) 
        {
            return getCookieVal(j);
        }
        i = document.cookie.indexOf(" ", i) + 1;
        if (i == 0) break; 
    }
    return "";
}

// store cookie value with optional details as needed
function setCookie(name, value, expires, path, domain, secure) 
{
    document.cookie = name + "=" + escape (value) +
        ((expires) ? "; expires=" + expires : "") +
        ((path) ? "; path=" + path : "") +
        ((domain) ? "; domain=" + domain : "") +
        ((secure) ? "; secure" : "");
}
   
// remove the cookie by setting ancient expiration date
function deleteCookie(name,path,domain) 
{
    if (getCookie(name)) {
        document.cookie = name + "=" +
            ((path) ? "; path=" + path : "") +
            ((domain) ? "; domain=" + domain : "") +
            "; expires=Thu, 01-Jan-70 00:00:01 GMT";
    }
}

/*
 * 定义全局变量g_CCookie
 */
var g_CCookie =null ;
if(!g_CCookie)
	g_CCookie = new CCookie();
/*************************************************
 * 财付通数字证书相关处理函数:使用公司QQCERT控件
 *************************************************/
function CQQCert()
{
  //是否使用QQCERT控件 
  this.m_bUseFlag = true;
  //控件版本
  this.m_sVersion = "1,0,1,1";
  //控件GUID
  this.m_sClassid = "CLSID:BAEA0695-03A4-43BB-8495-C7025E1A8F42";
  //控件路径
  this.m_sLocate = "https://www.tenpay.com/download/qqcert.cab";
  //绘出控件
	this.Draw = CQQCert_Draw;
	this.Import = CQQCert_Import;
	this.FindCrt = CQQCert_FindCrt;
	this.DelCrt = CQQCert_DelCrt;
	this.MakeCSR = CQQCert_MakeCSR;
	this.Sign = CQQCert_Sign;
	this.HostName = CQQCert_HostName;
	this.Version = CQQCert_Version;
	this.Base64Decode = CQQCert_Base64Decode;
	this.Base64Encode = CQQCert_Base64Encode;
	this.IsObjOk = CQQCert_IsObjOk
	this.IsCnExist = CQQCert_IsCnExist;
}

function CQQCert_Draw(idname, other, htmlparentid)
{
  var strObj;
  strObj = "<OBJECT id=\"" + idname + "\" ";
  strObj+= "classid=\"" + this.m_sClassid + "\" ";
  strObj+= " codebase=\"" + this.m_sLocate + "#Version=" + this.m_sVersion + "\" ";
	if(other)
		strObj+=" " + other;
  strObj+= " height=0 width=0></OBJECT>";
  
  if(htmlparentid)
  {
	  var obj=document.getElementById(htmlparentid);
	  obj.innerHTML=strObj;
  }
  else
  {
  document.write(strObj);
  try{
		if(document.getElementById(idname).Version< parseInt(g_CQQCertVersion)){
				document.write("<a href=\"/download/qqcert.exe\"><font style=\"font-size:12px\" color=ff6600>未安装数字证书控件？");
				document.write("请点此安装控件后刷新</a>");
			}
		} catch(er) {}
  }
}

function CQQCert_Import(ctl,crt)
{
	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
	{
		return false;
	}
	var ret,re;
	var cerstr;
//alert(!ctl);
//alert(!crt);
	ret = ctl.ImportCert(crt);
//alert("ret="+ret);
	if(ret==-1)
	{
    return false;
  }
	return true;
}

function CQQCert_FindCrt(ctl,keyvalue, keyname)
{
	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
	{
		return "";
	}

	if(!keyname)
		keyname="SN";

  var cn=ctl.FindCert(keyname, keyvalue);
  if(!cn||cn==null||cn=="")
  {
    return "";
  }
  else
  {
    return cn;
  }
}

function CQQCert_DelCrt(ctl,keyvalue,cn, keyname)
{
    var iRet=-1;
	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
	{
		return false;
	}
	if (!cn)
	{
		cn = GetLocalCert(ctl,keyvalue,keyname);
	}
	if (cn == "")
	{
		return false;
	}
  try
  {
//    iRet = ctl.DelCert(this.FindCrt(ctl,keyvalue, keyname));
    iRet = ctl.DelCert(cn);
  }
  catch(e)
  {
    return false;
  }
  return (iRet==1);
}

function CQQCert_MakeCSR(ctl,subject,uin,sid)
{

	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
	{
		return "";
	}
  var ret,csr;
	ret = ctl.SetChallenge(uin,sid);
	if(ret!=1){
		return "";
	}
	ret = ctl.SetSubject(subject);
	if(ret!=1){
		return "";
	}
	csr = ctl.GetCSR();
	return csr;
}

function CQQCert_Sign(ctl,keyvalue,message,cn,keyname)
{
	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
	{
		return "";
	}
	if (!cn)
	{
		cn = GetLocalCert(ctl,keyvalue,keyname);
	}
	if (cn == "")
	{
		return "";
	}

  return ctl.CertSign(cn,message);
}

function CQQCert_IsCnExist(ctl, cn)
{
	/*
	var str=ctl.CertSign(cn,ctl.Base64Encode("1"));
	if(str && str != "")
		return true;
	else
		return false;
	*/
	var res;
	try
	{	res = ctl.IsCertExist(cn);	}
	catch(e)
	{	res = -1;	}
	if(res == 1)
		return true;
	else
		return false;
}

function CQQCert_HostName(ctl)
{
	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
	{
		return "";
	}
  return ctl.HostName;
}

function CQQCert_Version(ctl)
{
  return ctl.Version;
}

function CQQCert_Base64Encode(ctl,str)
{
	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
	{
		return "";
	}
  return ctl.Base64Encode(str);
}

function CQQCert_Base64Decode(ctl,str)
{
	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
	{
		return "";
	}
  return ctl.Base64Decode(str);
}

function CQQCert_IsObjOk(ctl)
{
	if (!(g_CQQCert.Version(ctl) >= parseInt(g_CQQCertVersion)))
		return false;
	else
		return true;
}

var g_CQQCert = null;
var g_CQQCertVersion = 1011;
if(g_CQQCert == null)
	g_CQQCert = new CQQCert();
 
function WriteCertSignCookie(srcstr)
{	
if (g_CCookie.GetCookie("certuserflag") != "1")
{
	return true;
}
	var QQCertCtrl = window.top.document.getElementById("QQCertCtrl");
	if (!QQCertCtrl)
	{
		return false;
	}
if (!(g_CQQCert.Version(QQCertCtrl) >= parseInt(g_CQQCertVersion)))
{
	if(g_CQQCert.m_bUseFlag)
	{
	}
	return false;
}
//	var cn = g_CQQCert.FindCrt(QQCertCtrl,g_CCookie.GetCookie("qluid"));
	var cn = GetLocalCert(QQCertCtrl,g_CCookie.GetCookie("qluid"));
	if (cn == "")
	{
		top.location.href = "/certificates/tenpay_safe_tips2.shtml";
		return false;
	}
	g_CCookie.SetCookie(
			"cn",
			cn,
			"",
			"/",
			"tenpay.com",
			"");
	var signstr = g_CQQCert.Sign(QQCertCtrl,g_CCookie.GetCookie("qluid"),g_CQQCert.Base64Encode(QQCertCtrl,srcstr));
		g_CCookie.SetCookie(
			"srcstr",
			srcstr,
			"",
			"/",
			"tenpay.com",
			"");
		signstr = encodeURIComponent(signstr);
		g_CCookie.SetCookie(
			"signstr",
			signstr,
			"",
			"/",
			"tenpay.com",
			"");
	return true;
}

function WriteCertSignCookie2(CertCtrlId, iUid, sSrc, sSeq)
{	

	var QQCertCtrl = window.top.document.getElementById(CertCtrlId);
	if (!QQCertCtrl)
		return false;
		
	if (!(g_CQQCert.Version(QQCertCtrl) >= parseInt(g_CQQCertVersion)))
		return false;

//	var cn = g_CQQCert.FindCrt(QQCertCtrl, iUid);
	var cn = GetLocalCert(QQCertCtrl, iUid);
	if (cn == "")
		return false;

	var signstr = g_CQQCert.Sign(QQCertCtrl,iUid,g_CQQCert.Base64Encode(QQCertCtrl, md5(g_CQQCert.Base64Encode(QQCertCtrl,sSeq+sSrc)).toUpperCase()));
	g_CCookie.SetCookie("cn", cn,"","/","tenpay.com","");
	g_CCookie.SetCookie("signseq", sSeq,"","/","tenpay.com","");
	g_CCookie.SetCookie("signstr", signstr,"","/","tenpay.com","");
	return true;
}


function CertStat()
{
	var result = 0;
	if (g_CCookie.GetCookie("certuserflag") == "1")
	{
		result += 1;
	}
	else
	{
		result += 0;
		return result;
	}
	var QQCertCtrl = window.top.document.getElementById("QQCertCtrl");
	if(!QQCertCtrl)
		var QQCertCtrl = document.getElementById("QQCertCtrl");

	if (!QQCertCtrl)
	{
		return result;
	}
	if (g_CQQCert.Version(QQCertCtrl) >= parseInt(g_CQQCertVersion))
	{
		result += 2;
	}
	else
	{
		result += 0;
		return result;
	}
//	var cn = g_CQQCert.FindCrt(QQCertCtrl,g_CCookie.GetCookie("qluid"));
	var cn = GetLocalCert(QQCertCtrl,g_CCookie.GetCookie("qluid"));
	if (cn != "")
	{
		result += 4;
	}
	else
	{
		result += 0;
	}
	return result;
}

function CertUserHasActive()
{
	var result = CertStat();
	if (result == 0)
	{
		return true;
	}
	else if (result == 1)
	{
		return false;
	}
	else if (result == 3 || 7 == result)
	{
		return true;
	}
	else
	{
	// error
		return false;
	}
}

function CertUserHasCert()
{
	var result = CertStat();
	if (result == 0)
	{
		return 0;
	}
	else if (result == 1)
	{
		return 1;
	}
	else if (result == 3)
	{
		return 1;
	}
	else if (7 == result)
	{
		var m_cn = GetLocalCert();
		if (m_cn > 0)
		{
			return 2;
		}
		else
			return 1;
	}
	else
	{
	// error
		return 0;
	}
}

function CertStat_wallet()
{
	var result = 0;
	if ("1" == g_CCftUser.m_sCertuserflag)
	{
		result += 1;
	}
	else
	{
		result += 0;
		return result;
	}
	var QQCertCtrl = window.top.document.getElementById("QQCertCtrl");
	if(!QQCertCtrl)
		var QQCertCtrl = document.getElementById("QQCertCtrl");

	if (!QQCertCtrl)
	{
		return result;
	}
	if (g_CQQCert.Version(QQCertCtrl) >= parseInt(g_CQQCertVersion))
	{
		result += 2;
	}
	else
	{
		result += 0;
		return result;
	}
//	var cn = g_CQQCert.FindCrt(QQCertCtrl,g_CCftUser.m_sInnerid);
	var cn = GetLocalCert(QQCertCtrl,g_CCftUser.m_sInnerid);
	if (cn != "")
	{
		result += 4;
	}
	else
	{
		result += 0;
	}
	return result;
}

function CertUserHasActive_wallet()
{
	var result = CertStat_wallet();
	if (result == 0)
	{
		return true;
	}
	else if (result == 1)
	{
		return false;
	}
	else if (result == 3 || 7 == result)
	{
		return true;
	}
	else
	{
	// error
		return false;
	}
}

function WriteCertSignCookie_wallet(srcstr)
{
	if (g_CCftUser.m_sCertuserflag != "1")
	{
		return true;
	}
	var QQCertCtrl = window.top.document.getElementById("QQCertCtrl");
	if(!QQCertCtrl)
		var QQCertCtrl = document.getElementById("QQCertCtrl");

	if (!QQCertCtrl)
	{
		return false;
	}
if (!(g_CQQCert.Version(QQCertCtrl) >= parseInt(g_CQQCertVersion)))
{
	if(g_CQQCert.m_bUseFlag)
	{
	}
	return false;
}
//	var cn = g_CQQCert.FindCrt(QQCertCtrl,g_CCftUser.m_sInnerid);
	var cn = GetLocalCert(QQCertCtrl,g_CCftUser.m_sInnerid);
	if (cn == "")
	{
		TB_show('','#TB_inline?height=150&width=225&inlineId=div_no_cert&ex=noclick_notitle','');
//		top.location.href = "/certificates/tenpay_safe_tips2.shtml";
		return false;
	}
	g_CCookie.SetCookie(
			"cn",
			cn,
			"",
			"/",
			"tenpay.com",
			"");
	var signstr = g_CQQCert.Sign(QQCertCtrl,g_CCftUser.m_sInnerid,g_CQQCert.Base64Encode(QQCertCtrl,srcstr));
		g_CCookie.SetCookie(
			"srcstr",
			srcstr,
			"",
			"/",
			"tenpay.com",
			"");
		signstr = encodeURIComponent(signstr);
		g_CCookie.SetCookie(
			"signstr",
			signstr,
			"",
			"/",
			"tenpay.com",
			"");
	return true;
}

function CertStat_client()
{
	var result = 0;
	if (g_CCookie.GetCookie("certuserflag") == "1")
	{
		result += 1;
	}
	else
	{
		result += 0;
		return result;
	}
	var QQCertCtrl = window.top.document.getElementById("QQCertCtrl");
	if(!QQCertCtrl)
		QQCertCtrl = document.getElementById("QQCertCtrl");
	if (!QQCertCtrl)
	{
		return result;
	}
	if (g_CQQCert.Version(QQCertCtrl) >= parseInt(g_CQQCertVersion))
	{
		result += 2;
	}
	else
	{
		result += 0;
		return result;
	}
//	var cn = g_CQQCert.FindCrt(QQCertCtrl,g_CCookie.GetCookie("qluid"));
	var cn = GetLocalCert(QQCertCtrl,g_CCookie.GetCookie("qluid"));
	if (cn != "")
	{
		result += 4;
	}
	else
	{
		result += 0;
	}
	return result;
}

function CertUserHasActive_client()
{
	var result = CertStat_client();
	if (result == 0)
	{
		return true;
	}
	else if (result == 1)
	{
		return false;
	}
	else if (result == 3 || 7 == result)
	{
		return true;
	}
	else
	{
	// error
		return false;
	}
}

function WriteCertSignCookie_client(srcstr)
{	
if (g_CCookie.GetCookie("certuserflag") != "1")
{
	return true;
}
	var QQCertCtrl = window.top.document.getElementById("QQCertCtrl");
	if (!QQCertCtrl)
	{
		return false;
	}
if (!(g_CQQCert.Version(QQCertCtrl) >= parseInt(g_CQQCertVersion)))
{
	if(g_CQQCert.m_bUseFlag)
	{
	}
	return false;
}
//	var cn = g_CQQCert.FindCrt(QQCertCtrl,g_CCookie.GetCookie("qluid"));
	var cn = GetLocalCert(QQCertCtrl,g_CCookie.GetCookie("qluid"));
	if (cn == "")
	{
		TB_show('','#TB_inline?height=150&width=225&inlineId=div_no_cert&ex=noclick_notitle','');
//		top.location.href = "/certificates/tenpay_safe_tips2.shtml";
		return false;
	}
	g_CCookie.SetCookie(
			"cn",
			cn,
			"",
			"/",
			"tenpay.com",
			"");
	var signstr = g_CQQCert.Sign(QQCertCtrl,g_CCookie.GetCookie("qluid"),g_CQQCert.Base64Encode(QQCertCtrl,srcstr));
		g_CCookie.SetCookie(
			"srcstr",
			srcstr,
			"",
			"/",
			"tenpay.com",
			"");
		signstr = encodeURIComponent(signstr);
		g_CCookie.SetCookie(
			"signstr",
			signstr,
			"",
			"/",
			"tenpay.com",
			"");
	return true;
}

function GetLocalCert(ctl,innerid,certlist)
{
	
    if (!ctl)
	{
		ctl = document.getElementById("QQCertCtrl");
		if (!ctl)
			ctl = top.document.getElementById("QQCertCtrl");
	}
	if (!innerid)
	{
		innerid = g_CCookie.GetCookie("qluid");
	}
	if (!certlist)
	{
		certlist = g_CCookie.GetCookie("certlist");
	}

	var cns = certlist.split("-");
	var cn;
	var i = 0;
	var flag = -1;

	for (i=0; i<cns.length; i++)
	{
		if (cns[i] == "")
			continue;
		cn = parseInt(cns[i]);
		try
		{
			flag = g_CQQCert.IsCnExist(ctl,cn.toString());
		}
		catch(e)
		{
			flag = -1;
		}
		if (flag == 1)
		{
			// cert exist, get if the cert can be used
			var res= "";
			try
			{
				res = g_CQQCert.Sign(
					ctl,
					innerid,
					g_CQQCert.Base64Encode(ctl,"0123456789abcdef"),
					cn.toString());
			}
			catch(e)
			{
				res = "";
			}
			if (res != "")
			{
				// cert exist, and it can be used  
				return cn;
			}
			else
				// cert can't be used, and it is useless  
				continue;
		}
	}
	return "";
}

