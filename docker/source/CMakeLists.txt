cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project (multMatrix)
add_executable (multMatrix main_multMatrix.cpp utils.h utils.cpp multmatrix.cpp multmatrix.h operaciones.h)
target_link_libraries(multMatrix pthread)

project(serverObjetos LANGUAGES CXX)
add_executable(serverMultmatrix utils.h utils.cpp serverObjetos.cpp multmatrix_imp.h multmatrix_stub.h operaciones.h multmatrix.cpp multmatrix.h)
target_link_libraries(serverMultmatrix pthread)

