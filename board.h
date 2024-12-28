#ifndef BOARD
#define BOARD
#include "stone.h"
using namespace std;

class Board{
	private:
		vector<vector<Stone>> board{3, vector<Stone>(3, Stone())};
		int score1 = 0;
		int score2 = 0;
	public:
		Board();
		pair<int, int> coord(int pos);
		void fight(int pos);
		int getScore1();
		int getScore2();
		void printBoard();
//		bool placeStone(Stone s, pair<int, int> xy);
		bool placeStone(Stone s, int pos);
		bool hasSpace();
		bool isEmpty(int pos);
};
#endif