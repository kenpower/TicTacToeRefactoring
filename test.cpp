#include "pch.h"
#include "TicTacToe.h"

TEST(TicTacToe, ValidMove5) {
	TicTacToe ttt("XOXOX-OXO");
	EXPECT_EQ(5, ttt.bestMoveFor('X'));
}

TEST(TicTacToe, ValidMove8) {
	TicTacToe ttt("XOXOXOOX-");
	EXPECT_EQ(8, ttt.bestMoveFor('X'));
}

TEST(TicTacToe, ValidMove0) {
	TicTacToe ttt("---------");
	EXPECT_EQ(8, ttt.bestMoveFor('X'));
}

TEST(TicTacToe, ValidMoveNone) {
	TicTacToe ttt("XXXXXXXX");
	EXPECT_EQ(-1, ttt.bestMoveFor('X'));
}

TEST(TicTacToe, WinningMove) {
	TicTacToe ttt("XO-XX-OOX");
	EXPECT_EQ(5, ttt.bestMoveFor('X'));
}
