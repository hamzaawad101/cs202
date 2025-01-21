#include <iostream>
#include "C4Col.h"
class C4Board {

        private:
                int maxCol;// 7 columns
                C4Col board[7];
                bool checkWinner(int);

        public:
               	C4Board(); //default constructor
                void display();
                void play();

};
