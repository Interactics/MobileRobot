CXX = g++
CFLAGS = -g -w -WALL
OBJS = test.o unit.o
TARGET = test.out
INC = -I../include


$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

test.o : ../include/unit/unit.h test.cpp
unit.o : ../include/unit/unit.h ../src/unit/unit.cpp


clean:
	rm -f *.o $(TARGET)
