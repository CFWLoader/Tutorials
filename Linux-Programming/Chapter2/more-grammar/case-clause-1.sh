#!/bin/sh

echo "Is it morning?"

read timeOfDay

case "$timeOfDay" in
	yes)	echo "Good morning";;
	no )	echo "Good afternoon";;
	y  )	echo "Good morning";;
	n  )	echo "Good afternoon";;
	*  )	echo "Sorry, I don't regonize what you said.";;
esac

exit 0
