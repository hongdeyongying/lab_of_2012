//ѡ���������ɫ
var tpressedFontColor = "#f00";
//ͼƬĿ¼·��
var tpathPrefix_img = "Img/";
//�˵���������
var tlevelDX = 2;
//ѡ���л�ģʽ
var ttoggleMode = 1;
//ģʽ�Ƿ�չ��
var texpanded = 0;
var tcloseExpanded   = 0;
var tcloseExpandedXP = 0;

var tblankImage      = "Img/blank.gif";
//�˵����
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

var tfontStyle       = "normal 9pt ����";
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
    ["My-Soft", "", "","","", "չ��/�������Ŀ",,"1","0"],
        ["|�������", "", "", ""],
            ["||����䷢����", "http://www.my-soft.net.cn/Frame/deploy.htm", "iconarr.gif"],     
            ["||�����֤����", "http://www.my-soft.net.cn/Frame/validate.htm", "iconarr.gif"],    
            ["||��֤My-Soft�����", "http://www.my-soft.net.cn/Frame/validate_my-soft.htm", "iconarr.gif"],          
        ["|�����빤��", "", "", ""],            
            ["||������֤��", "http://www.my-soft.net.cn/Frame/developercert.htm", "iconarr.gif"],
            ["||��֤��", "http://www.my-soft.net.cn/Frame/rootcert.htm", "iconarr.gif"],
            ["||��֤����", "http://www.my-soft.net.cn/Frame/softcheck.htm", "iconarr.gif"],
            
    ["�Ƹ�ֱͨͨ��", "", "","","", "չ��/�������Ŀ",,"1","0"],  
				["|ҵ�����", "Product/ZTC/intro.htm", "iconarr.gif", ""],
				["|���ò���", "Product/ZTC/setting.htm", "iconarr.gif", ""],
				["|������Ѷҵ��", "Product/ZTC/sale.htm", "iconarr.gif", ""],
				["|�鿴������־", "Product/ZTC/log.htm", "iconarr.gif", ""],
	
    ["����", "", "","","", "չ��/�������Ŀ",,"1","0"],  
				["|JS�첽����COM����", "Product/TEST/js_call_com.htm", "iconarr.gif", ""],
				
    ["+���ջ�Ʊ", "", "","","", "չ��/�������Ŀ",,"1","0"],  
    	["|�ն��û�","","", ""],
		["||������ѯ", "Product/AIRLINE/Results.html", "iconarr.gif", ""],
    	["|������","","", ""],
		["||��½", "Product/AIRLINE_B2B/Login.html", "iconarr.gif", ""],
		["||PNR���", "Product/AIRLINE_B2B/PNR.html", "iconarr.gif", ""],
		

	["+mch.tenpay.com", "", "","","", "չ��/�������Ŀ",,"1","0"],  
		["|�Ƹ�ͨ�Զ�����ӿ�", "", "", ""],  
			["||����", "Product/AUTOPAY/help.ppt", "iconarr.gif", ""],  
			["||��ʾ", "Product/AUTOPAY/auto_pay_only.htm", "iconarr.gif", ""],  
			["||����Md5֧���������ʾ", "Product/AUTOPAY/auto_pay.htm", "iconarr.gif", ""],  
		["|�Ƹ�ͨ�����˿�ӿ�", "", "", ""],  
			["||�����˿���ʾ", "Product/SPLIT/split_refund.htm", "iconarr.gif", ""],  
			["||������ѯ��ʾ", "Product/SPLIT/split_inquire.htm", "iconarr.gif", ""],  
	["+www.tenpay.com", "", "","","", "չ��/�������Ŀ",,"1","0"],  
		["|�Ƹ�ͨB2C֧���ӿ�MD5", "", "", ""],  
			["||����", "Product/B2C/b2c_pay_md5.htm", "iconarr.gif", ""],  
	["+��ؼ�������빤��", "", "","","", "չ��/�������Ŀ",,"1","0"],  
		["|MD5", "Product/EN_DE_TOOL/md5.htm", "iconarr.gif", ""],    
		["|UrlEncode", "Product/EN_DE_TOOL/urlencode.htm", "iconarr.gif", ""],  
		["|RSA", "Product/EN_DE_TOOL/rsa.htm", "iconarr.gif", ""],  
	
	["��������", "", "","","", "չ��/�������Ŀ",,"1","0"],  
		["|���ǵ�Ŀ��", "http://www.my-soft.net.cn/Frame/idea.html", "iconarr.gif"],
		["|��ϵ����", "http://www.my-soft.net.cn/Frame/contact.html", "iconarr.gif"],
      
];

dtree_init();
