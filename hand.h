#ifndef HAND
#define HAND
#include "stone.h"
using namespace std;

class Hand{
	public:
		Hand();
		void printHand();
		void add(Stone s, char l);
		Stone placeStone(int p);
		Stone getStone(int p);
		void clearStone(int p);
	private:
		vector<Stone> hand{Stone()};
};
#endif