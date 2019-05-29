//选中字体的颜色
var tpressedFontColor = "#f00";
//图片目录路径
var tpathPrefix_img = "Img/";
//菜单缩进像素
var tlevelDX = 2;
//选中切换模式
var ttoggleMode = 1;
//模式是否展开
var texpanded = 0;
var tcloseExpanded   = 0;
var tcloseExpandedXP = 0;

var tblankImage      = "Img/blank.gif";
//菜单宽度
var tmenuWidth       = "190px";
var tmenuHeight      = "auto";

var tabsolute        = 1;
var tleft            = 0;
var ttop             = 120;

var tfloatable       = 0;
var tfloatIterations = 10;

var tmoveable        = 0;
var tmoveImage       = "Img/movepic.gif";
var tmoveImageHeight = 12;

var tfontStyle       = "normal 9pt 宋体";
var tfontColor       = ["#215DC6","#428EFF"];
var tfontDecoration  = ["none","underline"];

var titemBackColor   = ["#D6DFF7","#D6DFF7"];
var titemAlign       = "left";
var titemBackImage   = ["blank.gif","blank.gif"];
var titemCursor      = "pointer";
var titemHeight      = 22;
var titemTarget      = "content";

var ticonWidth       = 21;
var ticonHeight      = 15;
var ticonAlign       = "left";

var tmenuBackImage   = "blank.gif";
var tmenuBackColor   = "";
var tmenuBorderColor = "#FFFFFF";
var tmenuBorderStyle = "solid";
var tmenuBorderWidth = 0;

var texpandBtn       =["expandbtn2.gif","expandbtn2.gif","collapsebtn2.gif"];
var texpandBtnW      = 9;
var texpandBtnH      = 9;
var texpandBtnAlign  = "left"

var tpoints       = 0;
var tpointsImage  = "";
var tpointsVImage = "";
var tpointsCImage = "";

// XP-Style Parameters
var tXPStyle = 1;
var tXPIterations = 5;                  // expand/collapse speed
var tXPTitleBackColor    = "#265BCC";
var tXPExpandBtn    = ["xpexpand1.gif","xpexpand2.gif","xpcollapse1.gif","xpcollapse2.gif"];
var tXPTitleBackImg = "xptitle.gif";

var tXPTitleLeft      = "xptitleleft.gif";
var tXPTitleLeftWidth = 4;

var tXPBtnWidth  = 25;
var tXPBtnHeight = 25;

var tXPIconWidth  = 31;
var tXPIconHeight = 32;

var tXPFilter=1;

var tXPBorderWidth = 1;
var tXPBorderColor = '#FFFFFF';



var tstyles =
[
    ["tfontStyle=bold 9pt Tahoma","titemBackColor=#265BCC,#265BCC","tfontColor=#FFFFFF,#428EFF", "tfontDecoration=none,none"],
    ["tfontStyle=bold 9pt Tahoma","titemBackColor=#265BCC,#265BCC","tfontColor=#215DC6,#428EFF", "tfontDecoration=none,none"],
    ["tfontDecoration=none,none"],
    ["tfontStyle=bold 9pt Tahoma","tfontColor=#444444,#5555FF"],
];

var tXPStyles =
[
    ["tXPTitleBackColor=#D0DAF8", "tXPExpandBtn=xpexpand3.gif,xpexpand4.gif,xpcollapse3.gif,xpcollapse4.gif", "tXPTitleBackImg=xptitle2.gif"]
];

var tmenuItems =
[
    ["My-Soft", "", "","","", "展开/收起此栏目",,"1","0"],
        ["|规则介绍", "", "", ""],
            ["||软件颁发流程", "http://www.my-soft.net.cn/Frame/deploy.htm", "iconarr.gif"],     
            ["||软件验证流程", "http://www.my-soft.net.cn/Frame/validate.htm", "iconarr.gif"],    
            ["||验证My-Soft软件包", "http://www.my-soft.net.cn/Frame/validate_my-soft.htm", "iconarr.gif"],          
        ["|参数与工具", "", "", ""],            
            ["||开发者证书", "http://www.my-soft.net.cn/Frame/developercert.htm", "iconarr.gif"],
            ["||根证书", "http://www.my-soft.net.cn/Frame/rootcert.htm", "iconarr.gif"],
            ["||验证工具", "http://www.my-soft.net.cn/Frame/softcheck.htm", "iconarr.gif"],
            
    ["财付通直通车", "", "","","", "展开/收起此栏目",,"1","0"],  
				["|业务介绍", "Product/ZTC/intro.htm", "iconarr.gif", ""],
				["|设置参数", "Product/ZTC/setting.htm", "iconarr.gif", ""],
				["|销售腾讯业务", "Product/ZTC/sale.htm", "iconarr.gif", ""],
				["|查看销售日志", "Product/ZTC/log.htm", "iconarr.gif", ""],
	
    ["测试", "", "","","", "展开/收起此栏目",,"1","0"],  
				["|JS异步调用COM方法", "Product/TEST/js_call_com.htm", "iconarr.gif", ""],
				
    ["+航空机票", "", "","","", "展开/收起此栏目",,"1","0"],  
    	["|终端用户","","", ""],
		["||立即查询", "Product/AIRLINE/Results.html", "iconarr.gif", ""],
    	["|代理人","","", ""],
		["||登陆", "Product/AIRLINE_B2B/Login.html", "iconarr.gif", ""],
		["||PNR入库", "Product/AIRLINE_B2B/PNR.html", "iconarr.gif", ""],
		

	["+mch.tenpay.com", "", "","","", "展开/收起此栏目",,"1","0"],  
		["|财付通自动付款接口", "", "", ""],  
			["||介绍", "Product/AUTOPAY/help.ppt", "iconarr.gif", ""],  
			["||演示", "Product/AUTOPAY/auto_pay_only.htm", "iconarr.gif", ""],  
			["||集成Md5支付请求的演示", "Product/AUTOPAY/auto_pay.htm", "iconarr.gif", ""],  
		["|财付通分账退款接口", "", "", ""],  
			["||分账退款演示", "Product/SPLIT/split_refund.htm", "iconarr.gif", ""],  
			["||订单查询演示", "Product/SPLIT/split_inquire.htm", "iconarr.gif", ""],  
	["+www.tenpay.com", "", "","","", "展开/收起此栏目",,"1","0"],  
		["|财付通B2C支付接口MD5", "", "", ""],  
			["||集成", "Product/B2C/b2c_pay_md5.htm", "iconarr.gif", ""],  
	["+相关加密与编码工具", "", "","","", "展开/收起此栏目",,"1","0"],  
		["|MD5", "Product/EN_DE_TOOL/md5.htm", "iconarr.gif", ""],    
		["|UrlEncode", "Product/EN_DE_TOOL/urlencode.htm", "iconarr.gif", ""],  
		["|RSA", "Product/EN_DE_TOOL/rsa.htm", "iconarr.gif", ""],  
	
	["关于我们", "", "","","", "展开/收起此栏目",,"1","0"],  
		["|我们的目标", "http://www.my-soft.net.cn/Frame/idea.html", "iconarr.gif"],
		["|联系我们", "http://www.my-soft.net.cn/Frame/contact.html", "iconarr.gif"],
      
];

dtree_init();
