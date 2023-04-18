//
// Created by matti on 4/13/23.
//
using namespace std;
#include <string>
#include "Card.h"
#include <iostream>
Card::Card(string name, string color) {
    this->name = name;
    this->color = color;
}

bool Card::operator==(const Card& b) {
	if (this->name == b.name){
		return true;
	}
	else {
		return false;
	}
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
    return name + " " + color + " " + to_string(cmc);
}

void Spell::setSpell(int cmc) {
    this->cmc = cmc;
}

Sorcery::Sorcery(string ability, bool type, int cmc, string name, string color) : Spell(cmc, ability, name, color){
    this->type = type;
}

void Sorcery::setSorc(bool type) {
    this->type = type;
}

string Sorcery::getCard() {
	string typeOutput;
	if (type == true){
		typeOutput + "true";
	}
	else {
		typeOutput = "false";
	}
    return name + " " + color + " " + typeOutput + " " + ability;
}

Creature::Creature(int power, int toughness, string ability, int cmc, string name, string color) : Spell(cmc, ability, name, color) {
	this->power = power;
	this->toughness = toughness;
}

string Creature::getCard() {
	return name + " " +  color + " " + to_string(power) + "/" + to_string(toughness) + " " + ability;
}

Equipment::Equipment(int equipCost, int cmc, string ability, string name, string color) : Spell(cmc, ability, name, color){
	this->equipCost = equipCost;
}

string Equipment::getCard() {
	return name + " " + color + " " + ability + " " + to_string(equipCost);
}

void Equipment::setEquip(int equipCost) {
	this->equipCost = equipCost;
}

Land::Land(bool snow, std::string name, std::string color) : Card(name, color) {
	this->snow = snow;
}

string Land::getCard() {
	if (snow == true){
		string strReturn = name + " " + color + " is a snow land";
	}
	else {
		string strReturn =  name + " " + color;
	}
}

void Land::setSnow(bool snow) {
	this->snow = snow;
}

NonBasicLand::NonBasicLand(string ability, bool snow, string name, string color) : Land(snow, name, color) {
	this->ability = ability;
}

void NonBasicLand::setAbility(string ability) {
	this->ability = ability;
}

string NonBasicLand::getCard() {
	if (snow = true){
		return name + " " + color + " " + ability + " is a snow land";
	}
	else {
		return name + " " + color + " " + ability;
	}
}