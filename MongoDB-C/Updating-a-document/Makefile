LIBRARYS = `pkg-config --cflags --libs libmongoc-1.0`

TARGET_FILES = example4

all: $(TARGET_FILES)

example4: example4.c
	gcc -o example4 example4.c $(LIBRARYS)

clean:
	rm -rf $(TARGET_FILES)