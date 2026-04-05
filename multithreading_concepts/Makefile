CXX		 = g++
CXXFLAGS = -Wall -std=c++17 -pthread
TARGET	 = shared_mutex_try
SRC		 = shared_mutex_try.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o bin/$(TARGET)

.PHONY: clean
clean:
	rm -f bin/$(TARGET)