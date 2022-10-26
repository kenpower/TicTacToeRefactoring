#include "pch.h"
#include "TicTacToe.h"

const int NUM_CELLS = 9;
const char EMPTY_CELL = '-';

TicTacToe::TicTacToe(char* b) {
	for (int i = 0; i < NUM_CELLS; i++)
		grid[i] = b[i];
}


int TicTacToe::bestMoveFor(char player) {
	const int NoMove = -1;
	int result = NoMove;
	for (int move = 0; move < NUM_CELLS; move++) {
		if (!occupied(move)) {
			TicTacToe t = play(move, player);
			if (t.winner() == player){
				result = move;
				break;
			}	
			if (!occupied(move))
				result = move;
		}
	}

	return result;
}

TicTacToe TicTacToe::play(int i, char player) {
	TicTacToe t(grid);
	t.grid[i] = player;
	return t;
}

char TicTacToe::threeInARow(int a, int b, int c) {
	return occupied(a) && grid[a] == grid[b] && grid[b] == grid[c];
}

bool TicTacToe::occupied(int cell) {
	return grid[cell] != EMPTY_CELL;
}

char TicTacToe::winner() {
	const int TL = 0, TM = 1, TR = 2;
	const int ML = 3, MM = 4, MR = 5;
	const int BL = 6, BM = 7, BR = 8;

	if (threeInARow(TL,TM,TR))
		return grid[TL];
	if (threeInARow(ML, MM, MR))
		return grid[ML]; 
	if (threeInARow(BL, BM, BR))
		return grid[BL]; 
	
	return EMPTY_CELL;
}