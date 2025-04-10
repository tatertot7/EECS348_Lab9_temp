CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

OBJS = main.o

matrix.exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o matrix.exe $(OBJS)

main.o: main.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o matrix.exe
