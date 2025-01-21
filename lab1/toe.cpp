// Lab 1:Tic-tac-toe solver
/* author Hamza Awad
* generates a board where two players can play tic tac toe and stops the game when there is a winner
*8/30/24
*/
#include <iostream>
using namespace std;
bool checkWinner(char checkArray[], int size);
int main(int argc, char *argv[]) {
	int j;
	int i;
	int row;
	int column;
	int size=0;
	int position;
	cout<< "Welcome to tic tac toe "<<endl;
	cout<< "please enter board size: ";
	cin>>size;
	char board[size][size];
	char Player1='x';
	char Player2='o';
	cout<< "player1 will be "<<Player1<<endl;
	cout<< "player2 will be "<<Player2<<endl;

//code to draw the board
	for(i=0; i<size; i++) {  // we creat game board and fill spot with dashes
		for(j=0; j<size; j++) {
			board[i][j]='-';
		}

	}
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			cout<< board[i][j];
		}
		cout<<endl;

	}
	int activePlayer=1; //active player and active mark helps keep track of turns
	char activeChar='x';
	int spaces=size * size; //get how many spaces the board will have
	while(spaces>0) { //as long as there is still space the game keeps going unless there is a winner
		cout<<"player "<<activePlayer<<" ("<<activeChar<<") chose a spot(ex 0 1): ";
		cin>>row >>column;
		if(row>size-1 || column>size-1) { //checks if user input is correct and they pick a valid spot otherwise it prompts again
			cout<<"invalid input try again "<<endl;
			continue;
		}
		if(board[row][column]!='-') { //if a spot is not a dash it can not be changed by user
			cout<<"cell already makred try again "<<endl;
			continue;
		}
		board[row][column]=activeChar; //places current players mark on board
		//check for winner
		char myArray[size*size]; //create 1d array for check funtion
		for(int i=0; i<size; i++) {
			for(int j=0; j<size; j++) {

				myArray[i*size+j]=board[i][j]; //fill our 1d Array with 2d array elements
			}
		}
		bool result= checkWinner(myArray,size); //bool function that takes 1darray and size checks for winner after every turn
		if(result==true) { //if winner found we print the board and last turn wins
			for(int i=0; i<size; i++) {
				for(int j=0; j<size; j++) {
					cout<<board[i][j];
				}
				cout<<endl;
			}
			cout<<"Player "<<activePlayer<<" is the winner!!!"<<endl;
			return 0;
		}

		spaces--; //keep track of spaces being used helps to determin tie
		if(activePlayer==1) { //checks whos turn it is based on who played last 
			activePlayer=2; //if activePlayer is 1 then its player 2's turn and mark is changed 
			activeChar='o';
		} else {
			activePlayer=1;
			activeChar='x';
		}
		for(i=0; i<size; i++) { //print updated board after every turn
			for(j=0; j<size; j++) {
				cout<< board[i][j];
			}
			cout<<endl;

		}
		if(spaces==0){
		  cout<<"Its a Tie"<<endl;
		}
	}
	return 0;
}
/* bool checkWinner: checks if there is a winner on the baord X or O.
   Parameters:char checkArray[],int size.
   Returns: bool (true if winner found or false if no winner found)

*/

bool checkWinner(char checkArray[],int size) {

	int count=0;
	int i=0;
	int j=0;
// this section checks for a winner in a single row
	for( i=0; i<size; i++) {
		for(j =0; j<size-1; j++) {
			if(checkArray[i*size+j]==checkArray[i*size+j+1]) {
				count++;

			} else {
				break; //exits loop if row characters do not match with previouse input
			}

		}
		if(count==size-1) {
			if(checkArray[i*size+j]!='-') {//if winner is dash it can not win
				return true; //winner found returns trueand ends function
			}



		}
		count=0;
	}
//checks for winner in column
	for( i=0; i<size; i++) {
		for(j =0; j<size-1; j++) { //increase j and compare to the top and bottom character opposite from our row checker where we increment i
			if(checkArray[j*size+i]==checkArray[(j+1)*size+i]) {
				count++;

			} else {
				break;
			}

		}
		if(count==size-1) {
			if(checkArray[j*size+i]!='-') {
				return true;
			}



		}
		count=0;
	}
//[i][i]==[i+1][i+1]
//[i*size+i]==[(i+1)*size+(i+1)

//checking for winner from top left to bottom right 
	 for(i=0; i<size-1; i++) {//number match in the array as it goes from top right to left so we increment i only
                if(checkArray[i*size+i]==checkArray[(i+1)*size+(i+1)]) {
                        count++;
                } else {
                        break;
                }


        }
        if(count==size-1) {
                if(checkArray[i*size+i]!='-') {
                        return true;
                }

        }
        count=0;
//checking for winner from top right to bottom left 
        for(i=0,j=size-1; i<size-1 && j>0; i++,j--) { // going from top right to bottom left we increase i but decrease j as i goes up j goes down  
                if(checkArray[i*size+j]==checkArray[(i+1)*size+(j-1)]) {  
                        count++;
                }
	   }
        if(count==size-1) {
                if(checkArray[i*size+j]!='-') {
                        return true;
                }

        }
        count=0;
return false;
}

