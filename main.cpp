#include <iostream>
#include "Deck.h"
using namespace std;
int main() {
	const bool mainLoop = true;
	int choice;
	int cardChoice;
	string deckName;
	cout << "type 1 to build a deck, or 2 to search a deck for a card" << endl;
	cin >> choice;
	cin.ignore();
	cin.clear();
	if (choice == 1){
		cout << "Please enter a name for the deck" << endl;
		getline(cin, deckName);
		Deck newDeck(deckName);
		while (mainLoop) {
			cout << "Type 1 to add a Card, 2 to delete a card, 3 to save the deck, or 4 to quit" << endl;
			cin >> choice;
			cin.ignore();
			cin.clear();
			if (choice == 1){
				cout << "Type 1 to add a sorcery" << endl;
				cout << "Type 2 to add a creature" << endl;
				cout << "Type 3 to add a Equipment" << endl;
				cout << "Type 4 to add a Basic Land" << endl;
				cout << "Type 5 to add a Non Basic Land" << endl;
				cout << "Type 6 to add a Enchantment or Artifact" << endl;
				cin >> cardChoice;
				cin.ignore();
				cin.clear();
				if (choice != 4 && choice != 5){
					int cmc;
					string ability;
					string name;
					string color;
					cout << "Please enter the cards ability" << endl;
					getline(cin, ability);
					cout << "please enter the converted mana cost" << endl;
					cin >> cmc;
					cin.clear();
					cin.ignore();
					cout << "please enter the name of the card" << endl;
					getline(cin, name);
					cout << "please enter the mana color of the card" << endl;
					getline(cin , color);
					if (choice == 1){
						int typeCheck;
							bool type;
							cout << "please enter 1 if the card has instant speed or 2 if not" << endl;
							cin >> typeCheck;
							cin.ignore();
							cin.clear();
							if (typeCheck == 1){
								type == false;
							}
							else {
								type == true;
							}
							Card * newCard;
							newCard = new Sorcery(ability, type, cmc, name, color);
							newDeck.addCard(newCard);
						}
						if (choice == 2){
							int power;
							int toughness;
							cout << "please enter the creature power" << endl;
							cin >> power;
							cin.ignore();
							cin.clear();
							cout << "please enter the creature toughness" << endl;
							cin >> toughness;
							cin.ignore();
							cin.clear();
							Card * newCard;
							newCard = new Creature(power, toughness, ability, cmc, name, color);
							newDeck.addCard(newCard);
						}
						if (choice == 3){
							int equipCost;
							cout << "please enter the equip cost" << endl;
							cin >> equipCost;
							Card * newCard;
							newCard = new Equipment(equipCost, cmc, ability, name, color);
							newDeck.addCard(newCard);
						}
						if (choice == 6){
							Card * newCard;
							newCard = new Spell(cmc, ability, name, color);
						}
					}
					if (choice == 4 || choice == 5){
						string color;
						string name;
						bool snow;
						int snowCheck;
						cout << "please enter the color of the land" << endl;
						getline(cin, color);
						cout << "please enter the name of the land" << endl;
						getline(cin, name);
						cout << "please enter 1 if the land is a snow land" << endl;
						cin >> snowCheck;
						if (snowCheck == 1){
							snow == true;
						}
						else{
							false;
						}
						if (choice == 5){
							string ability;
							cout << "please enter in the lands ability" << endl;
							getline(cin, ability);
							Card * newCard;
							newCard = new NonBasicLand(ability, snow, name, color);
							newDeck.addCard(newCard);
						}
						else {
							Card * newCard;
							newCard = new Land(snow, name, color);
						}
					}
				}
				if (choice == 2){
					string cardName;
					string color = "na";
					cout << "please enter the card you want to delete" << endl;
					getline(cin, cardName);
					Card* newCard;
					newCard = new Card(cardName, color);
					newDeck.deleteCard(newCard);
				}
				if (choice == 3){
					newDeck.saveDeck();
				}
				if (choice == 4){
					break;
				}
			}
		}
	if (choice == 2){
		string cardName;
		string deckName;
		cout << "please enter the name of the card you want to search for" << endl;
		getline(cin, cardName);
		cout << "please enter the name of the deck you want to search" << endl;
		getline(cin, deckName);
		if (Deck::checkDeck(cardName, deckName) == true){
			cout << "the card does exist!";
		}
		else {
			cout << "the card does not exist in that deck";
		}
	}
}