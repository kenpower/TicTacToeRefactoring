#pragma once

struct Move {
	int square;
	int score;
};

class TicTacToe
{
	char grid[9];

	char threeInARow(int a, int b, int c);
	bool TicTacToe::occupied(int cell);
	int scoreFor(char);
	Move bestMoveFor(char player);
public:
	TicTacToe(char* b);
	
	int bestSquareFor(char player);
	
	TicTacToe play(int i, char player);
	
	char winner();
};

