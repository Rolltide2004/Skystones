#ifndef STONE
#define STONE
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Stone{
	private:
		char top;
		char l;
		char r;
		char bot;
		string name;
		char team;
	public:
		Stone(char t='-', char l='-', char r='-', char b='-');
		void printStone();
		void printTop();
		void printMid();
		void printBot();
		void setStone(char t='-', char l='-', char r='-', char b='-');
		void setTeam(char s);
		char getTop();
		char getBot();
		char getL();
		char getR();

		void setTop(char c);
		void setBot(char c);
		void setL(char c);
		void setR(char c);

		char getTeam();
		bool isEmpty();
		bool operator==(const Stone& a);
};
#endif
