message(STATUS "Building DAG-Geant4")
cmake_minimum_required(VERSION 2.8)
# CXX compiler flags
#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Geant4_CXX_FLAGS}")

# Linker flags
if (BUILD_STATIC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
endif (BUILD_STATIC)

# Source files
set(SRC_FILES)
file(GLOB SRC_FILES ${SRC_FILES} "*.cc")
file(GLOB SRC_FILES ${SRC_FILES} "src/*.cc")

# Libraries
set(LINK_LIB)
list(APPEND LINK_LIBS ${Geant4_LIBRARIES})

# Include directories
include(${Geant4_USE_FILE})
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# Build DAG-Geant4
add_executable(DagGeant4 ${SRC_FILES})
target_link_libraries(DagGeant4 ${LINK_LIBS})
# install(TARGETS DagGeant4 DESTINATION ${INSTALL_BIN_DIR})
