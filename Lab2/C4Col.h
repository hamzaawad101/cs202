
#include <iostream>

class C4Col {
        private:
                int numDiscs;
                int maxDiscs;
                char discArray[6];
        public:
               	C4Col(); //default constructor
                int isFull(); //checks if column is full
                char getDisc(int); //given the position it returns disc at that position
                int getMaxDiscs(); // returns maxDiscs 
                void addDisc(char); //adds disc to top of the column 
                int getLastIndex();//returns last filled index

};
