#include "hand.h"
Hand::Hand(){
	for(int i=0; i<5; i++){
		hand.push_back(Stone());
	}
}
void Hand::printHand(){
	for(int i=0; i<5; i++){
		hand[i].printTop();
		cout<<"\t";
	}cout<<endl;
	for(int i=0; i<5; i++){
		hand[i].printMid();
		cout<<"\t";
	}cout<<endl;
	for(int i=0; i<5; i++){
		hand[i].printBot();
		cout<<"\t";
	}cout<<endl;
}

void Hand::add(Stone s, char l){
	for(int i=0; i<5; i++){
		if(hand[i].isEmpty()){
			hand[i] = s;
			hand[i].setTeam(l);
			break;
		}
	}
}
Stone Hand::placeStone(int p){
	Stone test;
	if(hand[(p-1)] == test){
		cout<<"/////////////////////////////////error\n";
		return Stone();
	}else{
		Stone retVal = hand[(p-1)];
		hand[(p-1)] = Stone();
		return retVal;
	}
	return Stone();
}
void Hand::clearStone(int p){
//	if(p>0 && p<6)
	hand[(p-1)] = Stone();
}
Stone Hand::getStone(int p){
	return hand[(p-1)];
}

