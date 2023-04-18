//
// Created by matti on 4/18/23.
//

#include "Deck.h"

Deck::Deck() {}

Deck Deck::operator=(const Deck &b) {
}

void Deck::addCard(Card theCard) {
	deck.push_back(theCard);
}

void Deck::deleteCard(Card theCard) {
	for (int i = 0; i <= deck.size(); i++){
		if (deck[i] == theCard){
			deck.erase(deck.begin() + i);
		}
	}
}