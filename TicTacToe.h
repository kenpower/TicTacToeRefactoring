#pragma once
class TicTacToe
{
	char grid[9];

	char threeInARow(int a, int b, int c);
	bool TicTacToe::occupied(int cell);
public:
	TicTacToe(char* b);
	
	int bestMoveFor(char player);
	
	TicTacToe play(int i, char player);
	
	char winner();
};

