cmake_minimum_required(VERSION 3.20)
project(AcmeBackend VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(httplib CONFIG REQUIRED)

add_executable(AcmeBackend src/main.cpp)

target_link_libraries(AcmeBackend PRIVATE httplib::httplib)