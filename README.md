# Negri_CSCI2270_FinalProject
Texas Hold'em


This program is a simplified version of Texas Hold'em, where there are only two players. How this program works is described in detail in the program, however generally speaking, it uses a game class and a driver file called main.cpp to run the game. The deck is built using structs of type Card, which include their suit and card value. A loop is used to add 52 cards and every 14th card the number is reset to one and the suit will change (because there are 4 suits). Once the deck is built, it must be shuffled. Luckily c++ has a shuffle method in the algorithm library. Once the cards have been shuffled they are dealt to the two respective players. Each player is a struct of type Player that has their name, money, current bet, total bet, if they are player 1 or not (explained in code), how much money they have, and if they have folded or checked. If a player checks that means they did not bet, if you are not familiar with Texas Hold'em this will be come clearer playing the game and looking at the code descriptions. The code then uses a while loop to make sure the code runs 4 times because there are a maximum of 4 rouns in Texas Hold'em. Each round includes printing the cards on the table, which are store in an array, printing the players' cards, and gathering their bets. The bet gathering process is too complicated to explain in words without looking at the code however it should be made clear in the main.cpp file. Generally speaking however, player 1 is asked to make a bet and if he does it is stored, if not his check variable is set to true. Player2 is then asked to make their bet. This is where it gets somewhat complicated because he/she must bet the same or more than player1. If player1 checked player2 has the option to check, in which case the round ends. If player2 decides to bet, then the betting must go back to player1. Many if statements and while loops are used to accomplish this. Once again, looking at the main.cpp will make apparent how it works. 

Note: Keep in mind when playing the game that the program only checks pairs based on if they are pairs or not. If both players have a pair/three of a kind/full house, they are considered to be the same. This is not how traditional Texas Hold'em is played. Also keep in mind that the program only checks for these things and does not check for flush, royal flush, 4 of a kind, straight. These are things you could add.


Progression of the Game:

1. Player 1 Look at your cards.
2. Player 2 look at your cards.
3. Player 1 make a bet based on your two cards and the three on the table. Remember, you are betting based on the hand you have with the three on the table combined with your two. (Think five card poker). If you do not want to bet at this moment press 0 and the betting will move on to player2.
4. Player 2 does the same thing. Player 2, you must bet at least the same or more than player1. If you do not want to bet either press 0 and it will move onto the next round. If player2 bets more than player1 then player1 will be asked to be again. This will go back and forth until they match their bets.
5. The same thing will happen two more times. Each time one more card will be added to the three cards on the table. Remember, any combination you can make with your two cards and the 3, 4, or 5 cards on the table is valid.
6. If anyone folds at any point the other person wins.
7. Whoever has the better hand at the end wins the money in the pot.

INSTRUCTIONS ON HOW TO RUN:

Basically, just run the main file and instructions will be given as the program runs. One thing to pay attention to is sometimes it asks you to enter a number and other times it asks you to enter in anything. Please enter inputs accordingly otherwise to program will skip to the end and you won't get to play :/.

GROUP MEMBERS:

Just me.

OTHER CONTRIBUTORS:

None.

OPEN ISSUES/BUGS:

Sometimes it asks the user to enter in a number when it should work for any input.
Only checks for pairs, three of a kind, and full house. You could program straight, flush, four of a kind, and/or royal flush
Lacks a method for checking which hand is better (get rid of if statements at end of driver)
Does not allow for multiple games in the same run.




