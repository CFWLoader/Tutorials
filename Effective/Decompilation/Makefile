TARGET=main.s main.m32.s original_demo.s

all: ${TARGET}

original_demo.s:
	g++ -g -S -O0 -m32 main.cpp -o- | c++filt > original_demo.s

main.s:
	g++ -S main.cpp -o- | c++filt > main.s

main.m32.s:
	g++ -S -m32 main.cpp -o- | c++filt > main.m32.s

clean:
	rm -rf ${TARGET}