CXX		 = g++
CXXFLAGS = -Wall -std=c++17 -pthread
TARGET	 = live_lock
SRC		 = live_lock.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o bin/$(TARGET)

.PHONY: clean
clean:
	rm -f bin/$(TARGET)