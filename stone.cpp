#include "stone.h"
Stone::Stone(char t, char le, char ri, char b){
	top = t;
	l = le;
	r = ri;
	bot = b;
	team = '*';
}
void Stone::printStone(){
	printTop();
	cout<<endl;
	printMid();
	cout<<endl;
	printBot();
	cout<<endl;
}
void Stone::setTeam(char s){
	team = s;
}
char Stone::getTeam(){
	return team;
}
bool Stone::operator==(const Stone& a){
	if(this->top == a.top && this->l == a.l && this->r == a.r && this->bot == a.bot)
		return true;
	return false;
}

void Stone::printTop(){
	cout<<" "<<top<<" ";
}
void Stone::printMid(){
	cout<<l<<team<<r;
}
void Stone::printBot(){
	cout<<" "<<bot<<" ";
}

void Stone::setStone(char t, char le, char ri, char b){
	this->top = t;
	this->l = le;
	this->r = ri;
	this->bot = b;
}

char Stone::getTop(){ return top; }
char Stone::getBot(){ return bot; }
char Stone::getL(){ return l; }
char Stone::getR(){ return r; }

void Stone::setTop(char c){ top=c; }
void Stone::setBot(char c){ bot=c; }
void Stone::setL(char c){ l=c; }
void Stone::setR(char c){ r=c; }

bool Stone::isEmpty(){
	if(top == '-' && l == '-' && r == '-' && bot == '-'){
		return true;
	}else
		return false;
}
