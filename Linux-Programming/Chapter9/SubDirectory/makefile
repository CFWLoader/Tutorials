all: myapp

# Which compiler
CC = gcc

# Where to install
INSTDIR = /home/cfwloader/Softwares

# Where are include files
INCLUDE = .

# Options for development
CFLAGS = -g -Wall -ansi

# Options for release
# CFLAGS = -O -Wall -ansi

# Local libraries
MYLIB = ./modules/mylib.a

$(MYLIB):
	(cd modules;$(MAKE))			# All bash command should be collected on the first line or the make command return an error.


myapp: main.o $(MYLIB)
	$(CC) -o myapp main.o $(MYLIB)

clean:
	-rm main.o 2.o 3.o

install: myapp
	@if [ -d $(INSTDIR) ]; then \
		cp myapp $(INSTDIR); \
		chmod a+x $(INSTDIR)/myapp; \
		chmod og-w $(INSTDIR)/myapp; \
		echo "Installed in $(INSTDIR)"; \
	else \
		echo "Sorry, $(INSTDIR) does not exist.";\
	fi
