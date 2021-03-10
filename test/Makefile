.SUFFIXES : .cpp .o 

CXX = g++
CXXFLAGS = -g -Wall

EXEC = test
OBJS = test.o
SRCS = $(OBJS:.o=.cpp)

TARGET = test

$(EXEC) : test.o
	$(CXX) -o $(TARGET) $(OBJS) -L../src/unit -lunit
test.o : test.cpp
unit.o : unit.cpp

clean:
	rm -f *.o $(TARGET)

