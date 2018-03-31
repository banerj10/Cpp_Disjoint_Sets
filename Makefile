EXENAME = testdset
OBJS = testdset.o disjointset.o

CXX = g++
CXXFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LD = g++
LDFLAGS = -std=c++1y

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

dsetTest.o : testdset.cpp disjointset.h
	$(CXX) $(CXXFLAGS) testdset.cpp

disjointSet.o : disjointset.cpp disjointset.h
	$(CXX) $(CXXFLAGS) disjointset.cpp

clean :
	-rm -f *.o $(EXENAME)