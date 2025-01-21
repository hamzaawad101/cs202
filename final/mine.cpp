#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

void printBoard(const vector<char>& board, int size) {
  // Print column numbers
  cout << "  ";
  for(int j = 0; j < size; ++j){
    cout << setw(2) << j;
  }
  cout << endl;

  // Print top border
  cout << "  " << string(size * 2, '-') << endl;

  // Print board with row numbers and left border
  for(int i = 0; i < size; ++i){
    cout << i << "| ";

    for(int j = 0; j < size; ++j){
      cout << board[i * size + j] << " ";
    }

    cout << endl;
  }
}

//takes random seed from clock time and generates positions for mines
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
  vector<int> row = {-1, -1, -1, 0, 0, 1, 1, 1};        //row and column iterator vectors for checking
  vector<int> col = {-1, 0, 1, -1, 1, -1, 0, 1};

  for(int i = 0; i < size; ++i){
    for(int j = 0; j < size; ++j){
      if(board[i * size + j] == '*') continue; // Skip mines

        int num = 0;
        // Check all neighbors
        for(int k = 0; k < 8; ++k) {
          int ni = i + row[k];
          int nj = j + col[k];
          if(ni >= 0 && ni < size && nj >= 0 && nj < size) {
            if (board[ni * size + nj] == '*') {
              ++num;
            }
          }
        }
      board[i * size + j] = '0' + num; // Convert number to char
    }
  }
}

void revealZeroCells(vector<char>& board, vector<char>& fakeBoard, int size, int row, int col) {

  //check if out of bounds or already revealed
  if(row < 0 || row >= size || col < 0 || col >= size || fakeBoard[row * size + col] != '-') return;

  //reveal current cell
  fakeBoard[row * size + col] = board[row * size + col];

  //if the current cell is not a zero, stop recursion
  if (board[row * size + col] != '0') return;

  //recursive checks for neighboring cells
  vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
  vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

  for(int i = 0; i < 8; ++i){
    int newRow = row + dx[i];
    int newCol = col + dy[i];
    revealZeroCells(board, fakeBoard, size, newRow, newCol);
  }

}

bool checkWin(const vector<char>& board, const vector<char>& fakeBoard, int size){
  for(int i = 0; i < size * size; ++i){
    //if a non-mine cell is not revealed, game is not won
    if(board[i] != '*' && fakeBoard[i] == '-'){
      return false;
    }
  }
  return true;
}

void play(vector<char>& board, vector<char>& fakeBoard, int size) {
   int row, col, count; //get column and row from user 
   cout << "Enter Cell (col row): ";
   cin >> col >> row;

   int index = row * size + col; //get index to place on the board

   if(fakeBoard[index] != '-'){ // user chosen cell already shown 
      cout << "Cell already revealed. Please choose again." << endl;
      return;
   }

   if (board[index] == '*') { //* is a mine on board 
       cout << "Boom! You hit a mine!" << endl;
       fakeBoard[index] = '*';
       printBoard(board, size);

       exit(0);
   } else {
       cout << "Safe! This cell has " << board[index] << " neighboring mines." << endl;

       if(board[index] == '0') revealZeroCells(board, fakeBoard, size, row, col); //calls reveal function 
       else fakeBoard[index] = board[index];
   }

   printBoard(fakeBoard, size);

    if(checkWin(board, fakeBoard, size)){
        cout << "You Win!" << endl;
        exit(0);
    }
}

int main() {
   int size = 0;;
   int gameMode=0;
   cout << "Welcome to minesweeper" << endl;
   cout << "Please Enter diffecutly level (Easy = '1', Med = '2', Hard = '3'): "; //asks user for difficulty level 
   cin>>gameMode;
   if(gameMode==1){ //user choice changes size of board 
     size=5;
   }else if (gameMode==2){
     size=8;
   }else if(gameMode==3){
     size=10;
   }
   vector<char> board(size * size, '-');
   vector<char> fakeBoard(size * size, '-'); //board that player sees

   printBoard(board, size);
   placeMines(board, size);
   reveal(board, size);
   while (true) {
      play(board, fakeBoard, size);
   }

   return 0;
}