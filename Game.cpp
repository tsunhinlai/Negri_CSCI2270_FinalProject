

#include "Game.h"
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

Game::Game() {
    
}

Game::~Game() {
    
}

void Game::printMenu() {
    cout << "------------------------------------" << endl;
    cout << "------Welcome to Texas Hold'em------" << endl;
    cout << "--------------TwoPlayer-------------" << endl;
}


void Game::createDeck() { //This method builds the deck with 52 cards.
    int count = 1; //Because i goes from 1 to 52 we need another in that only goes from 1 to 13 and resets. THis is because those are the values of cards in a deck A(1), 2, 3, 4, 5, 6, 7, 8, 9, 10, J(11), Q(12), K(13)
    for (int i = 1; i <= 52; i++) { //loops 52 time becaues 52 cards
        if (i <= 13) { //Puts 13 cards with suit Spades into the deck (deck is called Cards)
            Card currentCard(count, "Spades"); //see constructor for struct Card
            cards.push_back(currentCard); //puts Card in the cards vector
        }
        if (i > 13 && i <= 26 ) { //Puts 13 cards with suit Clubs into the deck
            Card currentCard(count , "Clubs");
            cards.push_back(currentCard);
        }
        if (i > 26 && i <= 39 ) { //Puts 13 cards with suit Hearts into the deck
            Card currentCard(count, "Hearts");
            cards.push_back(currentCard);
        }
        if (i > 39 && i < 53 ) {
            Card currentCard(count , "Diamonds"); //Puts 13 cards with suit Diamonds into the deck
            cards.push_back(currentCard);
        }
        if (count == 13) { //This makes sure that count only gets to 13 and when it does it gets set back to 1
            count = 1;
        }
        else {
            count++; //If count is not 13, increment
        }
    }
}

void Game::printDeckArray() { //This simply prints the vector cards. This was used for testing the program
    for (int i = 0; i <= 51; i++) {
        cout << "Card number: " << cards[i].cardNumber << " Suit: " << cards[i].suit << endl;
    }
}

void Game::printCard(Card printedCard) { //This method prints a card that is passed in. It simply checks the number and the suit of the card and then prints that respective card.
    if (printedCard.suit == "Spades") {
        if(printedCard.cardNumber == 1) {
            cout << " ----" << endl;
            cout << "| "  << "\u2660" << "  |" << endl; // The weird "\u2660" is unicode for the Spade
            cout << "|    |" << endl;
            cout << "| " << "A" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 10) {
            cout << " ----" << endl;
            cout << "| "  << "\u2660" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << 10 <<  " |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 11) {
            cout << " ----" << endl;
            cout << "| "  << "\u2660" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "J" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 12) {
            cout << " ----" << endl;
            cout << "| "  << "\u2660" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "Q" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 13) {
            cout << " ----" << endl;
            cout << "| "  << "\u2660" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "K" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else {
            cout << " ----" << endl;
            cout << "| "  << "\u2660" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << printedCard.cardNumber <<  "  |" << endl;
            cout << " ----" << endl;
        }
        
    }
    if (printedCard.suit == "Clubs") {
        if(printedCard.cardNumber == 1) {
            cout << " ----" << endl;
            cout << "| "  << "\u2618" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "A" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 10) {
            cout << " ----" << endl;
            cout << "| "  << "\u2618" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << 10 <<  " |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 11) {
            cout << " ----" << endl;
            cout << "| "  << "\u2618" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "J" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 12) {
            cout << " ----" << endl;
            cout << "| "  << "\u2618" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "Q" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 13) {
            cout << " ----" << endl;
            cout << "| "  << "\u2618" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "K" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else {
            cout << " ----" << endl;
            cout << "| "  << "\u2618" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << printedCard.cardNumber <<  "  |" << endl;
            cout << " ----" << endl;
        }
        
    }
    if (printedCard.suit == "Hearts") {
        if(printedCard.cardNumber == 1) {
            cout << " ----" << endl;
            cout << "| "  << "\u2665" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "A" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 10) {
            cout << " ----" << endl;
            cout << "| "  << "\u2665" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << 10 <<  " |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 11) {
            cout << " ----" << endl;
            cout << "| "  << "\u2665" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "J" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 12) {
            cout << " ----" << endl;
            cout << "| "  << "\u2665" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "Q" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 13) {
            cout << " ----" << endl;
            cout << "| "  << "\u2665" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "K" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else {
            cout << " ----" << endl;
            cout << "| "  << "\u2665" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << printedCard.cardNumber <<  "  |" << endl;
            cout << " ----" << endl;
        }
        
    }
    
    if (printedCard.suit == "Diamonds") {
        if(printedCard.cardNumber == 1) {
            cout << " ----" << endl;
            cout << "| "  << "\u2666" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "A" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 10) {
            cout << " ----" << endl;
            cout << "| "  << "\u2666" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << 10 <<  " |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 11) {
            cout << " ----" << endl;
            cout << "| "  << "\u2666" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "J" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 12) {
            cout << " ----" << endl;
            cout << "| "  << "\u2666" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "Q" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else if(printedCard.cardNumber == 13) {
            cout << " ----" << endl;
            cout << "| "  << "\u2666" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << "K" <<  "  |" << endl;
            
            cout << " ----" << endl;
        }
        else {
            cout << " ----" << endl;
            cout << "| "  << "\u2666" << "  |" << endl;
            cout << "|    |" << endl;
            cout << "| " << printedCard.cardNumber <<  "  |" << endl;
            cout << " ----" << endl;
        }
        
    }
}

void Game::printDeck() { //Prints the deck using the printCard method. This was so I could make sure all the cards were printing correctly
    for (int i = 0; i < 53; i++) {
        printCard(cards[i]);
    }
    
}

int myRandom(int i) { //The logic of this method is unknown. However it is necesarry for the following method, shuffleDeck to function properly.
    return std::rand() % i;
}

void Game::shuffleDeck() { // This method shuffles the deck using a method from the <algorithm> library.
    
    random_shuffle(cards.begin(), cards.end(), myRandom); //The third parameter here is not a variable but rather the method directly above this one. Why you dont have to pass in int i I still have no idea. Anyways, the first two parameters are simply the beginning index and ending index for the vector/array you want to shuffle
}

void Game::showPlayers() { //Simply prints the players. Used to test program
    for (int i = 0; i < 4; i++) {
        cout << players[i].name << " ";
    }
}

void Game::dealCards(Player p) { // This method deals two cards to the player that is passed in as a parameter.
    if (p.isPlayer1 == true) { //Checks to see which player to deal to.
        player1Hand[0] = cards[0]; //Since the cards have already been shuffled, this just sets the players first card to be the first card off the deck
        cards.erase(cards.begin()); //Erases the card so it cannot be used again in the game
        player1Hand[1] = cards[0]; // Deals the player a second card
        cards.erase(cards.begin()); // Erases card
    }
    else { // Does same thing as above except for player2
        player2Hand[0] = cards[0];
        cards.erase(cards.begin());
        player2Hand[1] = cards[0];
        cards.erase(cards.begin());
    }
    
}

void Game::showHand(Player p) { //This simply prints the respective player's hand.
    if (p.isPlayer1 == true) {
        printCard(player1Hand[0]);
        printCard(player1Hand[1]);
    }
    else {
        printCard(player2Hand[0]);
        printCard(player2Hand[1]);
    }
}

void Game::addCardto5Cards() { //This method adds to the cards on the table. In texas hold'em, first there are 3 cards placed on the table, then one more, then in the final round one more.
    if (fiveCards.size() < 3) { //If there arent any cards on the table, this puts three cards out
        fiveCards.push_back(cards[0]); //fiveCards is the vector of cards on the table, this adds a card from the deck to this vector. Push back is nice because it inherently adds a card to the end of the vector.
        cards.erase(cards.begin());
        fiveCards.push_back(cards[1]);
        cards.erase(cards.begin());
        fiveCards.push_back(cards[2]);
        cards.erase(cards.begin());
    }
    
    else if(fiveCards.size() == 3) { //If there are already three cards on the table, only one needs to be put out.
        fiveCards.push_back(cards[3]);
        cards.erase(cards.begin());
    }
    
    else if(fiveCards.size() == 4) { //If there are already three cards on the table, only one needs to be put out.
        fiveCards.push_back(cards[4]);
        cards.erase(cards.begin());
    }
}

void Game::show5Cards() { // This simply prints the cards on the table
    cout << "CARDS ON THE TABLE: " << endl;
    for (int i = 0; i < fiveCards.size(); i++) {
        printCard(fiveCards[i]);
    }
    cout << "--------------------------" << endl;
}

void Game::checkCards(Player p) { //This method looks like a nightmare however its not all that hard to understand. First it makes and array called bucket. Each index of this array represents a card value. For example, 1 represents ace and 13 represents King. This array is used to see how many cards of each type you have.
    int bucket[15] = {0};
    Card currentHand[5] = {}; // In poker there are a ton of ways to combine your two cards with the fives cards on the table. This array simply stores the current hand that the program is looking at.
    string Winners[10];
    int left = 0, right = 1, rightPrev = right; //These varbiables help make combinations of the two cards with the five on the table. Their purpose will become more evident later
    
    
    //Essentially how this next block works (it stops at where it says 222222 and then repeats again 9 times), is it takes player1's cards and puts them in the five cards on the table, replacing them with two cards within the five cards. For example if the five cards on the table were:
    // A 2 3 4 5 and player1 has a 7 and an 8
    //This makes currentHand:
    // 7 8 3 4 5
    // The next iteration will make it:
    // 7 2 8 4 5
    // The next will be:
    // 7 2 3 8 5
    // The next will be:
    // 7 2 3 5 8
    // The next will be:
    // A 7 8 4 5
    // So essentially the left variable increments every 4 then every 3.
    // The right variable increments every time however it gets set to 2 after 4 iterations and then 3 after 7 iterations and then 3 after 8 iterations
    //The tenth iteration is simply the five cards on the table without using the player's two cards
    
    if (p.isPlayer1 == true) { //Checks to see which player we are dealing with.
        
        for (int i = 0; i < 5; i++) { // This for loop places cards in currentHand from the five cards on the table and player1's cards
            if (i == left) { //Left represents where the left card (i.e. player1's 1st card) is going to go
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) { //Right represents where the right card (i.e. player1's 2nd card) is going to go
                currentHand[right] = player1Hand[1];
            }
            else { //If its not in a right or a left position simply grab a card from the five cards on the table
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) { //This for loop, loops through the hand that was made from the previous loop
            for (int j = 1; j < 14; j++) { //This loop, loops through the 13 possible cards that are in the hand
                if (currentHand[i].cardNumber == j) { //If it finds a 5, for example, increment the 5th index. This shows the player has a 5.
                    bucket[j]++;
                }
            }
        }
        int temp = 0; //This could be used for straight
        
        for (int i = 1; i < 14; i++) { //Loops through bucket to check to see if they have any pairs, three of a kinds, or full houses
            if (bucket[i] == 2) { // If the int in a bucket is two that means they had two of the same card
                twoOfKind = true;
            }
            if (bucket[i] == 3) { //Same for three
                threeOfKind = true;
            }
            if (threeOfKind == true && twoOfKind == true) { // This is the fullHouse condition. If a player has a two of a kind and a three of a kind that is a full house. However, if a player has a full house, then they dont care about having a pair or three of a kind therefore those variables are set back to false.
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) { //Used for straight which is not checked for in program. (You could finish this). Essentially you need to check if there are five cards in a row. Bucket is already sorted so if temp ever gets to 4 then there is a straight.
                temp++;
            }
            if (temp == 4) { // CHecks what was just said
                straight = true;
            }
            if (bucket[i] == 0) { // If there is a zero then set it back to zero. This must go last because it has to check if there is a 1 first, otherwise straight will never be possible.
                temp = 0;
            }
            
        }
        if (temp == 4) { //Checks straight
            straight = true;
            Winners[0] = "STRAIGHT"; //Winners was an array used to see what each combination of cards produced. It is not used in the final product
        }
        
        if (twoOfKind == true) {
            
            Winners[0] = "PAIR";
        }
        
        if (threeOfKind == true) {
            
            Winners[0] = "THREE OF A KIND";
        }
        
        if (twoOfKind == true && threeOfKind == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[0] = "FULL HOUSE";
        }
        right++; //Increment right because we still have not interated 4 times
        
        if (twoOfKind == true) { //If the player has a two of a kind, I mark a variable TK true because we want to store the fact that they have two of a kind. Otherwise this fact will be lost. The same is done for three of a kind (THK) and full house (FH)
            TK = true;
        }
        if (threeOfKind == true) {
            THK = true;
        }
        if (fullHouse == true) {
            FH = true;
            TK = false;
            THK = false;
        }
        twoOfKind = false; //set all three variables back to false so we can check another combination for these things.
        threeOfKind = false;
        fullHouse = false;

        for (int i = 0; i < 14; i++) { // resets bucket so we can check another combination
            bucket[i] = 0;
        }
        //From this point all the way up until the else statement, all of these blocks of code do the same thing as the previous block, they just look at different combinations of cards. The reason I did it this way is because using a while loop got extremely conveluded for some reason and I was unable to use it. Maybe you could figure out how to do that because that would make this much much more efficient.
        
        ///////////////////////////////////////////////// 22222222222
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player1Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind = true;
            }
            if (bucket[i] == 3) {
                threeOfKind = true;
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight = true;
            Winners[1] = "STRAIGHT";
        }
        
        if (twoOfKind == true) {
            Winners[1] = "PAIR";
        }
        
        if (threeOfKind == true) {
            Winners[1] = "THREE OF A KIND";
        }
        
        if (twoOfKind == true && threeOfKind == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[1] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind == true) {
            TK = true;
        }
        if (threeOfKind == true) {
            THK = true;
        }
        if (fullHouse == true) {
            FH = true;
            TK = false;
            THK = false;
        }
        twoOfKind = false;
        threeOfKind = false;
        fullHouse = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 3333333333
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player1Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }

        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind = true;
            }
            if (bucket[i] == 3) {
                threeOfKind = true;
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight = true;
            Winners[2] = "STRAIGHT";
        }
        
        if (twoOfKind == true) {
            Winners[2] = "PAIR";
        }
        
        if (threeOfKind == true) {
            Winners[2] = "THREE OF A KIND";
        }
        
        if (twoOfKind == true && threeOfKind == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[2] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind == true) {
            TK = true;
        }
        if (threeOfKind == true) {
            THK = true;
        }
        if (fullHouse == true) {
            FH = true;
            TK = false;
            THK = false;
        }
        twoOfKind = false;
        threeOfKind = false;
        fullHouse = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 4444444
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player1Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind = true;
            }
            if (bucket[i] == 3) {
                threeOfKind = true;
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight = true;
            Winners[3] = "STRAIGHT";
        }
        
        if (twoOfKind == true) {
            Winners[3] = "PAIR";
        }
        
        if (threeOfKind == true) {
            Winners[3] = "THREE OF A KIND";
        }
        
        if (fullHouse == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[3] = "FULL HOUSE";
        }
        
        right = 2;
        left = 1;
        if (twoOfKind == true) {
            TK = true;
        }
        if (threeOfKind == true) {
            THK = true;
        }
        if (fullHouse == true) {
            FH = true;
            TK = false;
            THK = false;
        }
        twoOfKind = false;
        threeOfKind = false;
        fullHouse = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 555555
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player1Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind = true;
            }
            if (bucket[i] == 3) {
                threeOfKind = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight = true;
            Winners[4] = "STRAIGHT";
        }
        
        if (twoOfKind == true) {
            Winners[4] = "PAIR";
        }
        
        if (threeOfKind == true) {
            Winners[4] = "THREE OF A KIND";
        }
        
        if (twoOfKind == true && threeOfKind == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[4] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind == true) {
            TK = true;
        }
        if (threeOfKind == true) {
            THK = true;
        }
        if (fullHouse == true) {
            FH = true;
            TK = false;
            THK = false;
        }
        twoOfKind = false;
        threeOfKind = false;
        fullHouse = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 6666666
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player1Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind = true;
            }
            if (bucket[i] == 3) {
                threeOfKind = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight = true;
            Winners[5] = "STRAIGHT";
        }
        
        if (twoOfKind == true) {
            Winners[5] = "PAIR";
        }
        
        if (threeOfKind == true) {
            Winners[5] = "THREE OF A KIND";
        }
        
        if (twoOfKind == true && threeOfKind == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[5] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind == true) {
            TK = true;
        }
        if (threeOfKind == true) {
            THK = true;
        }
        if (fullHouse == true) {
            FH = true;
            TK = false;
            THK = false;
        }
        twoOfKind = false;
        threeOfKind = false;
        fullHouse = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 7777777
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player1Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind = true;
            }
            if (bucket[i] == 3) {
                threeOfKind = true;
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight = true;
            Winners[6] = "STRAIGHT";
        }
        
        if (twoOfKind == true) {
            Winners[6] = "PAIR";
        }
        
        if (threeOfKind == true) {
            Winners[6] = "THREE OF A KIND";
        }
        
        if (twoOfKind == true && threeOfKind == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[6] = "FULL HOUSE";
        }
        
        left = 2;
        right = 3;
        if (twoOfKind == true) {
            TK = true;
        }
        if (threeOfKind == true) {
            THK = true;
        }
        if (fullHouse == true) {
            FH = true;
            TK = false;
            THK = false;
        }
        twoOfKind = false;
        threeOfKind = false;
        fullHouse = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 88888
        
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player1Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind = true;
            }
            if (bucket[i] == 3) {
                threeOfKind = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight = true;
            Winners[7] = "STRAIGHT";
        }
        
        if (twoOfKind == true) {
            Winners[7] = "PAIR";
        }
        
        if (threeOfKind == true) {
            Winners[7] = "THREE OF A KIND";
        }
        
        if (twoOfKind == true && threeOfKind == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[7] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind == true) {
            TK = true;
        }
        if (threeOfKind == true) {
            THK = true;
        }
        if (fullHouse == true) {
            FH = true;
            TK = false;
            THK = false;
        }
        twoOfKind = false;
        threeOfKind = false;
        fullHouse = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 99999
        
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player1Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player1Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind = true;
            }
            if (bucket[i] == 3) {
                threeOfKind = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight = true;
            Winners[8] = "STRAIGHT";
        }
        
        if (twoOfKind == true) {
            Winners[8] = "PAIR";
        }
        
        if (threeOfKind == true) {
            Winners[8] = "THREE OF A KIND";
        }
        
        if (twoOfKind == true && threeOfKind == true) {
            fullHouse = true;
            twoOfKind = false;
            threeOfKind = false;
            Winners[8] = "FULL HOUSE";
        }
        
        twoOfKind = false;
        threeOfKind = false;
        fourOfKind = false;
        straight = false;
        fullHouse = false;
        
        for (int i = 0; i < 10; i++) {
            if (Winners[i] == "FULL HOUSE") {
                fullHouse = true;
                return;
            }
            if (Winners[i] == "FOUR OF A KIND") {
                fourOfKind = true;
                return;
            }
            if (Winners[i] == "THREE OF A KIND") {
                threeOfKind = true;
                return;
            }
            if (Winners[i] == "TWO OF A KIND") {
                twoOfKind = true;
                return;
            }
        }
        
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //This is exaclt the same as above except it checks player2's cards.
    
    else {
        cout << endl;
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        int temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[0] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            
            Winners[0] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            
            Winners[0] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[0] = "FULL HOUSE";
        }
        right++;
        if (twoOfKind2 == true) {
            TK2 = true;
        }
        if (threeOfKind2 == true) {
            THK2 = true;
        }
        if (fullHouse2 == true) {
            FH2 = true;
            TK2 = false;
            THK2 = false;
        }
        twoOfKind2 = false;
        threeOfKind2 = false;
        fullHouse2 = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 22222222222
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[1] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            Winners[1] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            Winners[1] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[1] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind2 == true) {
            TK2 = true;
        }
        if (threeOfKind2 == true) {
            THK2 = true;
        }
        if (fullHouse2 == true) {
            FH2 = true;
            TK2 = false;
            THK2 = false;
        }
        twoOfKind2 = false;
        threeOfKind2 = false;
        fullHouse2 = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 3333333333
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[2] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            Winners[2] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            Winners[2] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[2] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind2 == true) {
            TK2 = true;
        }
        if (threeOfKind2 == true) {
            THK2 = true;
        }
        if (fullHouse2 == true) {
            FH2 = true;
            TK2 = false;
            THK2 = false;
        }
        twoOfKind2 = false;
        threeOfKind2 = false;
        fullHouse2 = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 4444444
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[3] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            Winners[3] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            Winners[3] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[3] = "FULL HOUSE";
        }
        
        right = 2;
        left = 1;
        if (twoOfKind2 == true) {
            TK2 = true;
        }
        if (threeOfKind2 == true) {
            THK2 = true;
        }
        if (fullHouse2 == true) {
            FH2 = true;
            TK2 = false;
            THK2 = false;
        }
        twoOfKind2 = false;
        threeOfKind2 = false;
        fullHouse2 = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 555555
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[4] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            Winners[4] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            Winners[4] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[4] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind2 == true) {
            TK2 = true;
        }
        if (threeOfKind2 == true) {
            THK2 = true;
        }
        if (fullHouse2 == true) {
            FH2 = true;
            TK2 = false;
            THK2 = false;
        }
        twoOfKind2 = false;
        threeOfKind2 = false;
        fullHouse2 = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 6666666
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[5] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            Winners[5] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            Winners[5] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[5] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind2 == true) {
            TK2 = true;
        }
        if (threeOfKind2 == true) {
            THK2 = true;
        }
        if (fullHouse2 == true) {
            FH2 = true;
            TK2 = false;
            THK2 = false;
        }
        twoOfKind2 = false;
        threeOfKind2 = false;
        fullHouse2 = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 7777777
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[6] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            Winners[6] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            Winners[6] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[6] = "FULL HOUSE";
        }
        
        left = 2;
        right = 3;
        if (twoOfKind2 == true) {
            TK2 = true;
        }
        if (threeOfKind2 == true) {
            THK2 = true;
        }
        if (fullHouse2 == true) {
            FH2 = true;
            TK2 = false;
            THK2 = false;
        }
        twoOfKind2 = false;
        threeOfKind2 = false;
        fullHouse2 = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 88888
        
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[7] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            Winners[7] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            Winners[7] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[7] = "FULL HOUSE";
        }
        
        right++;
        if (twoOfKind2 == true) {
            TK2 = true;
        }
        if (threeOfKind2 == true) {
            THK2 = true;
        }
        if (fullHouse2 == true) {
            FH2 = true;
            TK2 = false;
            THK2 = false;
        }
        twoOfKind2 = false;
        threeOfKind2 = false;
        fullHouse2 = false;
        for (int i = 0; i < 14; i++) {
            bucket[i] = 0;
        }
        ///////////////////////////////////////////////// 99999
        
        for (int i = 0; i < 5; i++) {
            if (i == left) {
                currentHand[left] = player2Hand[0];
            }
            else if (i == right) {
                currentHand[right] = player2Hand[1];
            }
            else {
                currentHand[i] = fiveCards[i];
            }
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                if (currentHand[i].cardNumber == j) {
                    bucket[j]++;
                }
            }
        }
        
        
        
        temp = 0;
        
        for (int i = 1; i < 14; i++) {
            if (bucket[i] == 2) {
                twoOfKind2 = true;
            }
            if (bucket[i] == 3) {
                threeOfKind2 = true;
                
            }
            if (threeOfKind == true && twoOfKind == true) {
                fullHouse = true;
                threeOfKind = false;
                twoOfKind = false;
            }
            if (bucket[i] == 4) {
                fourOfKind2 = true;
            }
            if (bucket[i] == 1) {
                temp++;
            }
            if (bucket[i] == 0) {
                temp = 0;
            }
            
        }
        if (temp == 5) {
            straight2 = true;
            Winners[8] = "STRAIGHT";
        }
        
        if (twoOfKind2 == true) {
            Winners[8] = "PAIR";
        }
        
        if (threeOfKind2 == true) {
            Winners[8] = "THREE OF A KIND";
        }
        
        if (twoOfKind2 == true && threeOfKind2 == true) {
            fullHouse2 = true;
            twoOfKind2 = false;
            threeOfKind2 = false;
            Winners[8] = "FULL HOUSE";
        }
        
        twoOfKind2 = false;
        threeOfKind2 = false;
        fourOfKind2 = false;
        straight2 = false;
        fullHouse2 = false;
        
        for (int i = 0; i < 10; i++) {
            if (Winners[i] == "FULL HOUSE") {
                fullHouse2 = true;
                return;
            }
            if (Winners[i] == "FOUR OF A KIND") {
                fourOfKind2 = true;
                return;
            }
            if (Winners[i] == "THREE OF A KIND") {
                threeOfKind2 = true;
                return;
            }
            if (Winners[i] == "TWO OF A KIND") {
                twoOfKind2 = true;
                return;
            }
        }
        
        for (int i = 0; i < 15; i++) {
            bucket[i] = 0;
        }
        
    }
    
    
}


string Game::showHave(Player p) { //This method just returns what the above method found. What the player has, i.e. a three of a kind
    if (p.isPlayer1 == true) {
        if (FH == true) {
            return "FULL HOUSE";
        }
        if (THK == true) {
            return "THREE OF A KIND";
        }
        if (TK == true) {
            return "TWO OF A KIND";
        }
        
    }
    else if (p.isPlayer1 == false) {
        if (FH2 == true) {
            return "FULL HOUSE";
        }
        
        if (THK2 == true) {
            return "THREE OF A KIND";
        }
        if (TK2 == true) {
            return "TWO OF A KIND";
        }
        
    }
    return "NULL";
}




//Keep in mind this program does not include the fact that if both players have a pair or a three of a kind, it does not check whos its better. On top of that, if neither player has anything then it is also a tie. THis is incorrect because in this case the player with the higher card would win.

// "\u2666" == DIAMOND
// "\u2665" == HEARTS
// "\u2618" == CLUBS
// "\u2660" == SPADES











