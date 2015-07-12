LIBRARYS = `pkg-config --cflags --libs libmongoc-1.0`

TARGET_FILES = example3

all: $(TARGET_FILES)

example3: example3.c
	gcc -o example3 example3.c $(LIBRARYS)

clean:
	rm -rf $(TARGET_FILES)