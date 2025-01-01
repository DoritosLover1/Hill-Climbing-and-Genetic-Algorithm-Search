#include "Checkboard.h"

void Checkboard::print_board()
{
	for (const auto& layer : board) {
		for (const auto& row : layer) {
			std::cout << row << " ";
		}
		std::cout << "\n";
	}

}

int Checkboard::count_conflicts() const
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
			if (i + 1 < size && board[i][j] == board[i + 1][j]) count++;
			if (j + 1 < size && board[i][j] == board[i][j + 1]) count++;
        }
    }
    return count;
}

size_t Checkboard::get_color_size() {
	return color_size;
}

bool Checkboard::is_goal_state() const
{
	return count_conflicts() == 0;
}

int Checkboard::get_size()
{
	return size;
}

void Checkboard::mutate()
{
	int dist = rand() % size;
	int dist2 = rand() % size;
	int color = rand() % color_size;

	int i = dist;
	int j = dist2;
	board[i][j] = color;

}

Checkboard Checkboard::crossover(const Checkboard& p1, const Checkboard& p2)
{
	int size_ = p1.size;
	Checkboard ch(size_, p1.color_size);

	int cross_over_point = rand() % 10;
	for (int i = 0; i < size_; i++) 
	{
		for (int j = 0; j < size_; j++)
		{
			(i < cross_over_point) ? ch.set_color(i, j, p1.board[i][j]) : ch.set_color(i, j, p2.board[i][j]);
		}
	}
	return ch;
}

void Checkboard::set_color(int row, int col, int color) {
    if (row >= 0 && row < size && col >= 0 && col < size && color >= 0 && color < 4) {
        board[row][col] = color;
    }
}

std::vector<std::vector<int>>& Checkboard::get_board()
{
	return board;
}

