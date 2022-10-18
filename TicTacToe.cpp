#include "pch.h"
#include "TicTacToe.h"

TicTacToe::TicTacToe(char* b) {
	for (int i = 0; i < 9; i++)
		grid[i] = b[i];
}


int TicTacToe::bestMoveFor(char player) {
	const int NoMove = -1;
	for (int move = 0; move < 9; move++) {
		if (grid[move] == '-') {
			TicTacToe t = play(move, player);
			if (t.winner() == player) return move;
		}
	}
	for (int move = 0; move < 9; move++)
		if (grid[move] == '-')
			return move;
	return NoMove;
}

TicTacToe TicTacToe::play(int i, char player) {
	TicTacToe t(grid);
	t.grid[i] = player;
	return t;
}

char TicTacToe::threeInARow(int a, int b, int c) {
	return grid[a] != '-' && grid[a] == grid[b] && grid[b] == grid[c];
}

char TicTacToe::winner() {
	if (threeInARow(0,1,2))
		return grid[0];
	if (threeInARow(3, 4, 5))
		return grid[0]; 
	if (threeInARow(6, 7, 8))
		return grid[0]; 
	
	return '-';
}