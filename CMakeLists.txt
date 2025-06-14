cmake_minimum_required(VERSION 3.28)

project(FruitBoxSolver
    VERSION 25.6.14
    LANGUAGES CXX
)

add_executable(solver solver/main.cpp)
target_compile_features(solver PRIVATE cxx_std_23)
target_compile_options(solver PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(solver PRIVATE ${CMAKE_SOURCE_DIR}/solver)

install(TARGETS solver DESTINATION bin)
