#!/bin/sh

echo Guess I want what?
read statement

while [ "$statement" != "reject" ]; do
	echo Sorry, try again
	read statement
done

exit 0
