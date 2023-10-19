cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(sfinae VERSION ${PROJECT_VESRION})




add_executable(sfinae sfinae.cpp)


set_target_properties(sfinae PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)





if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
target_compile_options(sfinae PRIVATE
-g
-Wall
-Wextra
-Werror
-pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
target_compile_options(sfinae PRIVATE
/EHsc
/W4
/WX)
endif()

install(TARGETS sfinae RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)


