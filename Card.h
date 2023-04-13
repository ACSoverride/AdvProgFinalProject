//
// Created by matti on 4/13/23.
//

class Card {
public:
    Card(string name, string color);
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

enum sorcType {
    instant = 0,
    sorcery = 1,
};

class Sorcery : public Spell{
public:
    Sorcery(string ability, sorcType type, int cmc, string name, string color);
    string getCard();
    void setSorc(sorcType type;);
protected:
    sorcType type;
};

class Creature : public Spell {
public:
    Creature(int power, int toughness, string ability, int cmc, string name, string color);
    string getCard();
    void setCreature(int power, int toughness,);
protected:
    int power;
    int toughness;
};