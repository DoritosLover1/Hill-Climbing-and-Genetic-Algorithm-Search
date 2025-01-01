#pragma once
#include <vector>
#include <ctime>
#include <iostream>

// 0: DB, 1: B, 2: R, 3: O
class Checkboard
{
private:
    size_t size;
    std::vector<std::vector<int>> board;
    size_t color_size;

public:
    Checkboard() {
        size = 10;
        color_size = 4;
        board.resize(size, std::vector<int>(size));
        srand(time(0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = rand() % color_size;
            }
        }
    }

    Checkboard(int size, size_t color_size) {
        this->size = size;
        board.resize(size, std::vector<int>(size));
        srand(time(0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = rand() % color_size;
            }
        }
    }
    size_t get_color_size();
    void print_board();
    int count_conflicts() const;
    bool is_goal_state() const;
    std::vector<std::vector<int>>& get_board();
    void set_color(int row, int col, int color);
    int get_size();
    void mutate();
    static Checkboard crossover(const Checkboard& p1, const Checkboard& p2);
};
