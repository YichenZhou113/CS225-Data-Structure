EXENAME = main

CXX = clang++
#CXX = g++
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): matrix.o matrix.h exam.o exam.h main.cpp
	$(CXX) $(CXXFLAGS) main.cpp matrix.o exam.o -o $(EXENAME)

matrix.o: matrix.h matrix.cpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp

exam.o: exam.h exam.cpp
	$(CXX) $(CXXFLAGS) -c exam.cpp

.PHONY: clean
clean:
	rm -f *.o $(EXENAME)
