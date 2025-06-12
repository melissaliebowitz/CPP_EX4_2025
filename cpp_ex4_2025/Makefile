#melissaliebowitz@yahoo.com
CXX = clang++-18
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
TEST_SRC = $(wildcard tests/*.cpp)


.PHONY: main test valgrind clean


main: main.cpp MyContainer.hpp
	$(CXX) $(CXXFLAGS) -o main main.cpp
	./main


test: $(TEST_SRC) MyContainer.hpp
	$(CXX) $(CXXFLAGS) -o test $(TEST_SRC)
	./test


valgrind: main
	valgrind --leak-check=full --track-origins=yes ./main


clean:
	rm -f main test
