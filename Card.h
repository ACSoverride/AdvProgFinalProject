//
// Created by matti on 4/13/23.
//
#include <string>
using namespace std;

class Card {
public:
	Card(string name, string color);
	bool operator==(const Card& b);
	friend ostream& operator<<(ostream& out, const Card& b);
    virtual string getCard();
    void setCard(string name, string color);
protected:
    string name;
    string color;
};

class Spell : public Card{
public:
    Spell(int cmc, string ability, string name, string color);
    string getCard();
    void setSpell(int cmc);
protected:
    int cmc;
    string ability;
};

class Sorcery : public Spell{
public:
    Sorcery(string ability, bool type, int cmc, string name, string color);
    string getCard();
    void setSorc(bool type);
protected:
	//false = instant and true = sorcery
    bool type;
};

class Creature : public Spell {
public:
    Creature(int power, int toughness, string ability, int cmc, string name, string color);
    string getCard();
    void setCreature(int power, int toughness);
protected:
    int power;
    int toughness;
};

class Equipment : public Spell {
public:
	Equipment(int equipCost, int cmc, string ability, string name, string color);
	string getCard();
	void setEquip(int equipCost);

protected:
	int equipCost;
};

class Land : public Card {
public:
	Land (bool snow, string name, string color);
	void setSnow(bool snow);
	string getCard();

protected:
	bool snow;
};

class NonBasicLand : public Land {
public:
	NonBasicLand(string ability, bool snow, string name, string color);
	void setAbility(string ability);
	string getCard();

protected:
	string ability;
};