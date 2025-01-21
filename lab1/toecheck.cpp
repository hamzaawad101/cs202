// Lab 1:  Tic-tac-toe solver (as requested by awesome grad TA grader Tom)
/* author Hamza Awad
* checks 8 frozen tic tac toe board and outputs a winner
*8/30/24
*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int size, count=0;
	int i=0;
	int j=0;
	cin>>size;
	char board [size][size];
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			cin>>board[i][j];
		}
	}
// this section checks for a winner in a single row
	for( i=0; i<size; i++) {
		for(j =0; j<size-1; j++) {
			if(board[i][j]==board[i][j+1]) {
				count++;

			} else {
				break; //exits loop if row characters do not match with previouse input
			}

		}
		if(count==size-1) {
			if(board[i][j]!='-') { //if winner is dash it can not win
				cout<< board[i][j]<<" wins" <<endl;
				return 0; //winner found ends program
			}



		}
		count=0;

	}
//checks for winner in column
	for( i=0; i<size; i++) {
		for(j =0; j<size-1; j++) {
			if(board[j][i]==board[j+1][i]) { //increase j and compare to the top and bottom character opposite from our row checker where we increment i
				count++;

			} else {
				break;
			}

		}
		if(count==size-1) {
			if(board[j][i]!='-') {
				cout<< board[j][i]<< " wins" <<endl;
				return 0;
			}



		}
		count=0;


	}
//checking for winner from top left to bottom right 
	for(i=0; i<size-1; i++) { //number match in the array as it goes from top right to left so we increment i only
		if(board[i][i]==board[i+1][i+1]) {
			count++;
		} else {
			break;
		}


	}
	if(count==size-1) {
		if(board[i][i]!='-') {
			cout<< board[i][i]<< " wins" <<endl;
			return 0;
		}

	}
	count=0;
//checking for winner from top right to bottom left 
	for(i=0,j=size-1; i<size-1 && j>0; i++,j--) {// going from top right to bottom left we increase i but decrease j as i goes up j goes down  
		if(board[i][j]==board[i+1][j-1]) {
			count++;
		}


	}
	if(count==size-1) {
		if(board[i][j]!='-') {
		cout<< board[i][j]<< " wins" <<endl;
			return 0;
		}

	}
	cout<<"Tie"<<endl;
	count=0;

	return 0;
}


