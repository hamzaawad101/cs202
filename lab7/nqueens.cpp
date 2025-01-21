// Lab 7:  N-queens using backtracking 
/*Author:Hamza Awad
*10/16/24
*Lab solves Nqueens problem where it places queens that do not threaten each other on row,colum or diagonal on a NxN board.
* uses the brute force or the recursive/backtracking solution.
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;
void nqueens(vector<int>&board,int col,int size); //recursive function
bool isValid(const vector<int>& board, int size);//check if position is valid
void print(const vector<int>&board); //print output

int main(int argc, char *argv[]) {
    int size=0;
    //sscanf(argv[1],"%d",&size);
    cin>>size;
   //cout<<argv[1]<<endl;
    vector<int> board(size);

    nqueens(board, 0, size);

  return 0;

}
bool isValid(const vector<int>& board, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {

            if (board[i] == board[j]){
                return false;
            }
        }
    }
       
         for (int i = 0; i < size-1; i++) {
                for (int j = i+1; j< size; j++) {
                    if(abs(board[i] - board[j]) == abs(i - j)){
                        return false;
                     }
                 }
         }
        return true; 
    }
void nqueens(vector<int>&board,int col,int size){
    if(col==size){ //no more space on board to add queens
         if(isValid(board,size)){  //if board vaild we add again.
                 print(board);
         }
    }else{

     	for (int row = 0; row < size; row++) {
                board[col] = row; // try adding queen
                nqueens (board, col + 1, size);

            }
    }

}
//print output
void print(const vector<int>& board) {
    int size=board.size();
    for (int i = 0; i < size; ++i) {
        cout << board[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}