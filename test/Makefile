.SUFFIXES : .cpp .o 

CXX = g++
CXXFLAGS = -g -w -WALL

OBJS = test.o unit.o
SRCS = $(OBJS:.o=.c)

TARGET = test.out
ROOT = /Users/YuHoyeon 1/Documents/workspace/ 
INC = -I$(ROOT)/MobileRobot/include/unit

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $(OBJS) $(INC)

test.o : unit.h test.cpp
unit.o : unit.h unit.cpp

clean:
	rm -f *.o $(TARGET)

