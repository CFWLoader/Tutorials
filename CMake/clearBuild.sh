for prj in $(ls); do
	echo ${prj}
	if [ -d ${prj}/build ]; then
		cd ${prj}/build
		rm -rf *
		cd ../..
	fi
done
