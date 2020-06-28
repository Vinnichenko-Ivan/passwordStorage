cmake_minimum_required(VERSION 3.10.2) 
find_package(OpenSSL REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main OpenSSL::SSL)
