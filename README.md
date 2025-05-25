# CryptoCalc – Cryptocurrency Investment Calculator (Project 3)

## Overview
CryptoCalc is a tool that builds on the original CryptoCalc from Project 1 by refactoring into a fully object-oriented design. Users can load, save, and replay transaction histories, simulate market price movements, and compute profit-and-loss—all via clean abstractions, smart pointers, and exception-safe I/O.

## Features
- **Interactive CLI**  
  Prompt the user for input/output filenames, simulation parameters, and binary replay options.
- **Transaction Management**  
  Represented by a `Transaction` class (coin, quantity, price, type) with encapsulation and `print()` formatting.
- **File I/O Abstraction**  
  `IFileHandler` interface → `FileHandler` implementation for text & binary serialization, throwing `FileException` on errors.
- **Market Simulation**  
  `IMarketSimulator` interface → `RandomMarketSimulator` for configurable, random daily price paths.
- **OOP Pillars Demonstrated**  
  - **Abstraction & Encapsulation** via interfaces and private data members.  
  - **Inheritance & Polymorphism** for file handlers and simulators.  
  - **Composition** in `CryptoCalculator` (it owns a handler + a simulator).  
- **Smart Memory Management**  
  Uses `std::unique_ptr` and `std::shared_ptr` for all dynamic objects—no raw `new`/`delete`.
- **STL Containers & Utilities**  
  Leverages `std::vector`, `std::string`, `<iomanip>` formatting, and exception handling for robust code.
- **Exception Safety**  
  All file operations throw and catch `FileException` (and general `std::exception`) for clean failure recovery.

## How It Works
1. **Load Transactions**  
   - Prompt: `Text-file to load: data/transactions.txt`  
   - Parses each line into a `Transaction` object.
2. **Optional Binary Save & Reload**  
   - Save: user can write `.bin` for faster replay.  
   - Reload: read back from binary to rehydrate transactions.
3. **Simulate Market**  
   - Prompt: `Days to simulate`, `Initial price`.  
   - Generates a random price series modeling volatility.
4. **Compute P/L**  
   - Uses the first simulated price as reference.  
   - BUY → subtract cost; SELL → add revenue.
5. **Display Results**  
   - Nicely formatted two-decimal output for transactions, prices, and net P/L.

## What’s New in Project 3
- Introduction into **classes** and **interfaces**.  
- Demonstrates **inheritance**, **polymorphism**, and **composition**.  
- Introduces **exception-safe** file handling with custom `FileException`.  
- Uses **smart pointers** (`unique_ptr`, `shared_ptr`) exclusively.  
- Modular folder structure (`include/`, `src/`, `data/`, `README.md`).  
- Interactive user prompts for a richer experience.  

## Video Presentation
Watch the project walkthrough on YouTube: https://youtu.be/mzV04nnS3P0 



#  Build & Test Instructions

## Prerequisites

- **CMake** (version 3.10 or higher recommended)
- **C++ Compiler** (MSVC, GCC, or Clang)
- **Git** (for cloning GoogleTest)
- **GoogleTest** (already included as a submodule in `extern/googletest`)

---

## 1. Clone the Repository

If you haven't already, clone your project and initialize submodules:

```sh
git clone <your-repo-url>
cd "Project 3"
git submodule update --init --recursive
```

---

## 2. Directory Structure

Your project should look like this:

```
Project 3/
│
├── CryptoCalc/
│   ├── include/
│   └── src/
├── test/
│   └── Transaction_test.cpp
├── extern/
│   └── googletest/
├── CMakeLists.txt
```

---

## 3. Build the Project

Open a terminal in the project root (`Project 3`) and run:

```sh
rmdir /s /q build      
mkdir build
cd build
cmake ..
cmake --build .
```
---

## 4. Run the Application

After building, you will find the main executable in the `build` folder:

```sh
CryptoCalc.exe
```

---

## 5. Run the Tests

The test executable will also be in the `build` folder:

```sh
CryptoCalcTests.exe
```

Or, if you are using CTest (from the `build` directory):

```sh
ctest
```

---

## 6. Troubleshooting

- **No `.exe` files in build folder?**
  - Double-check that all source file paths in `CMakeLists.txt` are correct.
  - Make sure you are in the correct directory and that the build completed without errors.
  - Clean the build folder and try again.

- **GoogleTest not found?**
  - Ensure you have run `git submodule update --init --recursive`.

---

## 7. CMakeLists.txt Reference

Make sure your `CMakeLists.txt` uses the correct paths. Example:

```cmake
cmake_minimum_required(VERSION 3.31)
project(CryptoCalc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(extern/googletest)

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

enable_testing()

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

target_link_libraries(CryptoCalcTests
    PRIVATE
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(CryptoCalcTests)
```

---

## 8. Notes

- If your folder names have spaces (e.g., `CryptoCalc 3`), use quotes in CMake paths:  
  `"CryptoCalc 3/src/main.cpp"`
- Always run CMake from a clean build directory after changing source file paths.

