CXX		 = g++
CXXFLAGS = -Wall -std=c++17 -pthread
TARGET	 = data_race
SRC		 = data_race.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o bin/$(TARGET)

.PHONY: clean
clean:
	rm -f bin/$(TARGET)