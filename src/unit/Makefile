CXX = g++
LIB = libunit.a
OBJS = unit.o
INC = -I../../include/unit
CXXFLAGS = -Wall

$(LIB) : $(OBJS) 
	$(AR) rv $@ $(OBJS)

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $(INC)

clean:
	rm -f $(OBJS) $(LIB)