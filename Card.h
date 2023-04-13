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
    Spell(int cmc, string name, string color);
    string getCard();
    string setSpell(int cmc, string name, string color);
protected:
    int cmc;
};

enum sorcType {
    instant = 0,
    sorcery = 1,
};

class Sorcery : public Spell{
public:
    Sorcery(string ability, sorcType type, int cmc, string name, string color);
    string getCard();
    void setAbility(string ability);
protected:
    string ability;
    sorcType type;
};
