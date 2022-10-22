
project(breakpad_demo)

add_executable(${PROJECT_NAME} main.cpp)

set(BREAKPAD_DIR "/home/poilk/Documents/tools/breakpad")


target_compile_options(${PROJECT_NAME} PUBLIC -g)


target_link_directories(${PROJECT_NAME} PUBLIC
        breakpad_client)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${BREAKPAD_DIR}/src/client/linux/handler
        ${BREAKPAD_DIR}/src
        )

target_link_directories(${PROJECT_NAME} PUBLIC
        ${BREAKPAD_DIR}/src/build/src/client/linux)