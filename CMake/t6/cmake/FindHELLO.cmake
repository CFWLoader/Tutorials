set(CMAKE_PREFIX_PATH /home/cfwloader/Documents/Pseudo/t3)

find_path(HELLO_INCLUDE_DIR hello.h /home/cfwloader/Documents/Pseudo/t3/headers)

# set(CMAKE_PREFIX_PATH /home/cfwloader/Documents/Pseudo/t3/lib)

find_library(HELLO_LIBRARY NAMES hello PATH /home/cfwloader/Documents/Pseudo/t3/lib)

# find_library(HELLO_LIBRARY NAMES curl PATH /usr/lib64)
# find_package(CURL)

# message(STATUS "CURL LIB : ${CURL_LIBRARY}")

if (NOT HELLO_LIBRARY)
	message(STATUS "Lost lib hello")
endif (NOT HELLO_LIBRARY)

if (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
	set(HELLO_FOUND TRUE)
endif (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)

if (HELLO_FOUND)
	if (NOT HELLO_FIND_QUIETLY)
		message(STATUS "Found Hello: ${HELLO_LIBRARY}")
	endif (NOT HELLO_FIND_QUIETLY)
else (HELLO_FOUND)
	if (HELLO_FIND_REQUIRED)
		message(FATAL_ERROR "Could not find hello library.")
	endif (HELLO_FIND_REQUIRED)
endif (HELLO_FOUND)

