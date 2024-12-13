# Push_swap

**Push_swap** is a C program designed to sort a stack of integers with the fewest moves possible using a limited set of instructions. The project involves implementing sorting algorithms with attention to algorithmic complexity, enabling you to sort data in an optimized manner using stack manipulation.

<br>

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/dracudev/Push-Swap.git
   ```
2. Navigate into the cloned directory and run make. This will compile all the source files and create the program.

   ```bash
   cd Push-Swap
   make
   ```
   
3. Run the program with a list of integers as arguments:
   ```bash
   ./push_swap 2 1 3 6 5 8
   ```   
4. Or run it using a string:
   ```bash
   ./push_swap "1 -45 92 2 34"
   ```

5. Additional Makefile Commands:

  - `make clean`: Removes all the object files (*.o) created during the compilation process. This is useful for cleaning up the directory without removing the compiled libraries and the game.
    
  - `make fclean`: Performs a deeper clean by removing all the object files as well as the compiled libraries and the game. This essentially resets the directory to its initial state before compilation.

  - `make re`: Combines the fclean and make commands to first remove all compiled files and then recompile the entire game. This is useful if you want to ensure a completely fresh build.

<br>

## Project Summary

The **Push_swap** project focuses on developing sorting algorithms with optimized performance in C, emphasizing efficiency in terms of the number of operations. The program must output the minimal sequence of stack instructions to sort an unsorted stack. It’s a valuable exercise in understanding algorithm complexity and optimizing for the fewest moves.

### Objectives
- Developing and optimizing sorting algorithms.
- Managing stack data structures and memory in C.
- Minimizing algorithmic complexity to improve performance.

<br>

## Features

- **Sorting with Minimal Operations**: The program calculates the smallest sequence of instructions to sort the input stack in ascending order.
- **Two-Stack System**: Uses two stacks, `a` and `b`, where:
  - `a` starts with all input integers.
  - `b` is used as a temporary stack.
- **Instruction Set**: Includes the following operations for stack manipulation:
  - `sa`, `sb`, `ss` — Swap the first two elements in stacks `a` and `b`.
  - `pa`, `pb` — Push the top element from one stack to the other.
  - `ra`, `rb`, `rr` — Rotate stack elements up by one.
  - `rra`, `rrb`, `rrr` — Reverse rotate stack elements down by one.
- **Error Handling**: The program validates input for non-integer values, duplicates, and other invalid data, outputting "Error" for any issues.

<br>

## Example Usage

Here’s a sample sequence for sorting a stack using `push_swap`:

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

In this example, push_swap outputs the smallest series of instructions to sort the stack.

<br>

## Checker

- The **Checker** is a utility to verify the correctness of your sorting algorithm. It checks whether the sequence of operations returned by the `push_swap` program sorts the stack properly.
- **Usage**:
   - Download the checker binary provided and place it in the same directory as your executable.
   - Before running, make sure the checker has executable permissions:
     ```bash
     chmod +x checker_Mac  # or checker_Linux
     ```
   - Test the output of your program with:
     ```bash
     ARG="4 10 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
     ```

<br>

## Benchmarks

To validate the efficiency of the solution:
- Sorting `3` elements should require **2 or 3** instructions.
- Sorting `5` elements should require **no more than 12** instructions.
- Sorting `100` elements should take fewer than **1500** instructions.
- Sorting `500` elements should take fewer than **11500** instructions.
