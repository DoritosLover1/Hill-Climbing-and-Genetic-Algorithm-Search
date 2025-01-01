#include <iostream>
#include <fstream>
#include <algorithm>
#include "Checkboard.h"



Checkboard hill_climbing(Checkboard board) {
    Checkboard current_board = board;
    int current_conflicts = current_board.count_conflicts();
    int size = current_board.get_size();
    size_t color_number = current_board.get_color_size();

    int attempts = 0;

    while (true) {
        if (current_board.is_goal_state()) {
            return current_board;
        }

        Checkboard best_board = current_board;
        int best_conflicts = current_conflicts;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int current_color = current_board.get_board()[i][j];

                for (int new_color = 0; new_color < color_number; new_color++) {
                    if (current_color != new_color) {
                        Checkboard temp = current_board;
                        temp.set_color(i, j, new_color);

                        int temp_conflicts = temp.count_conflicts();

                        if (temp_conflicts < best_conflicts) {
                            best_board = temp;
                            best_conflicts = temp_conflicts;
                        }
                    }
                }
            }
        }

        if (best_conflicts >= current_conflicts) {
            attempts++;
        }
        else {
            current_board = best_board;
            current_conflicts = best_conflicts;
        }
    }

    return current_board;
}

Checkboard genetic_algorithm(int size, int population_size, int generations, int elitism_count, size_t color_size) {
    std::vector<Checkboard> population;

    for (int i = 0; i < population_size; ++i) {
        population.emplace_back(Checkboard(size, color_size));
    }

    for (int generation = 0; generation < generations; ++generation) {
        std::sort(population.begin(), population.end(), [](const Checkboard& a, const Checkboard& b) {
            return a.count_conflicts() < b.count_conflicts();
            });

        if (population[0].is_goal_state()) {
            return population[0];
        }

        std::vector<Checkboard> new_population;


        // Generate the rest of the new population
        for (int i = elitism_count; i < population_size; ++i) {
            Checkboard p1 = population[rand() % (population_size / 2)];
            Checkboard p2 = population[rand() % (population_size / 2)];

            Checkboard child = Checkboard::crossover(p1, p2);

            child.mutate();

            new_population.push_back(child);
        }
        population = new_population;
    }

    std::sort(population.begin(), population.end(), [](const Checkboard& a, const Checkboard& b) {
        return a.count_conflicts() < b.count_conflicts();
        });

    return population[0];
}


int main() {

    std::fstream outfile3;
    outfile3.open("assignment_2-output.txt", std::ios_base::app);
    outfile3 << "Hill Climbing Algorithm\n";
    outfile3.close();

    for (int i = 0; i < 10; i++) {
        
        //Hill Climbing
        {
            int size = 10;
            size_t color_number = 4;
            std::fstream outfile;
            outfile.open("assignment_2-output.txt", std::ios_base::app);

            Checkboard board(size, color_number);
            outfile << "\nInitial State: \n";
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    outfile << board.get_board()[i][j] << " ";
                }
                outfile << "\n";
            }
            outfile << "Conflicts Number: " << board.count_conflicts() << "\n";

            Checkboard result = hill_climbing(board);
            if (result.is_goal_state()) {
                outfile << "\nSolution: \n";
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        outfile << result.get_board()[i][j] << " ";
                    }
                    outfile << "\n";
                }
            }
            else {
                outfile << "There is not a certain solution, just the optimal one.\n";
            }
            outfile.close();
        }
    }

    std::fstream outfile2;
    outfile2.open("assignment_2-output.txt", std::ios_base::app);
    outfile2 << "\nGenetic Algorithm  with Population size= 100, Generations = 1000";
    outfile2.close();

    for (int i = 0; i < 10; i++) {
        //Genetic Search
        {
            std::fstream outfile;
            outfile.open("assignment_2-output.txt", std::ios_base::app);

            srand(time(0));
            int size = 10;
            int population_size = 10;
            int generations = 100;
            int elitism = 3;
            size_t color_size = 4;
            Checkboard solution = genetic_algorithm(size, population_size, generations, elitism, color_size);

            outfile << "Genetic Algorithm Solution (Optimal):\n";
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    outfile << solution.get_board()[i][j] << " ";
                }
                outfile << "\n";
            }

            outfile.close();
        }
    }
   
    return 0;
}