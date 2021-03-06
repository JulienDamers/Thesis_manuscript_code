cmake_minimum_required(VERSION 3.10)
project(Thesis_manuscript_code)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -O3)


## Packages Import
##########################################################
# CODAC-LIB (and IBEX-LIB) package
# Adding IBEX
find_package(IBEX REQUIRED)
ibex_init_common() # IBEX should have installed this function
message(STATUS "Found IBEX version ${IBEX_VERSION}")

# Adding Codac
find_package(CODAC REQUIRED)
message(STATUS "Found Codac version ${CODAC_VERSION}")

# Eigen
find_package(Eigen3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIRS})

###########################################################
# CAPD package
find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_CAPD REQUIRED  capd capd-gui mpcapd mpcapd-gui capdRedHom )  # this looks for .pc file
message(STATUS "Found CAPD")
include_directories(${PKG_CAPD_INCLUDE_DIRS})
set(LIBS ${CODAC_LIBRARIES} Ibex::ibex ${CODAC_LIBRARIES} ${PKG_CAPD_LDFLAGS})
###########################################################




## Executables/Libs creation
###########################################################
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)


add_subdirectory(cpp)