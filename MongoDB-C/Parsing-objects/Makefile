CC = g++

LIBRARYS = `pkg-config --cflags --libs libmongoc-1.0`

CXX_FLAGS = -std=c++11 -g -Wall

TARGET_FILES = example1

all: $(TARGET_FILES)

example1: example1.cpp
	$(CC) -o example1 example1.cpp $(LIBRARYS) $(JSON) $(CXX_FLAGS) -ljsoncpp

clean:
	rm -rf $(TARGET_FILES)