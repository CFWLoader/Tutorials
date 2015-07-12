LIBRARYS = `pkg-config --cflags --libs libmongoc-1.0`

TARGET_FILES = example5

all: $(TARGET_FILES)

example5: example5.c
	gcc -o example5 example5.c $(LIBRARYS)

clean:
	rm -rf $(TARGET_FILES)