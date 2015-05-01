# About

GCC compiler may report can't find term.h, you can install ncurses-devel to fix it.<br/>
Add -lncurses for successfully compiling this menu3-adv.c.<br/>

Function used in this program.<br/>
<pre class="brush:c ; gutter: ture">

	term.h:

	int tigetflag(char* capname);
	int tigetnum(char* capname);
	char* tigetstr(char* capname);		//This three function respectively return the bool value, number value and string value of terminfo's flags.

	char* tparm(char* cap, long p1, long p2, ..., long p9);		//This function provide modification of terminal's flag with numeric value.

	int putp(char* const str);					//Apply the parameter after the tparm's translation to the terminal.
	int tputs(char* const str, int affcnt, int (*putfunc)(int));	//Designed for the situation that stdout can't call terminal.
</pre>
