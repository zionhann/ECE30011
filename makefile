CXX := g++
CXXFLAGS := -std=c++11
TARGET := main
OBJECTS := main.o minheap.o helper.o

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $^ $(CXXFLAGS) -Wall

clean:
	rm -f $(TARGET) *.o