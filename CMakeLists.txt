cmake_minimum_required(VERSION 2.8)

# define by input
set(INCLUDE_DIR "" CACHE PATH "3rdparty include")
set(LIBRARIES "" CACHE PATH "3rdparty libraries")

project(CeresSophus)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")

find_package(Eigen3 QUIET)
find_package(Sophus QUIET)
find_package(Ceres QUIET)

include_directories(
${INCLUDE_DIR}
${EIGEN3_INCLUDE_DIRS}
${Sophus_INCLUDE_DIRS}
${CERES_INCLUDE_DIRS}
)

# target
add_executable(ceres_sophus_se3 ceres_sophus_se3.cpp local_parameterization_se3.hpp)
target_link_libraries(ceres_sophus_se3 ${CERES_LIBRARIES} ${LIBRARIES})
if(MSVC)
target_compile_definitions(ceres_sophus_se3 
    PRIVATE _CRT_NONSTDC_NO_WARNINGS _USE_MATH_DEFINES GOOGLE_GLOG_DLL_DECL=)
endif(MSVC)
