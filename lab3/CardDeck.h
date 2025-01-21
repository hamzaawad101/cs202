#include <iostream>

class CardDeck {

    public:
    	CardDeck(int n=52);
    	int getSize();
    	void shuffle(int );
    	CardDeck(const CardDeck& c);
    	void play();
    	~CardDeck();
    	const CardDeck &operator=( const CardDeck &right );
    	int Deal();
    	void printDeck();
    	void deckTest();

    private:
    	int size;
    	int *Deck;

};

