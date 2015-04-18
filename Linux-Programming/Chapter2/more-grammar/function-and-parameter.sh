#!/bin/sh

checkName(){
	echo "Is this your name $* ?"
	while true; do
		echo -n "Enter yes or no:"
		read x
		case "$x" in
			y | yes ) return 0;;
			n | no )  return 1;;
			* )  echo "Please answer yes or no:"
		esac
	done
}

if checkName "$1"; then
	echo "Hi $1, nice name"
else
	echo "Never mind"
fi

exit 0
