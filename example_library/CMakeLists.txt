# Assert the minimum cmake version
cmake_minimum_required(VERSION 3.14)

# Set the project name
project(TEST_CBLAS  VERSION 0.1.0
                    DESCRIPTION "Simple BLAS Usage."
                    LANGUAGES CXX)

# Require a modern C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Add a library called LinearAlg built from src/linear_alg.cpp
add_library(LinearAlg ./src/linear_alg.cpp)

# Add an executable called Main built from src/main.cpp
add_executable(Main ./src/main.cpp)

# Add the ./include directory as an include directory for the Main executable
target_include_directories(Main PRIVATE ./include)

# Locate the BLAS package
find_package(BLAS REQUIRED)

# Link the LinearAlg library target to BLAS via ${BLAS_LIBRARIES}
target_link_libraries(LinearAlg PRIVATE ${BLAS_LIBRARIES})

# Link the Main executable target to the LinearAlg library target
target_link_libraries(Main LinearAlg)

#########################################
# BEGIN GoogleTest setup, DO NOT CHANGE #
#########################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")

# Set up GoogleTest according to: https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(LinearAlgTest test/linear_alg_test.cpp)
target_link_libraries(LinearAlgTest GTest::gtest_main)
target_link_libraries(LinearAlgTest LinearAlg)
target_include_directories(LinearAlgTest PRIVATE include)

include(GoogleTest)
gtest_discover_tests(LinearAlgTest)

##########################
# END   GoogleTest setup #
##########################