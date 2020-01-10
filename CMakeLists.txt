# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (BowlingGameKata)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
#add_subdirectory (Source)

include_directories(Source/include)

set(PROJECT_SOURCES Source/src/BowlingGame.cpp)

add_executable(bowling_game_kata Source/src/main.cpp ${PROJECT_SOURCES})

add_executable(test_bowling_game_kata Test/BowlingGameTest.cpp ${PROJECT_SOURCES})

TARGET_LINK_LIBRARIES(test_bowling_game_kata gtest gtest_main pthread)
