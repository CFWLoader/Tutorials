#!/bin/sh

echo Please enter something:

read var

if [ "$var" = "a" ]; then
	echo You enter \"a\"
elif [ "$var" = "b" ]; then
	echo You enter \"b\"
else
	echo You enter other key
fi
