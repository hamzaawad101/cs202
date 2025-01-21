#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

void printBoard(const vector<char>& board, int size) {
    cout << "  ";
    for (int i = 0; i < size; ++i) {
        cout << i << ' ';
    }
    cout << endl;

    for (int i = 0; i < size; ++i) {
         cout << i << ' ';
        for (int j = 0; j < size; ++j) {
            cout << board[i * size + j] << ' ';
        }
        cout << endl;
    }
}

void placeMines(vector<char> &board, int size) {
  int seed;
  srand(time(NULL));
  for(int i = 0; i < size; i++) {
    seed = rand() % (size * size);
	if(board[seed] == '*') seed = rand() % (size * size);
	board[seed] = '*';
  }
}

void reveal(vector<char> &board, int size) {
  int num = 0;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
	  if(board[i * size + j] == '*') continue;
	  if(board[i * size + j + 1] == '*') num++;
	  if(board[i * size + j - 1] == '*') num++;
	  if(i != 0){
	    if(board[i + j] == '*') num++;
	    if(board[i + j + 1] == '*') num++;
	    if(board[i + j - 1] == '*') num++;
	  }
	  if(i != size){
	    if(board[(i + 1) * size + j] == '*') num++;
	    if(board[(i + 1) * size + j + 1] == '*') num++;
	    if(board[(i + 1) * size + j - 1] == '*') num++;
	  }
	  board[i * size + j] = 48 + num;
	  num = 0;
	}
  }
}
void play(vector<char>& board, vector<char>& fakeBoard, int size) {
    int row, col;
    cout << "Enter Cell (col row): ";
    cin >> col >> row;

    int index = row * size + col;
    if (board[index] == '*') {
        cout << "Boom! You hit a mine!" << endl;
        fakeBoard[index] = '*'; 
        printBoard(board, size); 
        
        exit(0); 
    } else {
        cout << "Safe! This cell has " << board[index] << " neighboring mines." << endl;
        fakeBoard[index] = board[index]; 
    }

    printBoard(fakeBoard, size);
}

int main() {
    int size = 0;;
    int gameMode=0;
    cout << "Welcome to minesweeper" << endl;
    cout << "Please Enter diffecutly level (Easy =1, Med =2, Hard=3) :";
    cin>>gameMode;
    if(gameMode==1){
      size=5;
    }else if (gameMode==2){
      size=8;
    }else if(gameMode==3){
      size=10;
    }
    vector<char> board(size * size, '-');
    vector<char> fakeBoard(size * size, '-'); 

    printBoard(board, size); 
    placeMines(board, size); 
    reveal(board, size);    
    while (true) {
       play(board, fakeBoard, size); 
    }

    return 0;
}


