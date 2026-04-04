CXX		 = g++
CXXFLAGS = -Wall -std=c++17 -pthread
TARGET	 = join_detach
SRC		 = join_detach.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o bin/$(TARGET)

.PHONY: clean
clean:
	rm -f bin/$(TARGET)