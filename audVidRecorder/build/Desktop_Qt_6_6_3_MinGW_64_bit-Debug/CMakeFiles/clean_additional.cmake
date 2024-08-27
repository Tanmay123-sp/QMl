# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appaudVidRecorder_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appaudVidRecorder_autogen.dir\\ParseCache.txt"
  "appaudVidRecorder_autogen"
  )
endif()
