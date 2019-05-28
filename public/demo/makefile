BUILD = $(patsubst %exe.cpp, %exe, $(wildcard *exe.cpp))

LIBPATH=-L./  -L../utility/  -L../linespm/ -L../logapi -L../bpml -L../logapi -L../html -L../http  -L../../../SOFT/boost/lib/ -lboost_regex

INCPATH=-I./ -I../utility/ -I../linespm/  -I../logapi -I../bpml/ -I../html/ -I../http/ -I/usr/local/apr/include/apr-1/  \
	-I../../../SOFT/boost/include/ \
	-I../../../SOFT/log4cxx/include/ \
	-I../../../SOFT/apr-1.3.3/include/apr-1 \
	-I../../../SOFT/openssl/include/

LIBS=-llinespm -lbpml -lhtml -lhttp -lutility -llogapi -lpthread -lrt -llog4cxx 

LDFLAGS+=\
        -L../linespm/ -llinespm \
        -L../bpml/ -lbpml\
        -L../fileconfig/ -lfileconfig \
        -L../html/ -lhtml \
        -L../http/ -lhttp\
        -L../utility/  -lutility \
        -L../logapi/ -llogapi \
        -L../../../SOFT/openssl/lib -lcrypto \
        -L../../../SOFT/cgicc/lib/  -lcgicc\
        -L../../../SOFT/fcgi/lib/  -lfcgi -lfcgi++ \
        -L../../../SOFT/log4cxx/lib -llog4cxx  \
        -L../../../SOFT/fcgi/lib -lfcgi  \
        -L../../../SOFT/openssl/lib -lssl -lcrypto \
        -L../../../SOFT/boost/lib -lboost_regex \
        -L../../../SOFT/mysql++/lib -lmysqlpp \
        -lrt -lz -lpthread 

#-lbpml


CPPFLAGS+=-D_FILE_OFFSET_BITS=64 -D_LARGE_FILE -D_POSIX_V6_ILP32_OFFBIG -D__USE_FILE_OFFSET64 -D__USE_LARGEFILE64  $(LIBPATH) $(INCPATH)   -ggdb 

all:$(BUILD)


%_exe:.obj/%_exe.o
	g++ $(CPPFLAGS)  -o $@ $<  $(LIBS) $(LDFLAGS)

.obj/%.o:%.cpp
	mkdir -p .obj
	g++ $(CPPFLAGS) -c  -o $@ $<

clean:
	rm $(BUILD)


test:
	@echo $(BUILD)
