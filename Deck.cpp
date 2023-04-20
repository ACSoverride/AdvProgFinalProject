//
// Created by matti on 4/18/23.
//

#include "Deck.h"

Deck::Deck(string deckName) {
	this->deckName = deckName;
}

void Deck::saveDeck() {
		fstream fileOut;
		if (fileOut){
			fileOut.open(deckName + ".txt", ios::app);
			for (int i = 0; i < theDeck.size(); i++) {
				fileOut << theDeck[i]->getCard() << endl;
			}
		}
		else {
			cout << "Error: Could not write to file";
		}
}

bool Deck::checkDeck(string cardName, string deckFileName) {
	ifstream inputFile(deckFileName + ".txt");
	if (inputFile) {
		while (!inputFile.eof()){
			string input;
			inputFile >> input;
			if (input == cardName){
				return true;
			}
		}
		return false;
	}
	else {
		cout << "Error: Could not read from file";
	}
}

void Deck::addCard(Card * theCard) {
	theDeck.push_back(theCard);
}

void Deck::deleteCard(Card * theCard) {
	bool found = false;
	for (int i = 0; i < theDeck.size(); i++){
		try {
			if (*theDeck[i] == *theCard) {
				delete theDeck[i];
				theDeck.erase(theDeck.begin() + i);
				found = true;
			}
			if (found == false){
				throw("card not in deck");
			}
		}
		catch(string error) {
			cout << "Error: " << error;
		}
	}
}

Deck::~Deck() {
	for (int i = 0; i < theDeck.size(); i++){
		delete theDeck[i];
	}
}