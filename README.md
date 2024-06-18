# Sudoku Solver using Backtracking

This repository contains a C++ program that solves Sudoku puzzles using the backtracking algorithm. This project is developed for the "Data Structures and Algorithms I" course and demonstrates the application of backtracking to find a solution to a Sudoku puzzle.

## Overview

Sudoku is a logic-based, combinatorial number-placement puzzle. The objective is to fill a 9x9 grid with digits so that each column, each row, and each of the nine 3x3 subgrids contain all of the digits from 1 to 9. The program uses backtracking to solve the puzzle by trying to fill each empty cell with a number and recursively checking if it leads to a solution.

## Features

- **Input Grid:** A 9x9 grid with some cells pre-filled and others empty (denoted by 0).
- **Backtracking Algorithm:** Attempts to place numbers 1-9 in empty cells and backtracks if a number leads to a conflict.
- **Validation:** Ensures that the number placement adheres to Sudoku rules.
- **Output:** Displays the solved Sudoku grid or indicates if no solution exists.

## Implementation Details

- **Language:** C++
- **Algorithm:** Backtracking
- **Input:** 9x9 integer grid with empty cells marked as 0.
- **Output:** Solved 9x9 grid or a message indicating no solution.

## Usage

1. **Initialize Grid:** Define the initial state of the Sudoku puzzle in the `grid` array.
2. **Compile and Run:**
   - Compile the program using a C++ compiler.
   - Run the executable.
3. **Output:** The program prints the solved Sudoku grid or a message indicating that no solution exists.

## Example

Given the following initial grid:

    0 0 4 2 5 0 0 6 0
    0 0 0 0 3 0 0 0 4
    0 0 0 0 0 0 0 0 0
    0 0 0 3 0 0 0 0 0
    3 8 6 7 0 0 4 0 0
    0 0 9 0 0 6 0 0 1
    0 5 2 8 7 0 6 4 3
    6 3 0 1 0 5 2 0 0
    0 0 0 0 2 3 5 0 7

The program will output the solved grid:

    7 9 4 2 5 1 3 6 8
    2 6 5 9 3 8 1 7 4
    8 1 3 4 6 7 9 5 2
    5 7 1 3 9 4 8 2 6
    3 8 6 7 1 2 4 9 5
    4 2 9 5 8 6 7 3 1
    1 5 2 8 7 9 6 4 3
    6 3 7 1 4 5 2 8 9
    9 4 8 6 2 3 5 1 7
