
project(sigslot)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_options(${PROJECT_NAME} PUBLIC -std=c++98)


#target_link_directories(${PROJECT_NAME} PUBLIC
#        breakpad_client)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/libcxx/include/sigslot
        #../../../libcxx/include/sigslot
        )

#target_link_directories(${PROJECT_NAME} PUBLIC
#        ${BREAKPAD_DIR}/src/build/src/client/linux)