#include "C4Col.h"
using namespace std;
C4Col::C4Col() {
	numDiscs=0;
	maxDiscs=6;
	for(int i=0; i<maxDiscs; i++) {
		discArray[i] =' ';
	}
}
//checks if the column is full
int C4Col::isFull() {
	return numDiscs >= maxDiscs;
}
// gets character at the given index(column)
char C4Col::getDisc(int num) {
	return discArray[num];
}
//gets the last played index(row)
int C4Col::getLastIndex() {
	if(numDiscs==0) {
		return 0;
	}
	return numDiscs-1;
}
//gets the max number of discs a column holds
int C4Col::getMaxDiscs() {
	return maxDiscs;
}
//adds a players move on the boardn if the column is not full
void C4Col::addDisc(char activeChar) {
	if (!isFull()) {
		discArray[numDiscs] = activeChar;
		numDiscs++;
	}
}



