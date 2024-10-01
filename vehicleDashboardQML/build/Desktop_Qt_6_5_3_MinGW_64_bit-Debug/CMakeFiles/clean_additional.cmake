# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appvehicleDashboardQML_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appvehicleDashboardQML_autogen.dir\\ParseCache.txt"
  "appvehicleDashboardQML_autogen"
  )
endif()
