cmake_minimum_required(VERSION 2.8.12)

include(FindJNI)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/..)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# avoid the extra "Debug", "Release" directories
# http://stackoverflow.com/questions/7747857/in-cmake-how-do-i-work-around-the-debug-and-release-directories-visual-studio-2
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

set(HASHLINK_DIR D:/Code/hashlink)
link_directories(${HASHLINK_DIR}/bin)

include_directories(
    ${HASHLINK_DIR}/src
    ${JNI_INCLUDE_DIRS}
)

add_library(hljni.hdll MODULE
    hljni.c
)

target_link_libraries(hljni.hdll
    libhl
)

set_target_properties(hljni.hdll
    PROPERTIES
    PREFIX ""
    OUTPUT_NAME hljni
    SUFFIX .hdll
)
