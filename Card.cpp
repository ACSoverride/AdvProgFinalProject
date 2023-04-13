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

Spell::Spell(int cmc, string ability, string name, string color) : Card(name, color){
    this->cmc = cmc;
    this->ability = ability;
}

string Spell::getCard() {
    return name + " " + color + " " + cmc;
}

void Spell::setSpell(int cmc) {
    this->cmc = cmc;
}

Sorcery::Sorcery(string ability, sorcType type, int cmc, string name, string color) : Spell(cmc, name, color, ability){
    this->type = type;
}

void Sorcery::setSorc(sorcType type) {
    this->type = type;
}

string Sorcery::getCard() {
    return name + " " + color + " " + type + " " + ability;
}

