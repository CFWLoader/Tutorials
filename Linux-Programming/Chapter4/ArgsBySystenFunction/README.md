# About getopt
This function will reform the argument array.</br>
In get args by opt function experiment, variable optarg registers the argument after the option.</br>
For example, '-f filename', when the getopt return argument 'f', you can get 'filename' by variable optarg.</br>
And the optind will record the non-option argument.</br>
You can iterate them by a for clause.</br>
Example: for(; optind < argc; ++optind){Your codes.}

<p>
In get long args experiment, we must define _GNU_SOURCE to use getopt_long and structure option.</br>
<pre class="brush: c; gutter: true">
struct option{
	const char* name;		//Long argument name;
	int has_args;			//How many parameters this option has.0 indicates no parameter, 1 indicates must pass a parameter, 2 indicates a optional paramete.
	int* flag;			//If NULL,the function getopt_long returns value of val to the function calls it; else return the value to the variable and 0 return to the function calls it.
	int val;			//option value.
}
</pre>
</p>
