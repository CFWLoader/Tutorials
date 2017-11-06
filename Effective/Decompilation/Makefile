all: main.format.s

main.format.s:
	g++ -g -S -O0 -m32 main.cpp -o- | c++filt > main.format.s

clean:
	rm -rf main.format.s