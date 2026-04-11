CXX		 = g++
CXXFLAGS = -Wall -std=c++17 -pthread
TARGET	 = divide_and_conquer
SRC		 = divide_and_conquer.cpp
# LDLIBS	 = -lboost_thread -lboost_system
#$(LDLIBS)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC)  -o bin/$(TARGET)

.PHONY: clean
clean:
	rm -f bin/$(TARGET)