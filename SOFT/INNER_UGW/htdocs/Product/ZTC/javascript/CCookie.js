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
	var exp = new Date(); 
	exp.setTime (exp.getTime() - 1); 

    if (getCookie(name)) {
        document.cookie = name + "=" +
            ((path) ? "; path=" + path : "") +
            ((domain) ? "; domain=" + domain : "") +
            "; expires="+exp.toGMTString();
    }
}

/*
 * 定义全局变量g_CCookie
 */
var g_CCookie =null ;
if(!g_CCookie)
	g_CCookie = new CCookie();