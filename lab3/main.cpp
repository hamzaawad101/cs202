/* author: Hamza Awad
* this program runs a blackJack game with a player and a dealer 
*/
#include "CardDeck.h"   // class definition for CardDeck used below
using namespace std;
int main() {
    CardDeck *Cd = new CardDeck(10); // instantiate an instance of a CardDeck object
    Cd->deckTest();
    Cd->play();
}





