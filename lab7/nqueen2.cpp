// Lab 7:  N-queens using "constrained" backtracking 
/*Author:Hamza Awad
*10/16/24
*Lab solves Nqueens problem where it places queens that do not threaten each other on row,colum or diagonal on a NxN board.
* uses the constrained recursive/backtracking solution.
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;
void nqueens(vector<int>& board, int row, int size, int& totalChecked); //recursive function
bool isValid(const vector<int>& board, int row, int col);//check if position is valid
void print(const vector<int>&board); //print output

int main(int argc, char *argv[]) {
    int size=0;
    int totalChecked=0;
    cin>>size;
    vector<int> board(size);
    nqueens(board, 0, size,totalChecked);
    cerr << "Total number of boards checked: " << totalChecked << endl; //how many boards were considered
  return 0;

}
bool isValid(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        // Check if queens are in the same column or on the same diagonal
        if (board[i] == col){
            return false;
        }
        if(abs(board[i] - col) == abs(i - row)) {//abs value is used to check the difference between the column and row 
            return false; //if its the same then its on the same diagonal
        }
    }
    return true;
}
void nqueens(vector<int>& board, int row, int size, int& totalChecked) {
    if (row == size) {//board full
        print(board);

        return;
    }
    
    for (int col = 0; col < size; ++col) {
        totalChecked++;  // Increment the number of boards checked
        if (isValid(board, row, col)) { //we check board before moving on to next row.
            board[row] = col;
            nqueens(board, row + 1, size,totalChecked);
        }
    }
}
//print output
void print(const vector<int>& board) {
    int size=board.size();
    for (int i = 0; i < size; ++i) {
        cout << board[i];
        if (i != size - 1) {
            cout << ", "; // Print comma between values
        }
    }
    cout << endl;
}