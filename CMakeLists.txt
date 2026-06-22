cmake_minimum_required(VERSION 3.16...3.27)
project(OpticalPhotons)

find_package(Geant4 REQUIRED ui_all vis_all)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(optical_photons main.cc ${sources} ${headers})
target_include_directories(optical_photons PRIVATE include)
target_link_libraries(optical_photons PRIVATE ${Geant4_LIBRARIES})

set(OPTICAL_PHOTON_SCRIPTS
  init_vis.mac
  )

foreach(_script ${OPTICAL_PHOTON_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()