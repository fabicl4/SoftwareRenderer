cmake_minimum_required(VERSION 3.15)
project(SoftwareRenderer LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(CMAKE_C_FLAGS "-Wall -Wextra -Werrror")

# Set Unicode definition - Win32API specific configuration
#add_definitions(-DUNICODE -D_UNICODE)

# Output directories (for organized builds)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

foreach(OUTPUTCONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin-int)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin-int)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin)
endforeach()

# Enable folders in Visual Studio for better organization
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "Building projects...")

# Add subdirectories (each one has its own CMakeLists.txt)
add_subdirectory(Test)