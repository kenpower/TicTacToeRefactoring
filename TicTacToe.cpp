#include "pch.h"
#include "TicTacToe.h"

const int NUM_CELLS = 9;
const char EMPTY_CELL = '-';

TicTacToe::TicTacToe(char* b) {
	for (int i = 0; i < NUM_CELLS; i++)
		grid[i] = b[i];
}

int TicTacToe::scoreFor(char player) {
	const int WIN = 100;

	if (winner() == player) return WIN;
	
	char opponent = player == 'X' ? 'O' : 'X';
	Move nextMove = bestMoveFor(opponent);

	return  -nextMove.score;
}

int TicTacToe::bestSquareFor(char player) {
	return bestMoveFor(player).square;
}

Move TicTacToe::bestMoveFor(char player) {
	const int DRAW = 0;
	const Move NoMove{ -1, DRAW };

	Move bestMove = NoMove;
	for (int position = 0; position < NUM_CELLS; position++) {
		if (!occupied(position)) {
			TicTacToe gameAfterMove = play(position, player);
			Move thisMove = { position, gameAfterMove.scoreFor(player) };
			if (thisMove.score > bestMove.score || bestMove.square == -1)
				bestMove = thisMove;
			if (thisMove.score == 100)
				break;
		}
	}

	return bestMove;
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

	const int NUM_LINES = 7;
	const int lines[][3] = {
		{TL,TM,TR}, {ML, MM, MR}, {BL, BM, BR},
		{TL, ML, BL}, {TM, MM, BM}, {TR, MR, BR},
		{TL, MM, BR}, {TR, MM, BL}
	};

	for(int i=0; i< NUM_LINES; i++)
		if (threeInARow(lines[i][0], lines[i][1], lines[i][2]))
			return grid[lines[i][0]];
	
	return EMPTY_CELL;
}