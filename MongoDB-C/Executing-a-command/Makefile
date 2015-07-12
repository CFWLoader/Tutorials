LIBRARYS = `pkg-config --cflags --libs libmongoc-1.0`

TARGET_FILES = example6

all: $(TARGET_FILES)

example6: example6.c
	gcc -o example6 example6.c $(LIBRARYS)

clean:
	rm -rf $(TARGET_FILES)