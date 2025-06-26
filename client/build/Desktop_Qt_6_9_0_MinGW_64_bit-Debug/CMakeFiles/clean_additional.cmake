# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\client_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\client_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\test_caesar_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\test_caesar_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\test_hash_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\test_hash_autogen.dir\\ParseCache.txt"
  "client_autogen"
  "test_caesar_autogen"
  "test_hash_autogen"
  )
endif()
