# Hello Go!
### How to compile and execute a go project:
- Make your project directory.
- Setting $GOPATH to you project directory.
- Make a directory name 'src' under the project directory.
- Before Writing your source codes, you make a directory to wrap you codes(We may name it 'TARGET').
- Write your go source codes and save them in the '${TARGET}' directory(Notice the relative path in the 'src' directory, We may call it 'REL-PATH').
- Use 'go install ${REL-PATH}/${TARGET}' to compile the binary file and there will be a directory named 'bin' under path $GOPATH.
- The executive file named ${TARGET}' is generated in the diretory 'bin'.

