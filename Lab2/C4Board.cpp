#include "C4Board.h"
using namespace std;
#include <iostream>
C4Board::C4Board() {

	maxCol=7;

}
void C4Board::play() {
	display(); //draw board
	int turn=0;
	int mark=0; //players chosen column
	char activeChar='x'; //x goes first always
	while(turn!=42) { //as long as there is still space the game keeps going unless there is a winner
		int activePlayer=(turn%2)+1; //active player keeps track of turns
		cout<<"player "<<activePlayer<<" ("<<activeChar<<") chose a column(0-6): ";
		cin>>mark;
		if(mark==-1) {
			cout<< "end of game"<<endl;
			break;
		}
		if(mark<0|| mark>maxCol-1) { //checks if user input is correct and they pick a valid spot otherwise it prompts again
			cout<<"invalid input try again "<<endl;
			continue;
		}
		if(board[mark].isFull()) {
			cout<<"column is full pick a different one"<<endl;
			continue;
		}
		board[mark].addDisc(activeChar); //check if we found a winner after every turn
		bool result=checkWinner(mark);
		if(result==true) { //winner is found 
			display();
			cout<<"Player "<<activePlayer<<"("<<activeChar<<")"<<" wins the game!!!"<<endl;
			break;
		}
		display(); //draw board
		turn++;
		if(activeChar=='o') {

			activeChar='x';
		} else {
			activeChar='o';
		}
	}
	if(turn==42) { //board is full
		cout<<"board is Full game is a tie "<<endl;
	}

}
/*function check winner returns bool 
* parameters is and int 
*returns true if winner is found or false if not found
*/
bool C4Board::checkWinner(int position) {
	int run=0;
	int row=board[position].getLastIndex();
	//horizontal check
	for (int i=0; i<7; i++) {
		if(board[i].getDisc(row)==board[i+1].getDisc(row)&&board[i].getDisc(row)!=' ') {
			run++;
		}
		else {
			run=0;
		}
		if(run==3) {
			return true;
		}
	}
	// checking vertically
	run=0;
	for(int i=0; i<6; i++) {
		if(board[position].getDisc(i)==board[position].getDisc(i+1)&&board[position].getDisc(i)!=' ') {
			run++;
		} else {
			run=0;
		}
		if(run==3) {
			return true;
		}
	}
	run=0;
	int counter=0;
	//checking diagnol bottom left to top right 
	for(int i=row,j=position; i<6,j<7; i++,j++) {
		if(board[j].getDisc(i)==board[j+1].getDisc(i+1)&&board[j].getDisc(i)!=' ') {
			run++;
			counter++;
		}   else {
			if(counter==0) {
				run=0;
			}
			break;
		}
		if(run==3) {
			return true;
		}
	}
//checking top right to bottom left 
	for(int i=row,j=position; i>=0,j>=0; i--,j--) {
		if(board[j].getDisc(i)==board[j-1].getDisc(i-1)&&board[j].getDisc(i)!=' ') {
			run++;
		} else {
			run=0;
			break;
		}
		if(run==3) {
			return true;
		}

	}
	run=0;
	counter=0;
	//checking diagonal bottom right to top left 
	for(int i=row,j=position; i<6,j<7; i++,j--) {
		if(board[j].getDisc(i)==board[j-1].getDisc(i+1)&&board[j].getDisc(i)!=' ') {
			run++;
			counter++;
		}   else {
			if(counter==0) {
				run=0;
			}
			break;
		}
		if(run==3) {
			return true;
		}
	}
	run=0;
	counter=0;
	//checking diagonal  top left to bottom right 
	for(int i=row,j=position; i<6,j<7; i--,j++) {
		if(board[j].getDisc(i)==board[j+1].getDisc(i-1)&&board[j].getDisc(i)!=' ') {
			run++;
			counter++;
		}   else {
			if(counter==0) {
				run=0;
			}
			break;
		}
		if(run==3) {
			return true;
		}
	}
	return false;
}
// returns nothing draws the board after every turn 
void C4Board::display() {
	cout<<"0 1 2 3 4 5 6 "<<endl;
	for (int i =0,index=5; i<6,index>=0; i++,index--) {
		for (int j = 0; j < maxCol; j++) {
			cout << board[j].getDisc(index) <<"|";
		}
		cout<<endl;
	}

	cout<<endl;
}

