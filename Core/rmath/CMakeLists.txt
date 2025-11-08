# Core/rmath/CMakeLists.txt

file(GLOB_RECURSE RMATH__HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rmath/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rmath/detail/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rmath/types/*.h"
)

file(GLOB_RECURSE RMATH_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/types/*.c"
)

#list(APPEND CORE_SOURCES ${RMATH_SOURCES})
#list(APPEND CORE_HEADERS ${RMATH_HEADERS})

#set(CORE_SOURCES "${CORE_SOURCES}" PARENT_SCOPE)
#set(CORE_HEADERS "${CORE_HEADERS}" PARENT_SCOPE)

add_library(RMATH STATIC
    "${RMATH_SOURCES}"
)

target_include_directories(RMATH
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#if(BUILD_TESTS)
#    enable_testing()
#
#    add_executable(test_rmath
#        test/test_vec3.c
#        test/test_mat4.c
#    )
#
#    target_link_libraries(test_rmath PRIVATE rmath)
#
#    add_test(NAME rmath_tests COMMAND test_rmath)
#endif()

#target_link_libraries(RMATH PRIVATE m)
#target_compile_definitions(RTM PRIVATE RTM_USE_STATIC_INLINE)

# Si tienes dependencias de pruebas
#enable_testing()
#add_subdirectory(test)