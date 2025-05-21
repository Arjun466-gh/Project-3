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
Watch the project walkthrough on YouTube: https://youtu.be/JIqR_T90lMM?si=Ba9TrvZlRZDqkIZR
