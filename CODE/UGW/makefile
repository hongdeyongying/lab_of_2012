BUILD=ugw testFactory

OBJS_TRANSACTION=\
	.obj/CTransaction_MYBPML.o \
	.obj/CTransaction_TEST.o \
	.obj/CTransaction_VCDIMG.o \
	.obj/CTransaction_LDD.o \
	.obj/CTransaction_MYSQL.o 

OBJS_TEST = \
	.obj/testFactory.o \
	\
	.obj/CTransaction_MYBPML.o \
	.obj/CTransaction_TEST.o \
	\
	.obj/CChecker_Regx.o \
	.obj/CCheckerFactory.o \
	.obj/CChecker.o \
	\
	.obj/CConvertor_Base.o \
	.obj/CConvertorFactory.o \
	.obj/CConvertor.o \
	\
	.obj/CTransactionFactory.o \
	.obj/CTransaction.o \

OBJS = \
	.obj/md5_xor_D99_T99_CDatabaseHash.o \
	.obj/xiaoqiang_md5_xor_D99_T99_CDatabaseHash.o \
	.obj/CDatabaseHashFactory.o \
	.obj/CDatabaseHash.o \
	\
	.obj/CCGIEntry.o \
	.obj/CCommonCgiIO.o \
	.obj/CCgiIO.o \
	.obj/CDebugCgiIO.o \
	.obj/CFastCgiIO.o \
	\
	.obj/CChecker_Regx.o \
	.obj/CCheckerFactory.o \
	.obj/CChecker.o \
	\
	.obj/CConvertor_Base.o \
	.obj/CConvertorFactory.o \
	.obj/CConvertor.o \
	\
	.obj/CTransactionFactory.o \
	.obj/CTransaction.o \
	\
	.obj/CMd5CDigitalSignature.o \
	.obj/CRsaCDigitalSignature.o \
	.obj/CDigitalSignatureFactory.o \
	.obj/CDigitalSignature.o \
	.obj/mysoft_cgi.o \
	\
	.obj/wheel_CLoadBalanceNodeHash.o\
	.obj/CLoadBalanceNodeHashFactory.o \
	.obj/CLoadBalanceNodeHash.o \
	\
	
CPPFLAGS+=-ggdb \
	-D_FILE_OFFSET_BITS=64 -D_LARGE_FILE \
	-I/usr/include/mysql/ \
	-I../public/utility/ \
	-I../public/html/ \
	-I../public/LPDD/ \
	-I../public/http/ \
	-I../public/bpml/ \
	-I../public/fileconfig/ \
	-I../public/logapi/ \
	-I../public/linespm/ \
	-I$(THIRD_PACKAGE)/cgicc/include/ \
	
LDFLAGS+=\
	-L../public/linespm/ -llinespm \
	-L../public/bpml/ -lbpml\
	-L../public/fileconfig/ -lfileconfig \
	-L../public/html/ -lhtml \
	-L../public/LPDD/ -llpdd \
	-L../public/http/ -lhttp\
	-L../public/utility/  -lutility \
	-L../public/logapi/ -llogapi \
	-lcrypto \
	-L$(THIRD_PACKAGE)/cgicc/lib/  -lcgicc\
	-lfcgi++ \
	-llog4cxx  \
	-lfcgi  \
	-lssl -lcrypto \
	-lboost_regex \
	-lmysqlpp \
	-lgd \
	-lapr-1 \
	-lrt -lz -lpthread \
	

all:$(BUILD)

.obj/%.o:%.cpp
	mkdir -p .obj
	g++ $(CPPFLAGS) -c  -o $@ $<

ugw:$(OBJS_TRANSACTION) $(OBJS)	
	g++ -o $@ $? $(LDFLAGS)
	
testFactory:$(OBJS_TEST)
	g++ -o $@ $? $(LDFLAGS) $(CPPFLAGS) 
	
clean:
	rm $(BUILD) .obj/*.o


install:
	cp $(BUILD) $(SOFT)/UGW/bin/

echo:
	@echo $(OBJS)
