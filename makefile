CXX := g++
TARGET := main
OBJECTS := main.o minheap.o helper.o

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@
	rm -f *.o

%.o: %.cpp
	$(CXX) -c $^ -Wall

clean:
	rm -f $(TARGET) *.o