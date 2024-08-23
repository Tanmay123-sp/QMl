# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\apprecorder_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\apprecorder_autogen.dir\\ParseCache.txt"
  "apprecorder_autogen"
  )
endif()
