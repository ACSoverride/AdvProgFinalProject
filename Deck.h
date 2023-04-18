//
// Created by matti on 4/18/23.
//
#include <vector>
#include "Card.h"
using namespace std;
class Deck {
public:
	Deck();
	void addCard(Card theCard);
	void saveDeck();
	void deleteCard(Card theCard);
private:
	vector<Card> deck;
};


