#!/bin/sh

echo "Is it morning?"

read timeOfDay

case "$timeOfDay" in
	yes | y | Yes | YES)	echo "Good morning";;
	no | n | NO | No)	echo "Good afternoon";;
	*  )	echo "Sorry, I don't regonize what you said.";;
esac

exit 0
