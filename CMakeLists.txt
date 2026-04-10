cmake_minimum_required(VERSION 3.16...3.27)
project(Mu2e)

find_package(Geant4 REQUIRED ui_all vis_all)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(mu2e main.cc ${sources} ${headers})
target_include_directories(mu2e PRIVATE include)
target_link_libraries(mu2e PRIVATE ${Geant4_LIBRARIES})