# About

### Structure of termios

<pre class="brush: c; gutter: true">
struct termios{
	tcflag_t c_iflag;		//Mode of input
	tcflag_t c_oflag;		//Mode of output
	tcflag_t c_cflag;		//Mode of control
	tcflag_t c_lflag;		//Local mode
	cc_t     c_cc[NCCS];		//Control characters
};

int tcsetattr(int fd, int actions, const struct termios* termios_p);

Values of actions:
TCSANOW: Modifies value immediately.
TCSADRAIN: Modifies value after completion of output.
TCSAFLUSH: Modifies value after completion of output, but aborts the inputs.

TCSA*
</pre>
