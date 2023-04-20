//
// Created by matti on 4/18/23.
//
#include <vector>
#include "Card.h"
#include <fstream>
#include <iostream>

using namespace std;
class Deck {
public:
	Deck(string deckName);
	void addCard(Card * theCard);
	void saveDeck();
	void deleteCard(Card  * theCard);
	bool checkDeck(string cardName);
private:
	vector<Card*> theDeck;
	string deckName;
};


