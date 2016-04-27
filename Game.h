//
//  Game.h
//  Five Card Poker
//
//  Created by Spencer Negri on 4/14/16.
//  Copyright © 2016 CU. All rights reserved.
//



#ifndef Game_h
#define Game_h

#include <iostream>
#include <vector>

using namespace std;

struct Card {
    int cardNumber;
    string suit;
    Card(int number, string newSuit) {
        cardNumber = number;
        suit = newSuit;
    }
    Card() {
        cardNumber = -1;
        suit = "NONE";
    }
    Card *nextCard;
};

struct Player {
    string name;
    int money;
    int bet;
    int currentBet;
    bool check;
    bool fold;
    bool isPlayer1;

    Player(string n) {
        name = n;
    }
};

class Game {
public:
    Game();
    ~Game();
    void printMenu();
    void createDeck();
    void printDeckArray();
    void printDeck();
    void printCard(Card printedCard);
    void shuffleDeck();
    bool isOver();
    void addPlayer(string name);
    void showPlayers();
    vector<Player> players;
    void dealCards(Player p);
    void showHand(Player p);
    //Card getFirst();
    void show5Cards();
    void addCardto5Cards();
    void checkCards(Player p);
    string showHave(Player p);
    bool twoOfKind = false, threeOfKind = false, fourOfKind = false, straight = false, fullHouse = false;
    bool twoOfKind2 = false, threeOfKind2 = false, fourOfKind2 = false, straight2 = false, fullHouse2 = false;
    bool TK = false, THK = false, FH = false;
    bool TK2 = false, THK2 = false, FH2 = false;
    
private:
    vector<Card> cards;
    vector<Card> fiveCards;
    Card player1Hand[2];
    Card player2Hand[2];
};



#endif /* Game_h */
