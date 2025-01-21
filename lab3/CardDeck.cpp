#include "CardDeck.h"
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>


//default constructor
CardDeck::CardDeck(int n) {
	size=n;
	Deck = new int[ size ];
	for(int i=0; i<size; i++) {
		Deck[i]=i;
	}


}
void CardDeck::printDeck() {
	for(int i=0; i<size; i++) {
		cout<<Deck[i]<<" ";
	}
	cout<<endl;
}
//copy constructor (Dr.scotts notes)
CardDeck::CardDeck( const CardDeck &arrayToCopy )  : size( arrayToCopy.size )  {

	Deck = new int[ size ]; // create space for pointer-based array

	for ( int i = 0; i < size; i++ )
		Deck[ i ] = arrayToCopy.Deck[ i ]; // copy into object

}  // end of copy constructor

//deconstructor delet memory
CardDeck::~CardDeck() {
	delete [] Deck;
}
//assinment operator (Dr.scotts notes)
const CardDeck &CardDeck::operator=( const CardDeck &right ) {

	if ( &right != this ) { // avoid self-assignment

		if ( size != right.size ) {

			delete [] Deck; // release space
			size = right.size; // resize this object
			Deck = new int[ size ]; // create space for array copy

		}

		for ( int i = 0; i < size; i++ )
			Deck[ i ] = right.Deck[ i ]; // copy array into object

	}
	return(*this);
}
void CardDeck::shuffle(int n) {
	srand(n);
	vector<int>c(Deck,Deck+size); //temporary vector to shuffle
	random_shuffle(c.begin(),c.end());
	for(int i=0; i<size; i++) {
		Deck[i]=c[i];//rearranging deck
	}
}
int CardDeck::getSize() {
	return size; //deck size
}
int CardDeck::Deal() {
	int card=Deck[size-1]; //deals a card and decreases the size of the deck
	size--;
	return card;
}
void CardDeck::deckTest() { //shuffle test
	cout<<"Before Shuffle..."<<endl;
	for(int i=0; i<size; i++) {
		cout<<Deck[i]<<" ";
	}
	cout<<endl;
	shuffle(0);
	cout<<"after Shuffle Test.."<<endl;
	for(int i=0; i<size; i++) {
		cout<<Deck[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	delete this;
}
void CardDeck::play() {
	int seed;
	int num=0; //reinitiate values
	char play='y';
	char playerInput=' ';
	char dealerInput=' ';
	int pHand[5];
	int dHand[5];
	int CardValue[13]= {2,3,4,5,6,7,8,9,10,10,10,10,11};// hold the values of each card
	int playerTotal; //value of cards in hand for player
	int dealerTotal;;//value of cards in hand for dealer
	bool winner=false;
	int playerWins=0;
	int dealerWins=0;
	int handCount; //how many cards are in hand
	cout<<" Welcome to BlackJack "<<endl;
	cout<<" Enter Deck size or -1 for Default of 52: ";
	cin>>num;
	cout<<"enter seed or 0 for default: " ;
	cin>>seed;
	if(num==-1) {
		CardDeck *deck=new CardDeck; //deck size=52
	} else {
		CardDeck *deck=new CardDeck(num);
	}
	cout<<"Deck size: "<<size<<endl;
	shuffle(seed);

	while(play=='y') {
		playerInput=' ';
		dealerInput=' ';
		winner=false;
		playerTotal=0;
		dealerTotal=0;
		handCount=2;
		pHand[5];
		dHand[5];
		//CardValue[13]= {2,3,4,5,6,7,8,9,10,10,10,10,11};
		pHand[0]=Deal(); //deal two card each
		dHand[0]=Deal();
		pHand[1]=Deal();
		dHand[1]=Deal();
		printDeck();
		playerTotal=CardValue[pHand[0]%13]+CardValue[pHand[1]%13]; //add cards with their right valuse using card array
		dealerTotal=CardValue[dHand[0]%13]+CardValue[dHand[1]%13];
		cout<<"Player | Total: "<<playerTotal<<" "<<" Cards: "<<CardValue[pHand[0]%13];
		cout<<" "<<CardValue[pHand[1]%13]<<endl;
		cout<<"Dealer | Total: "<<dealerTotal<<" "<<" Cards: "<<CardValue[dHand[0]%13];
		cout<<" "<<CardValue[dHand[1]%13]<<endl;
		while(playerInput!='s' && dealerInput!='s' && winner ==false) {
			cout<<" player Hit or Stand (h or s): ";
			cin>>playerInput;

			if (playerInput == 'h' || playerInput == 'H') {//player hit
				cout<<"Player Chose hit"<<endl;
				pHand[handCount] = Deal(); //deal again
				playerTotal += CardValue[pHand[handCount] % 13]; //add value of cards in hand
				handCount++; //increament how many cards they hold
				for (int i = 0; i < handCount; i++) { //print hand
					cout << CardValue[pHand[i] % 13] << " ";
				}

				cout<<endl;

				cout << endl;
				cout << "Player Total: " << playerTotal << endl;
				//checks for bust or winner
				if (playerTotal > 21) {
					cout << "Player Busted" << endl;
					cout << "Dealer wins" << endl;
					dealerWins++;
					winner = true;
				}
				if(playerTotal==21) {
					cout<<"player wins"<<endl;
					playerWins++;
					winner=true;

				}

			} else if(playerInput == 's' || playerInput== 'S') {
				cout<<"Player Chose to stand "<<endl;
			}

		}


		if(playerInput== 's' || playerInput=='S') {
			//dealers turn
			handCount=2;
			if(dealerTotal<17) {
				cout<<"Dealer Chose hit"<<endl;
				dHand[handCount] = Deal(); //deal
				handCount++;
				dealerTotal += CardValue[dHand[handCount] % 13]; //add values
				for (int i = 0; i < handCount; i++) { //print deck
					cout << CardValue[dHand[i] % 13] << " ";
				}
				cout << endl;
				cout << "Dealer Total: " << dealerTotal << endl;
				if(dealerTotal>21) {//if dealer bust player wins
					cout<<"dealer Busted"<<endl;
					cout<<"player wins"<<endl;
					playerWins++; //wins counter
					winner=true;
				}
				if(dealerTotal==21) {
					cout<<"dealer wins"<<endl;
					dealerWins++;
					winner=true;

				}

			} else {
				cout<<"Dealer Stands"<<endl;
				dealerInput='s';
			}

		}
		//refill deck
		if(getSize()<15) {
			CardDeck *deck=new CardDeck;
			if(getSize()==0) {
				CardDeck *deck=new CardDeck(num);
			}
			shuffle(seed);
		}
		cout<<"Player Wins: "<<playerWins<<endl;
		cout<<"Dealer Wins: "<<dealerWins<<endl;
		if(winner==true) {
			cout<<"would you like to play again: ";
			cin>>play;
		}
	}

}



