# Core/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(Core LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ----------------------------------------------------------
# Lib options
# ----------------------------------------------------------
option(CORE_BUILD_SHARED "Build CORE as a shared library" OFF)
option(CORE_BUILD_TESTS "Build CORE/test for this module" OFF)


#add_subdirectory(...)

# ----------------------------------------------------------
# Create Core Lib
# ----------------------------------------------------------
if(CORE_BUILD_SHARED)
    add_library(Core SHARED ${CORE_SOURCES} ${CORE_HEADERS})
else()
    #add_library(Core STATIC ${CORE_SOURCES} ${CORE_HEADERS})
    message("DEFAULT BUILD")
endif()

set(CORE_SOURCES
    core.c
)

add_library(Core STATIC ${CORE_SOURCES})

#target_link_libraries(Core PUBLIC ....)

target_compile_features(Core PUBLIC c_std_11)
if(MSVC)
    target_compile_options(Core PRIVATE /W4 /WX)
else()
    target_compile_options(Core PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

target_include_directories(Core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/rmath/include>
        $<INSTALL_INTERFACE:include>
)

# ----------------------------------------------------------
# Build Test
# ----------------------------------------------------------
#if(BUILD_TESTS)
#endif()

# ----------------------------------------------------------
# Instalation
# ----------------------------------------------------------
#include(GNUInstallDirs)
#
#install(
#    TARGETS Core
#    EXPORT CoreTargets
#    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
#
#install(
#    DIRECTORY rmath/include/
#    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#)
#
#install(
#    EXPORT CoreTargets
#    FILE CoreConfig.cmake
#    NAMESPACE Core::
#    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Core
#)