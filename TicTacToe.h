#pragma once
class TicTacToe
{
	char grid[9];
public:
	TicTacToe(char* b);
	
	int bestMoveFor(char player);
	
	TicTacToe play(int i, char player);
	
	char winner();
};

