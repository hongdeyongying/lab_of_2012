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
[/*
	["������֧��", "", "","","", "չ��/�������Ŀ",,"1","0"],
        ["|�̳�����ϵͳ", "./url", "", ""],
            ["||����POS", "testlink.htm", "iconarr.gif"],
            ["||MIS POS", "testlink.htm", "iconarr.gif"],
            ["||������", "testlink.htm", "iconarr.gif"],
        ["|�������ֵϵͳ", "./url", "", ""],
            ["||PSTN�ն�", "testlink.htm", "iconarr.gif"],
            ["||CTSI�ն�", "testlink.htm", "iconarr.gif"],
            ["||ADSL�ն�", "testlink.htm", "iconarr.gif"],
            ["||GPRS�ն�", "testlink.htm", "iconarr.gif"],
        ["|��ý���ն�", "./url", "", ""],
            ["||PSTN�ն�", "testlink.htm", "iconarr.gif"],
            ["||CTSI�ն�", "testlink.htm", "iconarr.gif"],
            ["||ADSL�ն�", "testlink.htm", "iconarr.gif"],
            ["||GPRS�ն�", "testlink.htm", "iconarr.gif"],
        
	["����֧��", "", "","","", "չ��/�������Ŀ",,"1","0"],
        ["|�Ƹ�ͨB2C֧���ӿ�ʾ��", "./url", "", ""],
            ["||��ͨ���汾1", "testlink.htm", "iconarr.gif"],
            ["||������,�汾3", "testlink.htm", "iconarr.gif"],
            ["||������,�汾4", "testlink.htm", "iconarr.gif"],
            ["||ί�д���,�汾4", "testlink.htm", "iconarr.gif"],
        ["|�Ƹ�ͨ������ѯ�ӿ�", "", "", ""],            
            ["||��ͨ,�汾1", "testlink.htm", "iconarr.gif"],
            ["||������,�汾2", "testlink.htm", "iconarr.gif"],
            ["||�������󣬰汾4", "testlink.htm", "iconarr.gif"],
            ["||���˽�����汾4", "testlink.htm", "iconarr.gif"],
        ["|�Ƹ�ͨ���˽ӿ�", "", "", ""],            
            ["||�ϰ汾���ˣ�1", "testlink.htm", "iconarr.gif"],
            ["||�°汾���ˣ�4", "testlink.htm", "iconarr.gif"],
            ["||�����˿4", "testlink.htm", "iconarr.gif"],
            ["||�ϰ汾�����˿1", "testlink.htm", "iconarr.gif"],
        ["|�Ƹ�ͨ��������", "", "", ""],            
            ["||�̻���ʵʱ����", "testlink.htm", "iconarr.gif"],
            ["||QQ��Ϣ֪ͨ", "testlink.htm", "iconarr.gif"],
			["||�û���Ϣ��֤", "testlink.htm", "iconarr.gif"],
			["||ǩ��ί�д���", "testlink.htm", "iconarr.gif"],
			["||ί�д��ۿۿ�汾1", "testlink.htm", "iconarr.gif"],
            
	["���繤��", "", "","","", "չ��/�������Ŀ",,"1","0"],
        ["|���ع���", "", "", ""],
            ["||my������", "testlink.htm", "iconarr.gif"],            
        ["|���簲ȫ", "", "", ""],            
            ["||my����ǽ", "mailto:gaussgao@tencent.com", "iconarr.gif"],
            ["||my������", "mailto:gaussgao@tencent.com", "iconarr.gif"],      */
    ["My-Soft", "", "","","", "չ��/�������Ŀ",,"1","0"],
        ["|�������", "", "", ""],
            ["||����䷢����", "Frame/deploy.htm", "iconarr.gif"],     
            ["||�����֤����", "Frame/validate.htm", "iconarr.gif"],    
            ["||��֤My-Soft�����", "Frame/validate_my-soft.htm", "iconarr.gif"],          
        ["|�����빤��", "", "", ""],            
            ["||������֤��", "Frame/developercert.htm", "iconarr.gif"],
            ["||��֤��", "Frame/rootcert.htm", "iconarr.gif"],
            ["||��֤����", "Frame/softcheck.htm", "iconarr.gif"],
            
    ["+�ҵ����", "", "","","", "չ��/�������Ŀ",,"1","0"],  
				["|���տ�Ʊ", "", "", ""],
					["||�����ͻ���", "Product/hnair_b2b_client.htm", "iconarr.gif", ""],  
				["|�ֿ����ϵͳ", "", "", ""],
					["||�ֿ��̵�ϵͳ", "Product/stock_check.htm", "iconarr.gif", ""],    
 /*   
	["��������", "Frame/index_download.html", "","","", "չ��/�������Ŀ",,"1","0"],  
		["|Access�ļ�����", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		["|Opensslʵ��Ssl��DEMO", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		["|Crypto��֤�����DEMO", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		["|���Ҽ�����", "", "iconarr.gif", ""],            
        ["|�ı��ļ�����", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		["|PSAM����DEMO", "", "iconarr.gif", ""],            
        ["|��ͼ������DEMO", "mailto:gaussgao@tencent.com", "iconarr.gif"],
		*/
	["��������", "", "","","", "չ��/�������Ŀ",,"1","0"],      
		["|GNU���빤��", "", "", ""],            
	        ["||Automake", "Download/gnu_autoconf.7z", "iconarr.gif"],
			["||Autoconf", "Download/gnu_automake.7z", "iconarr.gif"],
		["|WEB������", "", "", ""],            
	        ["||Apache�������Ż�", "Download/apache224_ssl.7z", "iconarr.gif"],
		["|���ܽ���", "", "", ""],            
	        ["||Openssl", "Download/openssl_ca_crt.zip", "iconarr.gif"],
			/*["||Crypto", "mailto:gaussgao@tencent.com", "iconarr.gif"], */
	["+��������", "", "","","", "չ��/�������Ŀ",,"1","0"],  
		["|���ǵ�Ŀ��", "Frame/idea.html", "iconarr.gif"],
		["|��ϵ����", "Frame/contact.html", "iconarr.gif"],
//		["|��������", "http://user.qzone.qq.com/372132908", "iconarr.gif"],
	
      
];

dtree_init();
