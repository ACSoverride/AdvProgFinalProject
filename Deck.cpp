//
// Created by matti on 4/18/23.
//

#include "Deck.h"

Deck::Deck() {}

void Deck::saveDeck(string deckName) {
	try {
		fstream fileOut;
		fileOut.open(deckName, ios::app);
		for (int i = 0; i < theDeck.size(); i++){
			fileOut << theDeck[i].getCard() << endl;
		}
	}
}

void Deck::addCard(Card theCard) {
	theDeck.push_back(theCard);
}

void Deck::deleteCard(Card theCard) {
	for (int i = 0; i < theDeck.size(); i++){
		if (theDeck[i] == theCard){
			theDeck.erase(theDeck.begin() + i);
		}
	}
}