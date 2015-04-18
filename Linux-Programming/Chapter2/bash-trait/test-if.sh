#!/bin/sh

#test grammar.
#if test -f fred.c
#then
#	echo fred.c existed.
#fi

#[ grammer.It seems this grammar is more suitable for programs.
#Notice that space aroud symbol '[' and ']'.
if [ -e $1 ]; then
	echo $1 existed.
fi
