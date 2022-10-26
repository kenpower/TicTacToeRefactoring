#include "pch.h"
#include "TicTacToe.h"

TEST(TicTacToe, ValidMove5) {
	TicTacToe ttt("XOXOX-OXO");
	EXPECT_EQ(5, ttt.bestSquareFor('X'));
}

TEST(TicTacToe, ValidMove8) {
	TicTacToe ttt("XOXOXOOX-");
	EXPECT_EQ(8, ttt.bestSquareFor('X'));
}

TEST(TicTacToe, ValidMove0) {
	TicTacToe ttt("---------");
	int move = ttt.bestSquareFor('X');
	EXPECT_TRUE(	
		0 == move ||
		1 == move ||
		2 == move ||
		3 == move ||
		4 == move ||
		5 == move ||
		6 == move ||
		7 == move ||
		8 == move 
	);
}

TEST(TicTacToe, ValidMoveNone) {
	TicTacToe ttt("XXXXXXXX");
	EXPECT_EQ(-1, ttt.bestSquareFor('X'));
}

TEST(TicTacToe, WinningMove) {
	TicTacToe ttt(
		"OO-"
		"XX-"
		"OOX");
	EXPECT_EQ(5, ttt.bestSquareFor('X'));
}

TEST(TicTacToe, WinningMoveVertical) {
	TicTacToe ttt(
		"-O-"
		"XO-"
		"XOX");
	
	EXPECT_EQ(0, ttt.bestSquareFor('X'));
}

TEST(TicTacToe, WinningMoveDiagonal) {
	TicTacToe ttt(
		"XO-"
		"X--"
		"OOX");
	
	EXPECT_EQ(4, ttt.bestSquareFor('X'));
}