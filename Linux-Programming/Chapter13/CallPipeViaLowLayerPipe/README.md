# About
int pipe(int file_descriptor[2]);<br/>
Notice that the function requires the file descriptor, not the file stream.<br/>
file_descriptor[1] is the part of being written and file_descriptor[0] is the<br/>
part of being read.<br/>
I have a misunderstanding on the parameters of series of exec functions.<br/>
The last parameter of exec*(...), normally is (char*) 0, is not the file descriptor 0<br/>
but the indication of parameters' end of function due to the variable parameters.<br/>

