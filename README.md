Checkboard Optimization Algorithms ⚙️

This project implements a simulation of optimization algorithms on a colored checkboard problem. Two algorithms are used:

Hill Climbing ⚡

Genetic Algorithm 🧬

The goal is to reduce conflicts on a checkboard where adjacent cells of the same color are considered conflicts. The project demonstrates these algorithms by outputting their results to a file.

Features ✨

Checkboard Generation: Creates a randomized checkboard with a specified size and number of colors.

Conflict Counting: Counts the number of adjacent cells with the same color.

Hill Climbing Algorithm: Attempts to find a local minimum for conflicts.

Genetic Algorithm: Evolves a population of checkboards to reduce conflicts, aiming for an optimal solution.

Results Output: Saves the initial and final states of the checkboard and the number of conflicts to a file.

File Structure 📁

Checkboard.h: Header file for the Checkboard class.

Checkboard.cpp: Implementation of the Checkboard class.

main.cpp: Contains the main function and implements the hill climbing and genetic algorithms.

assignment_2-output.txt: Output file where results are saved.

How to Run 🏋️‍♂️

Prerequisites

A C++ compiler (e.g., g++, clang++)

C++17 or higher is recommended.

Compilation

Use the following command to compile the project:

g++ -std=c++17 main.cpp Checkboard.cpp -o checkboard

Execution

Run the compiled program:

./checkboard

Output

The results will be saved to assignment_2-output.txt. Each execution will append results to the file, so you can compare multiple runs.

Algorithms Overview 🎯

Hill Climbing ⚡

Generates an initial random checkboard.

Iteratively modifies the board by changing the color of a single cell to reduce the number of conflicts.

Stops when no better solution can be found or the goal state (0 conflicts) is achieved.

Genetic Algorithm 🧬

Initializes a population of random checkboards.

Iteratively evolves the population through selection, crossover, and mutation.

Uses elitism to preserve the best solutions from one generation to the next.

Stops after a fixed number of generations or if an optimal solution is found.

Configuration 🔧

The following parameters can be modified in main.cpp:

Hill Climbing:

size: Size of the checkboard (default: 10).

color_number: Number of colors (default: 4).

Genetic Algorithm:

population_size: Number of individuals in the population (default: 10).

generations: Number of generations to run (default: 100).

elitism: Number of top individuals to preserve (default: 3).

color_size: Number of colors (default: 4).

Example Output 🗒

An example output in assignment_2-output.txt:

Hill Climbing Algorithm

Initial State:
0 1 2 3 1 2 3 0 1 2
...
Conflicts Number: 12

Solution:
0 1 2 3 1 2 3 0 1 2
...

Genetic Algorithm with Population size = 10, Generations = 100
Genetic Algorithm Solution (Optimal):
0 1 2 3 1 2 3 0 1 2
...

Limitations ⚠

Hill Climbing: May get stuck in local minima.

Genetic Algorithm: Performance depends on parameters like population size and mutation rate.

License 🔒

This project is free to use for educational purposes. Attribution is appreciated.

Feel free to modify the parameters or algorithms to explore different scenarios! 🚀
