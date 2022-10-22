cmake_minimum_required(VERSION 3.16)
project(cpp_files)

set(CMAKE_CXX_STANDARD 11)

#include(CmakePrintHelpers)

find_package(Boost REQUIRED)

macro(compile_single_cpp dir file_name)
    add_executable(${dir}_${file_name} ${dir}/${file_name})
    target_link_libraries(${dir}_${file_name})
endmacro()


set(CPP_DIRS cf test algorithm_template)
foreach (compile_dir ${CPP_DIRS})
    message(STATUS "compile_dir: ${compile_dir}")
    file(GLOB files RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/${compile_dir}" ${compile_dir}/*.cpp)
    foreach (file ${files})
        message(STATUS "folder ${compile_dir}, file: ${file}")
        compile_single_cpp(${compile_dir} ${file})
    endforeach ()
endforeach ()

file(GLOB apps RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/bin/*)
#cmake_print_variables(apps)
foreach(app_dir ${apps})
    add_subdirectory(${app_dir})
endforeach()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/target/${CMAKE_BUILD_TYPE}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/target/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/target/${CMAKE_BUILD_TYPE}")
