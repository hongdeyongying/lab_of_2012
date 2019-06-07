BUILD=edgw device_gt02 ldd_admin pdd_admin

OBJS = .obj/CFrame.o .obj/gvar_edgw.o .obj/main_edgw.o .obj/CListener.o .obj/CWorker.o .obj/CLDDGt02.o .obj/CPDDGt02.o

OBJS_CLI = .obj/device_gt02.o .obj/gvar_edgw.o

OBJS_LDD_ADMIN = .obj/ldd_admin.o .obj/CLDDGt02.o .obj/CPDDGt02.o  .obj/gvar_edgw.o

OBJS_PDD_ADMIN = .obj/pdd_admin.o .obj/CPDDGt02.o .obj/gvar_edgw.o

#$(patsubst %.cpp, %.o, $(wildcard *.cpp))

CPPFLAGS+=-ggdb \
	-D_FILE_OFFSET_BITS=64 -D_LARGE_FILE \
	-I../../public/utility/ \
	-I../../public/html/ \
	-I../../public/fileconfig/ \
	-I../../public/logapi/ \
	-I../../public/linespm/

LDFLAGS+=\
	-L../../public/linespm/ -llinespm \
	-L../../public/fileconfig/ -lfileconfig \
	-L../../public/html/ -lhtml \
	-L../../public/utility/  -lutility \
	-L../../public/logapi/ -llogapi \
	-llog4cxx \
	-lssl \
	-lpthread -lrt -llog4cxx
	

all:$(BUILD)

.obj/%.o:%.cpp
	mkdir -p .obj
	g++ $(CPPFLAGS) -c  -o $@ $<

edgw:$(OBJS)	
	g++ -o $@ $? $(LDFLAGS)
	
device_gt02:$(OBJS_CLI)	
	g++ -o $@ $? $(LDFLAGS)
	
ldd_admin:$(OBJS_LDD_ADMIN)
	g++ -o $@ $? $(LDFLAGS)	
	
pdd_admin:$(OBJS_PDD_ADMIN)
	g++ -o $@ $? $(LDFLAGS)	
	
clean:
	rm $(BUILD) .obj/*.o


install:
	cp $(BUILD) $(SOFT)/DGW/EDGW/bin/


test:
	cd $(SOFT)/DGW/EDGW/bin/; ./edgw;cd $(CODE)/DGW/EDGW 


echo:
	@echo $(OBJS)
