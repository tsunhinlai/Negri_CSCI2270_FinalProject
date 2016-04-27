//
//  main.cpp
//  Five Card Poker
//
//  Created by Spencer Negri on 4/14/16.
//  Copyright © 2016 CU. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include <cstdlib>
#include <sstream>
#include <ctime>

using namespace std;

int main(int argc, const char * argv[]) {
    
    srand(time(NULL)); // Sets the time to be zero. This is necessary because otherwise the shuffle algorithm produces the same result each time.
    int pot = 0; // set pot to zero
    Game newPokerGame; // create new instance of Game
    int money, roundNumber = 1;
    string line, name, name1;
    
    newPokerGame.printMenu(); //Prints title menu
    
    newPokerGame.createDeck(); //Calls createDeck method. See createDeck for method description
    newPokerGame.shuffleDeck(); ///Calls shuffleDeck method. See shuffledeck for method description
        
     // Prints the title of my game and asks for names
    cout << "Please enter your two names: " << endl;
    
    getline(cin, line); // names are entered in on one line separaed by a space so getline is needed here
    stringstream ss(line);
    
    Player player1("none"); //Make two instances of the struct Player because there can only be two playesr
    Player player2("none");
    player1.isPlayer1 = true; // This is used to distinguish between players
    player2.isPlayer1 = false;
    ss >> name1;
    player1.name = name1;
    ss >> name1; //// stringstream the respective names in because they are separated by a space
    player2.name = name1;
    
    cout << "Please enter the amount of money you would like to give each player" << endl; // Allows user to enter in the amount of money they want to play with
    cin >> money;
    cin.ignore(); //This is used after every single cin statement in the project. To be honest I am not exatcly sure why this works, however it is directly related to the fact that getline gathers everything up to a new line and cin only goes to the next space.
    
    cout << "At any point if you would like to fold, type -1 for your bet " << endl;
    
    player1.money += money; //Gives each player desired amount of money
    player2.money += money;
    
    newPokerGame.dealCards(player1); //See dealCards description
    newPokerGame.dealCards(player2);
   
    ///////////////////// ROUND 1 ////////////////////////////////////////////////////////////////////////////////////
    
    cout << player1.name << ", when you are ready to see your hand press any number." << endl;
    cin >> player1.currentBet; //This is used to give player1 time before they want to see their cards. currentBet is set to 00 again almost immediatly
    cin.ignore();
    
    int lines = 0;
    
    
    newPokerGame.showHand(player1);
    
    lines = 0;
    while (lines < 50) {
        cout << endl;
        lines++;
    }
    
    cout << player1.name << " scroll up to see your cards" << endl;
    
    cout << player2.name << ", when you are ready to see your hand press any number." << endl;
    cin >> player2.currentBet;
    cin.ignore();
    
    
    
    
    newPokerGame.showHand(player2);
    
    lines = 0;
    while (lines < 50) {
        cout << endl;
        lines++;
    }
    
    cout << player2.name << " scroll up to see your cards" << endl;
    
   
    ///////////////////// ROUND 2 ////////////////////////////////////////////////////////////////////////////////////
    
    
    
    while ((player1.fold != true || player2.fold != true) && roundNumber < 4) { // There are a maximum of 4 rounds in Texas Hold'em and the loop should only run when both have not folded.
    
        
        cout << "When you are ready to see the five cards press any number" << endl;
        cin >> player1.currentBet;
        cin.ignore();
        player1.currentBet = 0; // sets their bets to 0 because they havent actually bet yet
        player2.currentBet = 0;
        lines = 0;
        while (lines < 50) {
            cout << endl;
            lines++;
        }
        
    newPokerGame.addCardto5Cards(); // See method description. This adds 3 cards to the face up cards on the table
    newPokerGame.show5Cards(); //Prints the cards on the table
    
    cout << player1.name << " when you are ready to see your hand press any key." << endl;
    cin.ignore(); //Gives time for player1 before he/she would like to see their cards
        
        
        
    
    newPokerGame.showHand(player1);
    
    cout << player1.name << " enter in how much you would like to bet. If you would like to check, enter 0." << endl;
        cout << "Remember you have: " << player1.money << " dollars." << endl;
    cin >> player1.currentBet; //Gets player1's bet
    cin.ignore();
        
    if (player1.currentBet == -1) { //Checks if they folded
        player1.fold = true;
        break;
    }
    
    if (player1.currentBet == 0) { //Checks if they checked (didnt place a bet)
        player1.check = true;
    }
    
        while (player1.currentBet < 0) { //This makes sure that player1 did not bet a negative number
            cout << "You cannot bet less than 0. Please enter another: " << endl;
            cin >> player1.currentBet;
            cin.ignore();
        }
    
    while (player1.currentBet > player1.money) { //This makes sure that player1 has enough money to make the bet
        cout << "You don't have enough money to make that bet. Please enter a different amount: " << endl;
        cin >> player1.currentBet;
        cin.ignore();
    }
    
    player1.bet += player1.currentBet; //Adds current bet to the total amount of money player1 has put in. Here bet is 0+current bet
    player1.money -= player1.currentBet;//Subtracts their current bet from their money
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////PLAYER 2 BETTING START////////////////////////////////////////////////////////////
    
    cout << player2.name << " when you are ready to see your hand press any key." << endl;
    cin.ignore();
        
        lines = 0;
        while (lines < 50) {
            cout << endl;
            lines++;
        }
    
    newPokerGame.show5Cards(); //Shows 3 cards on the table for player2 so they can make a bet
    newPokerGame.showHand(player2); //Shows their hand
    
    if (player1.check == true) { // IF PLAYER 1 CHECKED
        cout << player1.name << " checked. If you would like to check press 0. Otherwise enter your bet: " << endl; // Player 2 can check if they want, in which case the round will be over
        cout << "Remember you have: " << player2.money << " dollars." << endl;
        cin >> player2.currentBet;
        cin.ignore();
        player1.check = false;
        
        if (player2.currentBet == -1) { //Check for player2 fold
            player2.check = true;
            break;
        }
        
        ///////GET BET FROM PLAYER 2 ///////////
        
        while (player2.currentBet < 0) { //This makes sure that player1 did not bet a negative number
            cout << "You cannot bet less than 0. Please enter another: " << endl;
            cin >> player2.currentBet;
            cin.ignore();
        }
        
        while (player2.currentBet > player2.money) { // Checks if player2 has enough money
            cout << "You don't have enough money to make that bet. Please enter a different amount: " << endl;
            cin >> player2.currentBet;
            cin.ignore();
        }
        if (player2.currentBet == -1) { // Checks for fold again to be safe
            player2.check = true;
            break;
        }
        
        player2.bet += player2.currentBet; // Adds to bet
        player2.money -= player2.currentBet; // Subtracts from money
        
        lines = 0;
        while (lines < 50) {
            cout << endl;
            lines++;
        }
    
        if (player2.currentBet != 0) { // IF PLAYER 2 bet more than player1. In this case if player2 did anything but check this if statement will execute
            cout << player2.name << " raised " << player2.currentBet << ". "<< player1.name << " please enter your bet: " << endl; //Tells player1 that player2 raised and he/she must either match their bet or fold
            cout << "Remember you have: " << player1.money << " dollars." << endl;
            cin >> player1.currentBet;
            cin.ignore();
            
            if (player1.currentBet == -1) { //IF FOLD
                player1.check = true;
                break;
            }
            
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////Check Player 1 bet////////////////////////////////////////////////////////////
            
            while (player1.currentBet < 0) { //This makes sure that player1 did not bet a negative number
                cout << "You cannot bet less than 0. Please enter another: " << endl;
                cin >> player1.currentBet;
                cin.ignore();
            }
            
            while (player1.currentBet > player1.money) { // Checks if player1 has enough money
                cout << player1.name << " you do not have enough to make that bet. Please enter another: " << endl;
                cin >> player1.currentBet;
                cin.ignore();
            }
            
            while (player1.currentBet < player2.currentBet) { // Checks if player1 bet either the same or more than player2 (they must match player2 or bet more)
                cout << player1.name << " you must bet at least: " << player2.currentBet << endl;
                cin >> player1.currentBet;
                cin.ignore();
            }
            
            while (player1.check == true) { //If player2 raised player1, player1 is not allowed to check. This checks for this case.
                cout << player1.name << " you cannot check. Please enter another bet: "<< endl;
                cin >> player1.currentBet;
                cin.ignore();
            }
            
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            player1.bet += player1.currentBet; //Previously described
            player1.money -= player1.currentBet;
            
        }
        
    }
    
    else { //This is the case where player 1 did not check and entered in a bet.
    
        cout << player1.name << " bet " << player1.currentBet << " you must bet at least that much or more: " << endl; //Tells player2 how much player1 bet and how much they need to bet.
        cout << "Remember you have: " << player2.money << " dollars." << endl;
        cout << player2.name << " enter in how much you would like to bet." << endl;
        cin >> player2.currentBet;
        cin.ignore();
        
        if (player2.currentBet == -1) { //Checks for fold
            player1.check = true;
            break;
        }
        
        while (player2.currentBet < 0) { //This makes sure that player2 did not bet a negative number
            cout << "You cannot bet less than 0. Please enter another: " << endl;
            cin >> player2.currentBet;
            cin.ignore();
        }
        
        while (player2.currentBet > player2.money) { // All three while loops check for the same thing as they did above except for player2 this time
            cout << player2.name << " you do not have enough to make that bet. Please enter another: " << endl;
            cin >> player2.currentBet;
            cin.ignore();
        }
        
        while (player2.check == true) {
            cout << player2.name << " you cannot check. Please enter another bet: "<< endl;
            cin >> player2.currentBet;
            cin.ignore();
        }
        
        if (player2.currentBet == -1) { //Checks for fold again
            player2.check = true;
            break;
        }
        
        player2.bet += player2.currentBet;
        player2.money -= player2.currentBet;
        
    }
        
        string answer;
        int tempBet1 = 0, tempBet2 = 0; // These are needed for player1 and player2 respectively because if Player1 raises player2 or viceversa their current bets are going to change each time someone raises. Because of this, we dont want to store their current bets until they have equal bets.
        int count = 1; //This is used for print statements. The first time the while loop runs we want to use the players current bet but after the first time we only want to use their temporary bet.
        
        
        lines = 0;
        while (lines < 50) {
            cout << endl;
            lines++;
        }
        while (player1.currentBet != player2.currentBet) { //Cannot move on to next round until everyone has bet the same amount
            
            if (player1.currentBet < player2.currentBet) { //This checks to see who needs to match who. In this case player1 has not bet enough to match player 2.
                newPokerGame.show5Cards(); //SHow cards and hand again for player1
                newPokerGame.showHand(player1);
                if (player1.check == true) {
                    cout << player2.name << " bet " << player2.currentBet<<". "<<player1.name <<" you must bet at least that much" << endl;
                }
                else {
                    cout << player2.name << " raised " << player2.currentBet- player1.currentBet <<". "<<player1.name <<" you must bet at least that much" << endl;
                }
                
                cout << player1.name << " you have " << player1.money <<" dollars."<<endl; // Allows player to see how much money they have
                cin >> tempBet1;
                cin.ignore();
                
                if (tempBet1 == 0) {
                    player1.check = true;
                }
                
                while (tempBet1 < 0) { //This makes sure that player1 did not bet a negative number
                    cout << "You cannot bet less than 0. Please enter another: " << endl;
                    cin >> player1.currentBet;
                    cin.ignore();
                }
                
                while (tempBet1 > player1.money) { // All three while loops check for the same thing as they did above except for player2 this time
                    cout << player2.name << " you do not have enough to make that bet. Please enter another: " << endl;
                    cin >> tempBet1;
                    cin.ignore();
                }
                
                while (player1.check == true) {
                    cout << player2.name << " you cannot check. Please enter another bet: "<< endl;
                    cin >> tempBet1;
                    cin.ignore();
                }
                
                if (tempBet1 == -1) { //Checks for fold again
                    player1.check = true;
                    break;
                }
        
                player1.currentBet = player1.currentBet + tempBet1; // Update their current bet to be their previous bet plus their first bet and so on.
                player1.bet += player1.currentBet; // Add to total amount of bets
                player1.money = player1.money - tempBet1; //TAke the money they bet from them
            }
            
            lines = 0;
            while (lines < 50) {
                cout << endl;
                lines++;
            }
            
            if (player2.currentBet < player1.currentBet) { // This is the same as the previous if statement except for player2
                
                newPokerGame.show5Cards(); //SHow cards and hand again for player1
                newPokerGame.showHand(player2);
                cout << player1.name << " raised " << player1.currentBet- player2.currentBet <<". "<<player2.name <<" you must bet at least that much" << endl;
                
                cout << player2.name << " you have " << player2.money <<" dollars."<<endl;
                cin >> tempBet2;
                cin.ignore();
                
                if (tempBet2 == 0) {
                    player2.check = true;
                }
                
                while (tempBet1 < 0) { //This makes sure that player1 did not bet a negative number
                    cout << "You cannot bet less than 0. Please enter another: " << endl;
                    cin >> player1.currentBet;
                    cin.ignore();
                }
                
                while (tempBet2 > player2.money) { // All three while loops check for the same thing as they did above except for player2 this time
                    cout << player2.name << " you do not have enough to make that bet. Please enter another: " << endl;
                    cin >> player2.currentBet;
                    cin.ignore();
                }
                
                while (player2.check == true) { //They cannot check here
                    cout << player2.name << " you cannot check. Please enter another bet: "<< endl;
                    cin >> tempBet2;
                    cin.ignore();
                }
                
                if (player2.currentBet == -1) { //Checks for fold again
                    player2.check = true;
                    break;
                }
                

                player2.currentBet = player2.currentBet + tempBet2;
                player2.bet += player2.currentBet;
                player2.money = player2.money - tempBet2;
            }
            count++;
        }
        if (player1.currentBet == -1) { // check for fold once more to be safe
            player1.fold = true;
            break;
        }
        
        if (player2.currentBet == -1) {
            player2.fold = true;
            break;
        }
        
        roundNumber++;  //Increment the round number because the round is over
        player1.check = false; //Reset their check variables so they are able to check again in the next round
        player2.check = false;
        pot = pot + player1.currentBet; // Add their bets to the pot
        pot = pot + player2.currentBet;
        player1.currentBet = 0; // Reset their current bets
        player2.currentBet = 0;
}
    
    if (player1.fold == true) { //Since there are only two players, if one player folds the game is over and the other player wins automatically.
        cout << player2.name << "YOU WIN " << pot << " dollars!" << endl;
    }
    if (player2.fold == true) {
        cout << player1.name << " YOU WIN " << pot << " dollars!" << endl;
    }
    
    newPokerGame.checkCards(player1); //Checks cards to see what they have in their hands. See method description
    newPokerGame.checkCards(player2);
    cout << endl;
    
    
    cout <<player1.name<< " you had " <<newPokerGame.showHave(player1) << endl; //This method simply returns what they have. For example, it might return "TWO OF A KIND", depending on what this player has.
    cout << player2.name<< " you had "<< newPokerGame.showHave(player2) << endl;
    
    
    //The following if statements check to see who actually won the game and how much that person won. This Texas Hold'em game is missing many hands such as a four of a kind, straight, flush, and royal flush. Straight and royal flush are almost programmed however not included due to their unfinished state. See Game.cpp
    
    if (newPokerGame.showHave(player1) == "TWO OF A KIND" && newPokerGame.showHave(player2) == "NULL" ) {
        cout << player1.name << " you win " << pot << " dollars. Spend it wisely" << endl;
    }
    
    if (newPokerGame.showHave(player2) == "TWO OF A KIND" && newPokerGame.showHave(player1) == "NULL" ) {
        cout << player2.name << " you win " << pot << " dollars. Spend it wisely" << endl;
    }
    
    if (newPokerGame.showHave(player1) == "TWO OF A KIND" && newPokerGame.showHave(player2) == "TWO OF A KIND" ) {
        cout << "Its a tie. Both had a pair" << endl;
    }
    
    if (newPokerGame.showHave(player1) == "THREE OF A KIND" && newPokerGame.showHave(player2) == "TWO OF A KIND" ) {
        cout << player1.name << " you win " << pot << " dollars. Spend it wisely" << endl;
    }
    
    if (newPokerGame.showHave(player2) == "THREE OF A KIND" && newPokerGame.showHave(player1) == "TWO OF A KIND" ) {
        cout << player2.name << " you win " << pot << " dollars. Spend it wisely" << endl;
    }
    
    if (newPokerGame.showHave(player1) == "FULL HOUSE" && newPokerGame.showHave(player2) == "FULL HOUSE" ) {
        cout << "Its a tie. Both had a full house. RARE!" << endl;
    }
    
    if (newPokerGame.showHave(player2) == "FULL HOUSE" ) {
        cout << player2.name << " you win" << pot << "dollars. Spend it wisely" << endl;
    }
    
    if (newPokerGame.showHave(player1) == "FULL HOUSE" ) {
        cout << player1.name << " you win" << pot << "dollars. Spend it wisely" << endl;
    }
    
    if (newPokerGame.showHave(player1) == "NULL" && newPokerGame.showHave(player2) == "NULL" ) {
        cout << "Its a tie. Both had nothig..." << endl;
    }
    
    
}


