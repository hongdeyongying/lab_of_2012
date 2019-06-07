BUILD = $(patsubst %exe.cpp, %exe, $(wildcard *exe.cpp))




LIBPATH=-L./  -L../utility/  -L../linespm/ -L../logapi -L../bpml -L../logapi -L../html -L../http  -lboost_regex

INCPATH=-I./ -I../utility/ -I../linespm/  -I../logapi -I../bpml/ -I../html/ -I../http/ 

LIBS=-llinespm -lbpml -lhtml -lhttp -lutility -llogapi -lpthread -lrt -llog4cxx 

LDFLAGS+=\
        -L../linespm/ -llinespm \
        -L../bpml/ -lbpml\
        -L../fileconfig/ -lfileconfig \
        -L../html/ -lhtml \
        -L../http/ -lhttp\
        -L../utility/  -lutility \
        -L../logapi/ -llogapi \
        -lcrypto \
        -llog4cxx  \
        -lssl -lcrypto \
        -lboost_regex \
        -L$(THIRD_PACKAGE)/cgicc/lib/  -lcgicc\
        -lfcgi -lfcgi++ \
        -lmysqlpp \
	-lapr-1 \
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
