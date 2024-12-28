#include "board.cpp"
#include "hand.cpp"
#include "stone.cpp"
using namespace std;

void printGame(Hand, Hand, Board);

int main(){

	Board b;
	Hand hand1, hand2;

	Stone s1('1','0','1','0');
	Stone s2('0','2','0','2');
	Stone s3('3','0','3','0');
	Stone s4('1','2','3','4');
	Stone s5('2','2','2','2');

	Stone s6('0','1','0','1');
	Stone s7('2','0','2','0');
	Stone s8('0','3','0','3');
	Stone s9('4','3','2','1');
	Stone s0('2','2','2','2');
//add stone to first available hand slot
//if none available nothing happens
	hand1.add(s1, '#');
	hand1.add(s2, '#');
	hand1.add(s3, '#');
	hand1.add(s4, '#');
	hand1.add(s5, '#');

	hand2.add(s6, '@');
	hand2.add(s7, '@');
	hand2.add(s8, '@');
	hand2.add(s9, '@');
	hand2.add(s0, '@');
	
	int in, pos;
	bool turn=true;
	Stone temp;
do{
	printGame(hand1, hand2, b);

	if(turn){
		cout<<"P#: "<<endl;
		do{
			cout<<"Stone: "; cin>>in;
		}while(in<1 || in>5 || hand1.getStone(in).isEmpty());
		do{
			cout<<"Position: "; cin>>pos;
		}while(pos<1 || pos>9 || !b.isEmpty(pos));
		if(b.placeStone(hand1.getStone(in), pos)){
			hand1.clearStone(in);
			b.fight(pos);
			cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		}
	}else{
		cout<<"P@: "<<endl;
		do{
			cout<<"Stone: "; cin>>in;
		}while(in<1 || in>5 || hand2.getStone(in).isEmpty());
		do{
			cout<<"Position: "; cin>>pos;
		}while(pos<1 || pos>9 || !b.isEmpty(pos));
		
		if(b.placeStone(hand2.getStone(in), pos)){
			hand2.clearStone(in);
			b.fight(pos);
			cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
		}
	}
	turn = !turn;
}while(b.hasSpace());
		
	printGame(hand1, hand2, b);
	cout<<endl;
	
	if(b.getScore1() > b.getScore2()){
		cout<<"PLAYER # WINS!"<<endl<<endl;
	}else
		cout<<"PLAYER @ WINS!"<<endl<<endl;

return 0;
}

void printGame(Hand h1, Hand h2, Board b){
	h2.printHand();
	cout<<"------------------------------------"<<endl;
	b.printBoard();
	cout<<"------------------------------------"<<endl;
	h1.printHand();
}
