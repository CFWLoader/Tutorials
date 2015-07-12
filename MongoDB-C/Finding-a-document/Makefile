LIBRARYS = `pkg-config --cflags --libs libmongoc-1.0`

TARGET_FILES = example1 example2

all: $(TARGET_FILES)

example1: example1.c
	gcc -o example1 example1.c $(LIBRARYS)

example2: example2.c
	gcc -o example2 example2.c $(LIBRARYS)

clean:
	rm -rf $(TARGET_FILES)