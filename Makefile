#CXXFLAGS =	-O0 -g -Wall -fmessage-length=0 -std=c++11
CXXFLAGS =	-O3  -Wall -fmessage-length=0 -std=c++11

LFLAGS = -g

OBJS =		trominoTiling.o Tromino.o Board.o Puzzler.o

LIBS =

TARGET =	trominoTiling

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS) $(LFLAGS)
	
%.o:	%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(CLFLAGS) -c $*.cpp -o $*.o
	$(CXX) -MM $(CXXFLAGS) $(INCLUDE) $(CLFLAGS) $*.cpp > $*.d

-include $(OBJS:.o=.d)
	

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
