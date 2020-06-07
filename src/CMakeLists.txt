cmake_minimum_required (VERSION 3.8)
project(SimpleAudioLibrary)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Add source to this project's executable.
file(GLOB source_files
    "*.h"
    "*.cpp"
)

add_library(SimpleAudioLibrary ${source_files})
target_link_libraries(SimpleAudioLibrary ${CONAN_LIBS})
