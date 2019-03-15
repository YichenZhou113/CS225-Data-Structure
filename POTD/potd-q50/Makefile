EXENAME = main
OBJS = main.o intersperse.o

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

intersperse.o: intersperse.cpp
	$(CXX) $< $(CXXFLAGS)

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
