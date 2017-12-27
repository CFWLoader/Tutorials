#!/bin/sh

target_suffix=("*.dvi" "*.pdf" "*.aux" "*.log" "*.lof" "*.lot" "*.toc" "*.bbl" "*.blg")

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
	curdir=$1

	# echo $curdir
	
	for sub in `ls $curdir`; do
		# echo $sub
		if [ -d $sub ]; then
			search_subdir $sub
			# echo $sub
		fi
	done

	clean_dir ${curdir}

	# echo $curdir
}

search_subdir `pwd`
