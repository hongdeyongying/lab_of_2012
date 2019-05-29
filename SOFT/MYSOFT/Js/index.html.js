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
[/*
	["磁条卡支付", "", "","","", "展开/收起此栏目",,"1","0"],
        ["|商场收银系统", "./url", "", ""],
            ["||银联POS", "testlink.htm", "iconarr.gif"],
            ["||MIS POS", "testlink.htm", "iconarr.gif"],
            ["||收银机", "testlink.htm", "iconarr.gif"],
        ["|便利店充值系统", "./url", "", ""],
            ["||PSTN终端", "testlink.htm", "iconarr.gif"],
            ["||CTSI终端", "testlink.htm", "iconarr.gif"],
            ["||ADSL终端", "testlink.htm", "iconarr.gif"],
            ["||GPRS终端", "testlink.htm", "iconarr.gif"],
        ["|多媒体终端", "./url", "", ""],
            ["||PSTN终端", "testlink.htm", "iconarr.gif"],
            ["||CTSI终端", "testlink.htm", "iconarr.gif"],
            ["||ADSL终端", "testlink.htm", "iconarr.gif"],
            ["||GPRS终端", "testlink.htm", "iconarr.gif"],
        
	["在线支付", "", "","","", "展开/收起此栏目",,"1","0"],
        ["|财付通B2C支付接口示例", "./url", "", ""],
            ["||普通，版本1", "testlink.htm", "iconarr.gif"],
            ["||代理商,版本3", "testlink.htm", "iconarr.gif"],
            ["||带分账,版本4", "testlink.htm", "iconarr.gif"],
            ["||委托代扣,版本4", "testlink.htm", "iconarr.gif"],
        ["|财付通订单查询接口", "", "", ""],            
            ["||普通,版本1", "testlink.htm", "iconarr.gif"],
            ["||代理商,版本2", "testlink.htm", "iconarr.gif"],
            ["||分账请求，版本4", "testlink.htm", "iconarr.gif"],
            ["||分账结果，版本4", "testlink.htm", "iconarr.gif"],
        ["|财付通分账接口", "", "", ""],            
            ["||老版本分账，1", "testlink.htm", "iconarr.gif"],
            ["||新版本分账，4", "testlink.htm", "iconarr.gif"],
            ["||分账退款，4", "testlink.htm", "iconarr.gif"],
            ["||老版本分账退款，1", "testlink.htm", "iconarr.gif"],
        ["|财付通其他功能", "", "", ""],            
            ["||商户号实时申请", "testlink.htm", "iconarr.gif"],
            ["||QQ消息通知", "testlink.htm", "iconarr.gif"],
			["||用户信息验证", "testlink.htm", "iconarr.gif"],
			["||签署委托代扣", "testlink.htm", "iconarr.gif"],
			["||委托代扣扣款，版本1", "testlink.htm", "iconarr.gif"],
            
	["网络工具", "", "","","", "展开/收起此栏目",,"1","0"],
        ["|下载工具", "", "", ""],
            ["||my下载器", "testlink.htm", "iconarr.gif"],            
        ["|网络安全", "", "", ""],            
            ["||my防火墙", "mailto:gaussgao@tencent.com", "iconarr.gif"],
            ["||my监视器", "mailto:gaussgao@tencent.com", "iconarr.gif"],      */
    ["My-Soft", "", "","","", "展开/收起此栏目",,"1","0"],
        ["|规则介绍", "", "", ""],
            ["||软件颁发流程", "Frame/deploy.htm", "iconarr.gif"],     
            ["||软件验证流程", "Frame/validate.htm", "iconarr.gif"],    
            ["||验证My-Soft软件包", "Frame/validate_my-soft.htm", "iconarr.gif"],          
        ["|参数与工具", "", "", ""],            
            ["||开发者证书", "Frame/developercert.htm", "iconarr.gif"],
            ["||根证书", "Frame/rootcert.htm", "iconarr.gif"],
            ["||验证工具", "Frame/softcheck.htm", "iconarr.gif"],
            
    ["+我的软件", "", "","","", "展开/收起此栏目",,"1","0"],  
				["|航空客票", "", "", ""],
					["||海航客户端", "Product/hnair_b2b_client.htm", "iconarr.gif", ""],  
				["|仓库管理系统", "", "", ""],
					["||仓库盘点系统", "Product/stock_check.htm", "iconarr.gif", ""],    
 /*   
	["工具下载", "Frame/index_download.html", "","","", "展开/收起此栏目",,"1","0"],  
		["|Access文件解密", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		["|Openssl实现Ssl的DEMO", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		["|Crypto的证书管理DEMO", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		["|按揭计算器", "", "iconarr.gif", ""],            
        ["|文本文件排序", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		["|PSAM发卡DEMO", "", "iconarr.gif", ""],            
        ["|绘图函数库DEMO", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		*/
	["资料下载", "", "","","", "展开/收起此栏目",,"1","0"],      
		["|GNU编译工具", "", "", ""],            
	        ["||Automake", "Download/gnu_autoconf.7z", "iconarr.gif"],
			["||Autoconf", "Download/gnu_automake.7z", "iconarr.gif"],
		["|WEB服务器", "", "", ""],            
	        ["||Apache的配置优化", "Download/apache224_ssl.7z", "iconarr.gif"],
		["|加密解密", "", "", ""],            
	        ["||Openssl", "Download/openssl_ca_crt.zip", "iconarr.gif"],
			/*["||Crypto", "mailto:gaussgao@tencent.com", "iconarr.gif"], */
	["+关于我们", "", "","","", "展开/收起此栏目",,"1","0"],  
		["|我们的目标", "Frame/idea.html", "iconarr.gif"],
		["|联系我们", "Frame/contact.html", "iconarr.gif"],
//		["|在线留言", "http://user.qzone.qq.com/372132908", "iconarr.gif"],
	
      
];

dtree_init();
