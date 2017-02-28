#!/bin/sh

target_suffix=("*.dvi" "*.pdf" "*.aux" "*.log")

# for ele in ${target_suffix[*]}; do
# 	echo $ele
# done

clean_dir()
{
	dir=$1

	for ele in ${target_suffix[*]}; do
		rm -rf ${dir}/${ele}
	done 
}

search_subdir()
{
	curdur=$1
	
	for sub in `ls $curdir`; do
		# echo $sub
		if [ -d $sub ]; then
			search_subdir $sub
			# echo $sub
		fi
	done

	echo $curdir
}

search_subdir `pwd`
