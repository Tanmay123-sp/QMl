# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\apprecorderOpenCV_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\apprecorderOpenCV_autogen.dir\\ParseCache.txt"
  "apprecorderOpenCV_autogen"
  )
endif()
