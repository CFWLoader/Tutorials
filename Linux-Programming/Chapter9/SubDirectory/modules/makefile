# Local libraries
MYLIB = mylib.a

all: $(MYLIB)

# Which compiler
CC = gcc

# Where are include files
INCLUDE = .

# Options for development
CFLAGS = -g -Wall -ansi

# Options for release
# CFLAGS = -O -Wall -ansi

$(MYLIB): $(MYLIB)(2.o) $(MYLIB)(3.o)
main.o: main.c a.h				# Notice that an indentation will lead the make command treat it as a command.
2.o: 2.c a.h b.h
3.o: 3.c b.h c.h

clean:
	-rm 2.o 3.o
