//
// Created by matti on 4/13/23.
//

#include "Card.h"

Card::Card(string name, string color) {
    this->name = name;
    this->color = color;
}

string Card::getCard(){
    return name;
}

void Card::setCard(string name, string color) {
    this->name = name;
    this->color = color;
}

Spell::Spell(int cmc, string name, string color) : Card(name, color){
    this->cmc = cmc;
    this->name = name;
    this->color = color;
}

string Spell::getCard() {
    return name + " " + color + " " + cmc;
}

void Spell::setSpell(int cmc, string name, string color) {
    this->cmc = cmc;
    this->name = name;
    this->color = color;
}

Sorcery::Sorcery(string ability, sorcType type, int cmc, string name, string color) : Spell(int cmc, string name, string color){

}