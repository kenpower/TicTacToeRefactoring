#pragma once
class TicTacToe
{
	char grid[9];
public:
	TicTacToe(char* b) {
		for (int i = 0; i < 9; i++)
			grid[i] = b[i];
	}
	
	
	int move(char player) {
		for (int i = 0; i < 9; i++) { 
			if (grid[i] == '-') { 
				TicTacToe t = play(i, player); 
				if (t.winner() == player) return i; 
			}
		}
		for (int i = 0; i < 9; i++)
			if (grid[i] == '-')
				return i;
		return -1;
	}	
	
	TicTacToe play(int i, char player) {
		TicTacToe t(grid);
		t.grid[i] = player;
		return t;
	}
	
	char winner() {
		if (   grid[0] != '-' 
			&& grid[0] == grid[1] 
			&& grid[1] == grid[2])
			   return grid[0];
		if (   grid[3] != '-' 
			&& grid[3] == grid[4] 
			&& grid[4] == grid[5])
			return grid[3]; 
		if (   grid[6] != '-' 
			&& grid[6] == grid[7] 
			&& grid[7] == grid[8])
			return grid[6]; return '-';
	 }
};

