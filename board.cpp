#include "board.h"
Board::Board(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i].push_back(Stone());
		}
	}
}
void Board::printBoard(){
	cout<<"P@: "<<getScore2()<<" | ";	
	for(int i=2; i>=0; i--){
		if(i<2)cout<<"      | ";
		for(int j=0; j<3; j++){
			board[i][j].printTop();
			if(j!=2)cout<<"\t";
		}
		cout<<" |"<<endl<<"      | ";
		
		for(int j=0; j<3; j++){
			if(board[i][j].isEmpty()){
				if(i==0){
					if(j==0) board[i][j].setTeam('7');
					if(j==1) board[i][j].setTeam('8');
					if(j==2) board[i][j].setTeam('9');
				}else if(i==1){
					if(j==0) board[i][j].setTeam('4');
					if(j==1) board[i][j].setTeam('5');
					if(j==2) board[i][j].setTeam('6');
				}else{
					if(j==0) board[i][j].setTeam('1');
					if(j==1) board[i][j].setTeam('2');
					if(j==2) board[i][j].setTeam('3');
				}
			}
			board[i][j].printMid();
			if(j!=2)cout<<"\t";
		}
		cout<<" |"<<endl<<"      | ";
		for(int j=0; j<3; j++){
			board[i][j].printBot();
			if(j!=2)cout<<"\t";
		}
		cout<<" |"<<endl;
		if(i==0){
			cout<<"P#: "<<getScore1()<<" |                     |"<<endl;
		}else
			cout<<"      |                     |"<<endl;
	}
}

bool Board::placeStone(Stone s, int pos){
	pair<int, int> xy = coord(pos);
	if(board[xy.first][xy.second].isEmpty()){
		board[xy.first][xy.second] = s;
		return true;
	}
	return false;
}
bool Board::hasSpace(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j].isEmpty())
				return true;
		}
	}
	return false;
}
bool Board::isEmpty(int pos){
	pair<int, int> xy = coord(pos);
	if(board[xy.first][xy.second].isEmpty())
		return true;
	return false;
}
int Board::getScore1(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j].getTeam() == '#') score1++;
		}
	}
	return score1; }
int Board::getScore2(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j].getTeam() == '@') score2++;
		}
	}
	return score2; }

pair<int, int> Board::coord(int pos){
	pair<int, int> xy;
	if(pos<4 && pos>0){
		xy.first=2;}
	else if(pos>6 && pos<10){
		xy.first=0;}
	else if(pos<7 && pos>3){
		xy.first=1;}
	xy.second = (pos-1)%3;
	return xy;
}

void Board::fight(int pos){
//set edge stones' outside edge to '-'
	for(int i=0; i<3; i++){
		if(!board[i][0].isEmpty())
			board[i][0].setL('-');
		if(!board[0][i].isEmpty())
			board[0][i].setBot('-');
		if(!board[i][2].isEmpty())
			board[i][2].setR('-');
		if(!board[2][i].isEmpty())
			board[2][i].setTop('-');
	}

	pair<int, int> xy = coord(pos);
//evaluate placed stone taking above/below stones
	if(pos<4 && !board[xy.first-1][xy.second].isEmpty()){
		if(board[xy.first][xy.second].getBot() > board[xy.first-1][xy.second].getTop())
			board[xy.first-1][xy.second].setTeam(board[xy.first][xy.second].getTeam());
	}
	if(pos>6 && !board[xy.first+1][xy.second].isEmpty()){
		if(board[xy.first][xy.second].getTop() > board[xy.first+1][xy.second].getBot())
			board[xy.first+1][xy.second].setTeam(board[xy.first][xy.second].getTeam());
	}
	if(pos<7 && pos>3){
		if(!board[xy.first-1][xy.second].isEmpty()){
			if(board[xy.first][xy.second].getBot() > board[xy.first-1][xy.second].getTop())
				board[xy.first-1][xy.second].setTeam(board[xy.first][xy.second].getTeam());
		}
		if(!board[xy.first+1][xy.second].isEmpty()){
			if(board[xy.first][xy.second].getTop() > board[xy.first+1][xy.second].getBot())
				board[xy.first+1][xy.second].setTeam(board[xy.first][xy.second].getTeam());
		}
	}
//evaluate placed stone taking right/left stones
	if(xy.second==0 && !board[xy.first][xy.second+1].isEmpty()){
		if(board[xy.first][xy.second].getR() > board[xy.first][xy.second+1].getL())
			board[xy.first][xy.second+1].setTeam(board[xy.first][xy.second].getTeam());
	}
	if(xy.second==2 && !board[xy.first][xy.second-1].isEmpty()){
		if(board[xy.first][xy.second].getL() > board[xy.first][xy.second-1].getR())
			board[xy.first][xy.second-1].setTeam(board[xy.first][xy.second].getTeam());
	}
	if(xy.second==1){
		if(!board[xy.first][xy.second+1].isEmpty()){
			if(board[xy.first][xy.second].getR() > board[xy.first][xy.second+1].getL())
				board[xy.first][xy.second+1].setTeam(board[xy.first][xy.second].getTeam());
			
		}
		if(!board[xy.first][xy.second-1].isEmpty()){
			if(board[xy.first][xy.second].getL() > board[xy.first][xy.second-1].getR())
				board[xy.first][xy.second-1].setTeam(board[xy.first][xy.second].getTeam());
		}
	}
}
