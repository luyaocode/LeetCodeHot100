project(Other LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/Other)
file(GLOB src_files
    "${SOURCE_DIR}/*.cpp"
    "${SOURCE_DIR}/*.h"
)
add_executable (${PROJECT_NAME} ${src_files})
