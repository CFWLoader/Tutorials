#!/bin/bash

echo Please give the path being cleaned.

read targetPath

enterSubDiretories()
{
	for element in `ls $1`; do

		absolutePath=$1/$element;

		if [ -d $absolutePath ]; then
			enterSubDiretories $absolutePath;
		fi

		ls $absolutePath | xargs file | grep ELF | awk '{print gensub(/[:]/,"",$1, $1)}';

	done
}

enterSubDiretories $targetPath;