cmake_minimum_required(VERSION 3.31)
project(CryptoCalc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# 1) googletest submodule
add_subdirectory(extern/googletest)

# 2) Application
add_executable(CryptoCalc
    CryptoCalc/src/main.cpp
    CryptoCalc/src/CryptoCalculator.cpp
    CryptoCalc/src/FileHandler.cpp
    CryptoCalc/src/RandomMarketSimulator.cpp
    CryptoCalc/src/Transaction.cpp
)

target_include_directories(CryptoCalc PRIVATE
    ${PROJECT_SOURCE_DIR}/CryptoCalc/include
)

# 3) enable the CTest 
enable_testing()

# 4)test binary

# 4) test binary
add_executable(CryptoCalcTests
    test/Transaction_test.cpp
    CryptoCalc/src/CryptoCalculator.cpp
    CryptoCalc/src/FileHandler.cpp
    CryptoCalc/src/RandomMarketSimulator.cpp
    CryptoCalc/src/Transaction.cpp
)

target_include_directories(CryptoCalcTests PRIVATE
    ${PROJECT_SOURCE_DIR}/CryptoCalc/include
    ${PROJECT_SOURCE_DIR}/extern/googletest/googletest/include
)

# 5) link to the imported gtest_main target
target_link_libraries(CryptoCalcTests
    PRIVATE
        GTest::gtest_main
)

# 6) register all tests with CTest
include(GoogleTest)
gtest_discover_tests(CryptoCalcTests)