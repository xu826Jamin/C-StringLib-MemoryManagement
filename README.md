# C-StringLib-MemoryManagement
## Overview
This project is Lab 3 of the McMaster Principles of Programming course, designed to deepen understanding of string manipulation, dynamic memory allocation, and sorting algorithms. It solves the problem of implementing fundamental string operations from scratch and managing a dynamic list of words read from a file. This matters as it builds a strong foundation in low-level memory management and pointer arithmetic, which are crucial for systems programming.

## Features
- **Custom String Library**: Implementation of core string functions including `my_strlen`, `my_strcmp`, `my_strcmpOrder`, and `my_strcat`.
- **Dynamic Word List Management**: Reads a variable number of words from a file (`wordlist.txt`) using dynamic memory allocation.
- **Sorting Algorithms**: Implements both Bubble Sort and Selection Sort to organize the word list alphabetically.
- **Memory Safety**: Includes a `delete_wordlist` function to properly free all allocated memory, preventing leaks.
- **Edge Case Handling**: Handles file open failures and memory allocation errors gracefully.

## Tech Stack
- **Language**: C
- **Build System**: GNU Make
- **Testing**: Custom test harness (`testCases.c`)
- **Scripting**: Bash (`run.sh`) for test execution

## Design Decisions
**Fixed Buffer for Input Reading**: In `read_words`, a temporary buffer of 100 characters (`tempLine`) is used to read each line before allocating the exact amount of memory needed for the word.
- **Tradeoff**: This simplifies the reading logic significantly compared to reading character-by-character to determine length first. However, it imposes a hard constraint that no word in the input file can exceed 99 characters. This was chosen to balance implementation complexity with the expected input data constraints.

## How to Run
1. **Compile the project**:
   Open a terminal in the project directory and run:
   ```bash
   make
   ```
2. **Run the tests**:
   Execute the test suite using the provided script:
   ```bash
   make test
   ```
   Or manually run the executable:
   ```bash
   ./Lab3
   ```

## What I Learned
- **Pointer Arithmetic**: Gained proficiency in manipulating strings using pointers (`char *`) instead of array indexing.
- **Double Pointers**: Understood how to use `char **` to manage arrays of strings.
- **Dynamic Memory**: Learned to effectively use `malloc` and `free` for jagged arrays (arrays of strings of varying lengths).
- **Algorithm Implementation**: Reinforced knowledge of Bubble Sort and Selection Sort by implementing them for string data.
