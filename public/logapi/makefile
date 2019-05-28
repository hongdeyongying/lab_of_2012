
BUILD=liblogapi.a

OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

CPPFLAGS+=-D_FILE_OFFSET_BITS=64 -D_LARGE_FILE -I../../../SOFT/apr-1.3.3/include/apr-1/ \
	-I../../../SOFT/log4cxx/include/

all:$(BUILD)

%.o:%.cpp
	g++ $(CPPFLAGS) -c  -o $@ $<

$(BUILD):$(OBJS)	
	ar rcs $@ $?
	
clean:
	rm $(BUILD) *.o

