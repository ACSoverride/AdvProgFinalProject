//
// Created by matti on 4/18/23.
//
#include <vector>
#include "Card.h"
#include <fstream>

using namespace std;
class Deck {
public:
	Deck();
	void addCard(Card theCard);
	void saveDeck(string deckName);
	void deleteCard(Card theCard);
private:
	vector<Card> theDeck;
};


