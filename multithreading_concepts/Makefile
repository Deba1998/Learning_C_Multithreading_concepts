CXX		 = g++
CXXFLAGS = -Wall -std=c++17 -pthread
TARGET	 = dowload_images
SRC		 = dowload_images.cpp
LDLIBS	 = -lboost_thread -lboost_system -lcurl
#$(LDLIBS)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o bin/$(TARGET)

.PHONY: clean
clean:
	rm -f bin/$(TARGET)