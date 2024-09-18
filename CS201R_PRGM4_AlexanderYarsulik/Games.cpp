#include "Games.h"

/*
* I do not think I was in class when we were taught what was needed
* to make "Pseudo-code", so I have not included anything of that sort.
*
* If such is required, please contact me about it.
*
* LLM was used for the Blackjack and Hangman game (ChatGPT (free version)).
* I have commented my understanding of the generated code before
* the definitions of those functions.
*/


void setColor(int textColor) { // Sets the console color to the input integer's assigned color
    cout << "\033[" << textColor << "m";
}

void resetColor() { // Resets the console color
    cout << "\033[0m";
}

int rollDie() {
    int x, y, z;
    srand(time(0));
    Sleep(1000);
    x = (rand() % 6) + 1;
    y = (rand() % 6) + 1;
    z = x + y;
    cout << "\tRoll was: ";
    setColor(91); // Bright Red
    cout << x;
    resetColor();
    cout << " + ";
    setColor(92); // Bright Green
    cout << y;
    resetColor();
    cout << " = ";
    setColor(94); // Bright Blue
    cout << z << endl;
    resetColor();
    return z;
}

int rollScrapsDie() {
    int a;
    srand(time(0));
    Sleep(1000);
    a = (rand() % 8) + 1;
    return a;
}

bool scrapsDieTotal() {
    int a, b, c, tempTotal, userPoint;

    cout << "\tYou rolled: ";
    setColor(31); // Red
    a = rollScrapsDie();
    cout << a;
    resetColor();
    cout << " + ";
    setColor(32); // Green
    b = rollScrapsDie();
    cout << b;
    resetColor();
    cout << " + ";
    setColor(34); // Blue
    c = rollScrapsDie();
    cout << c;
    resetColor();
    cout << " = ";
    setColor(35); // Magenta
    tempTotal = a + b + c;
    cout << tempTotal << endl;
    resetColor();

    if ((a == 8) || (b == 8) || (c == 8)) { // Where the user rolls an 8 on the first round
        cout << "\tYou rolled an 8! YOU WIN!\n";
        return true;
    }
    else if ((tempTotal == 9) || (tempTotal == 10) || (tempTotal == 14)) { // Where the user rolls a total of 9, 10, or 14 on the first round
        cout << "\tYou rolled a total of 9, 10, or 14! YOU WIN!\n";
        return true;
    }
    else if ((a == 1) || (b == 1) || (c == 1)) { // Where the user rolls a 1 on the first round
        cout << "\tYou rolled a 1! YOU LOSE!\n";
        return false;
    }
    else if ((tempTotal == 8) || (tempTotal == 20) || (tempTotal == 23) || (tempTotal == 24)) { // Where the user rolls a total of 8, 20, 23 or 24 on the first round
        cout << "\tYou rolled a total of 8, 20, 23, or 24! YOU LOSE!\n";
        return true;
    }
    else {
        // This branch activates when the user does not roll a winning or losing number on their first round.
        // Whatever number the user got is now what the user has to roll in order to win, called the userPoint.
        // Now, if the user rolls an 8 on any dice, or a total of 15, they lose. If they roll the userPoint, they win.
        userPoint = tempTotal;
        tempTotal = 0;
        while ((tempTotal != userPoint) && (tempTotal != 15)) { // This while loop will continue until the user wins or loses
            cout << "\tPoint is: ";
            setColor(95);
            cout << userPoint << endl;
            resetColor();

            cout << "\tYou rolled: ";
            setColor(31); // Red
            a = rollScrapsDie();
            cout << a;
            resetColor();
            cout << " + ";
            setColor(32); // Green
            b = rollScrapsDie();
            cout << b;
            resetColor();
            cout << " + ";
            setColor(34); // Blue
            c = rollScrapsDie();
            cout << c;
            resetColor();
            cout << " = ";
            setColor(35); // Magenta
            tempTotal = a + b + c;
            cout << tempTotal << endl;
            resetColor();

            if (tempTotal == userPoint) { // WIN: Where the user rolls the userPoint
                cout << "\tYou rolled the Point! YOU WIN!\n";
                return true;
            }
            else if ((a == 8) || (b == 8) || (c == 8)) { // LOSS: Where the user rolls an 8 in the loop
                cout << "\tYou rolled an 8! YOU LOSE!\n";
                return false;
            }
            else if (tempTotal == 15) { // LOSS: Where the user rolls a total of 15 in the loop
                cout << "\tYou rolled a total of 15! YOU LOSE!\n";
                return false;
            }
        }

    }
}

void craps() {
    char userChoice = 'Y';
    int userRoll = 0;
    double userMoney = 50.00;
    setColor(32); // Green
    cout << "\t=================\n";
    cout << "\tWELCOME TO CRAPS!\n";
    cout << "\t=================\n";
    resetColor();

    while (userChoice != 'N') {
        int userBet = 0;
        int userPoint = 0;
        cout << "\n\tYour net worth is: $";
        setColor(32); // Green
        cout << userMoney;
        resetColor();
        cout << ".\n";

        if (userMoney <= 0.1) { // Checks if the user has enough money to play Craps. If not, the game terminates.
            cout << "\tYou no longer have enough money to play Craps!\n";
            setColor(31); // Red
            cout << "\n\t==================\n";
            cout << "\tTerminating Craps!\n";
            cout << "\t==================\n";
            resetColor();
            break;
        }

        cout << "\tPlease enter your desired bet amount: $";
        setColor(32); // Green
        cin >> userBet; // Takes in the user bet input
        resetColor();

        while (userBet > userMoney) { // Checks for improper betting amounts
            cout << "\n\tYour net worth is only: $";
            setColor(32); // Green
            cout << userMoney << ".\n";
            resetColor();
            cout << "\tPlease adjust your bet: $";
            setColor(32); // Green
            cin >> userBet;
            resetColor();
        }

        userMoney -= userBet; // Where the user's money is subtracted by the input bet amount

        userRoll = rollDie();
        if ((userRoll == 7) || (userRoll == 11)) { // Where the user gets 7 or 11 on the first round
            userMoney += (userBet * 2);
            cout << "\tYay, you Win!! You now have: $";
            setColor(32); // Green
            cout << userMoney << endl;
            resetColor();
        }
        else if ((userRoll == 2) || (userRoll == 3) || (userRoll == 12)) { // Where the user gets 2, 3 or 12 on the first round
            cout << "\tSorry, but you lost!! You now have: $";
            setColor(32); // Green
            cout << userMoney << endl;
            resetColor();
        }
        else {
            // This branch activates when the user does not roll a winning or losing number on their first round.
            // Whatever number the user got is now what the user has to roll in order to win, called the userPoint.
            // Now, the losing number is 7. If the user rolls a 7, they lose. If they roll the userPoint, they win.
            userPoint = userRoll;
            userRoll = 0;
            while ((userRoll != userPoint) && (userRoll != 7)) { // This while loop will continue until the winning number or 7 is rolled
                cout << "\t\tPoint is: ";
                setColor(34); // Blue
                cout << userPoint << endl;
                resetColor();
                userRoll = rollDie();
            }
            if (userRoll == 7) { // User rolls a 7 and loses
                cout << "\t\tSorry, but you lost!! You now have: $";
                setColor(32);
                cout << userMoney << endl;
                resetColor();
            }
            else { // User rolls the winning number
                userMoney += (userBet * 2);
                cout << "\t\tYay, you Win!! You now have: $";
                setColor(32);
                cout << userMoney << endl;
                resetColor();
            }
        }
        bool userChoiceCheck = false; // The condition for the end of the while loop
        while (userChoiceCheck != true) { // While the user has not input a proper 'Y' or 'N'
            cout << "\n\tWould you like to go again? Y or N: ";
            cin >> userChoice;
            if ((userChoice != 'Y') && (userChoice != 'N')) { // Catches improper inputs
                setColor(31); // Red
                cout << "\n\t========================================\n";
                cout << "\tImproper input. Only 'Y' or 'N' allowed.\n";
                cout << "\t========================================\n";
                resetColor();
                continue; // Continues the while loop
            }
            else if (userChoice == 'N') { // User chooses to stop playing craps
                setColor(97); // Bright White
                cout << "\n\t==================\n";
                cout << "\tTerminating Craps!\n";
                cout << "\t==================\n";
                resetColor();
                userChoiceCheck = true;
            }
            else { // User chooses to run another game of craps
                setColor(97); // Bright White
                cout << "\n\t================================\n";
                cout << "\tRunning another game of Craps...\n";
                cout << "\t================================\n";
                resetColor();
                userChoiceCheck = true;
            }
        }

    }
}

void scraps() {
    char userChoice = 'Y';
    int userRoll1, userRoll2, userRoll3, userTotal;
    double userMoney = 50.00;
    setColor(92); // Bright Green
    cout << "\n\t==================\n";
    cout << "\tWELCOME TO SCRAPS!\n";
    cout << "\t==================\n";
    resetColor();

    while (userChoice != 'N') {
        int userBet = 0;
        int userPoint = 0;
        cout << "\n\tYour net worth is: $";
        setColor(92); // Bright Green
        cout << userMoney;
        resetColor();
        cout << ".\n";

        if (userMoney <= 0.1) { // Checks if the user has enough money to play Craps. If not, the game terminates.
            cout << "\tYou no longer have enough money to play Scraps!\n";
            setColor(31); // Red
            cout << "\n\t===================\n";
            cout << "\tTerminating Scraps!\n";
            cout << "\t===================\n";
            resetColor();
            userChoice = 'N';
            break;
        }

        cout << "\tPlease enter your desired bet amount: $";
        setColor(92); // Bright Green
        cin >> userBet; // Takes in the user bet input
        resetColor();

        while (userBet > userMoney) { // Checks for improper betting amounts
            cout << "\n\tYour net worth is only: $";
            setColor(92); // Bright Green
            cout << userMoney;
            resetColor();
            cout << ".\n";

            cout << "\tPlease adjust your bet: $";
            setColor(92); // Bright Green
            cin >> userBet;
            resetColor();
        }

        userMoney -= userBet; // Where the user's money is subtracted by the input bet amount

        bool win_or_lose = scrapsDieTotal();

        if (win_or_lose == true) {
            userMoney += (userBet * 2);
        }
        cout << "\tYou now have: $";
        setColor(92); // Bright Green
        cout << userMoney << endl;
        resetColor();

        bool userChoiceCheck = false; // The condition for the end of the while loop
        while (userChoiceCheck != true) { // While the user has not input a proper 'Y' or 'N'
            cout << "\tWould you like to go again? Y or N: ";
            cin >> userChoice;
            if ((userChoice != 'Y') && (userChoice != 'N')) { // Catches improper inputs
                setColor(31); // Red
                cout << "\n\t========================================\n";
                cout << "\tImproper input. Only 'Y' or 'N' allowed.\n";
                cout << "\t========================================\n";
                resetColor();
                continue; // Continues the while loop
            }
            else if (userChoice == 'N') { // User chooses to stop playing craps
                setColor(97); // Bright White
                cout << "\n\t===================\n";
                cout << "\tTerminating Scraps!\n";
                cout << "\t===================\n";
                resetColor();
                userChoiceCheck = true;
            }
            else { // User chooses to run another game of craps
                setColor(97); // Bright White
                cout << "\n\t=================================\n";
                cout << "\tRunning another game of Scraps...\n";
                cout << "\t=================================\n";
                resetColor();
                userChoiceCheck = true;
            }
        }

    }
}

void rockPaperScissors() {
    char options[3] = { 'R','P','S' };
    char userPick, compPick, userContinue = 'Y';
    bool userContinueCheck = false;

    setColor(31); // Red
    cout << "\n\t=================================\n";
    cout << "\tWELCOME TO ROCK, PAPER, SCISSORS!\n";
    cout << "\t=================================\n";
    resetColor();

    while (userContinueCheck == false) {

        srand(time(0));

        cout << "\n\tEnter your choice (as a single letter): R (rock), P (paper), S (scissors): ";
        cin >> userPick;

        userPick = toupper(userPick);

        if ((userPick != 'R') && (userPick != 'P') && (userPick != 'S')) {
            setColor(31); // Red
            cout << "\n\t======================================\n";
            cout << "\tInvalid user choice. Please try again.\n";
            cout << "\t======================================\n";
            resetColor();
            continue;
        }

        string userPickWord;

        if (userPick == 'R') {
            cout << "\n\t\tYou picked: ROCK" << endl;
            userPickWord = "ROCK";
        }
        else if (userPick == 'P') {
            cout << "\n\t\tYou picked: PAPER" << endl;
            userPickWord = "PAPER";
        }
        else {
            cout << "\n\t\tYou picked: SCISSORS" << endl;
            userPickWord = "SCISSORS";
        }

        int optionPick = rand() % 3; // A random option of the R,P,S array is chosen,
        compPick = options[optionPick]; // And the computer "picks" whichever letter is assigned to the number randomly generated.

        string compPickWord;

        if (compPick == 'R') {
            compPickWord = "ROCK";
        }
        else if (compPick == 'P') {
            compPickWord = "PAPER";
        }
        else {
            compPickWord = "SCISSORS";
        }

        Sleep(1000);

        cout << "\n\t\tComputer picked: " << compPickWord << "\n\n";

        Sleep(1000);

        if (userPick == compPick) { // If the user and computer pick the same letter.
            setColor(97); // Bright White
            cout << "\t\tYOU TIED: " << userPickWord << " = " << compPickWord << endl;
            resetColor();
        }
        else if (userPick == 'P') { // If user picks paper,
            if (compPick == 'R') { // And the computer picks rock, the player wins.
                setColor(32); // Green
                cout << "\t\tWIN: PAPER covers ROCK\n";
                resetColor();
                // Increment win count
            }
            else { // And the computer picks scissors, the player loses.
                setColor(31); // Red 
                cout << "\t\tLOSE: SCISSORS cut PAPER\n";
                resetColor();
            }
        }
        else if (userPick == 'R') { // If user picks rock,
            if (compPick == 'S') { // And the computer picks scissors, the player wins.
                setColor(32); // Green
                cout << "\t\tWIN: ROCK smashes SCISSORS\n";
                resetColor();
                // Increment win count
            }
            else { // And the computer picks paper, the player loses.
                setColor(31); // Red 
                cout << "\t\tLOSE: PAPER covers ROCK\n";
                resetColor();
            }
        }
        else if (userPick == 'S') { // If user picks scissors,
            if (compPick == 'P') { // And the computer picks paper, the player wins.
                setColor(32); // Green
                cout << "\t\tWIN: SCISSORS cut PAPER\n";
                resetColor();
                // Increment win count
            }
            else { // And the computer picks rock, the player loses.
                setColor(31); // Red 
                cout << "\t\tLOSE: ROCK Smashes SCISSORS\n";
                resetColor();
            }
        }

        cout << "\n\tDo you want to play Rock Paper Scissors again? (Y/N): "; // Prompts the user to either continue or end the game.

        cin >> userContinue;
        userContinue = toupper(userContinue);

        if ((userContinue != 'Y') && (userContinue != 'N')) { // Catches invalid user inputs (not 'Y' or 'N') and defaults to continuing the game.
            setColor(31); // Red
            cout << "\n\t========================================\n";
            cout << "\tInvalid entry. Defaulting to play again.\n";
            cout << "\t========================================\n";
            resetColor();
        }
        else if (userContinue == 'N') {
            setColor(97); //Bright White
            cout << "\n\t====================================\n";
            cout << "\tTerminating Rock, Paper, Scissors...\n";
            cout << "\t====================================\n";
            resetColor();
            userContinueCheck = true;
        }
        else {
            setColor(97); //Bright White
            cout << "\n\t==================================================\n";
            cout << "\tStarting another round of Rock, Paper, Scissors...\n";
            cout << "\t==================================================\n";
            resetColor();
        }
    }

}

void rockPaperScissorsSpock() {
    char options[4] = { 'R','P','S','K' };
    char userPick, compPick, userContinue = 'Y';
    string userPickWord;
    bool userContinueCheck = false;

    setColor(91); // Bright Red
    cout << "\n\t========================================\n";
    cout << "\tWELCOME TO Rock, Paper, Scissors, Spock!\n";
    cout << "\t========================================\n";
    resetColor();

    while (userContinueCheck == false) {

        srand(time(0));

        Sleep(1000);

        cout << "\n\tEnter your choice (as the simplified letters): R (rock), P (paper), S (scissors), K (Spock): ";
        cin >> userPick;
        userPick = toupper(userPick);

        if ((userPick != 'R') && (userPick != 'P') && (userPick != 'S') && (userPick != 'K')) {
            setColor(31); // Red
            cout << "\n\t======================================\n";
            cout << "\tInvalid user choice. Please try again.\n";
            cout << "\t======================================\n";
            resetColor();
            continue;
        }

        Sleep(1000);

        if (userPick == 'R') {
            cout << "\n\t\tYou picked: ROCK\n" << endl;
            userPickWord = "ROCK";
        }
        else if (userPick == 'P') {
            cout << "\n\t\tYou picked: PAPER\n" << endl;
            userPickWord = "PAPER";
        }
        else if (userPick == 'S') {
            cout << "\n\t\tYou picked: SCISSORS\n" << endl;
            userPickWord = "SCISSORS";
        }
        else {
            cout << "\n\t\tYou picked: SPOCK\n" << endl;
            userPickWord = "SPOCK";
        }

        int optionPick = rand() % 4; // A random option of the R,P,S array is chosen,
        compPick = options[optionPick]; // And the computer "picks" whichever letter is assigned to the number randomly generated.

        string compPickWord;

        if (compPick == 'R') {
            compPickWord = "ROCK";
        }
        else if (compPick == 'P') {
            compPickWord = "PAPER";
        }
        else if (compPick == 'S') {
            compPickWord = "SCISSORS";
        }
        else {
            compPickWord = "SPOCK";
        }

        Sleep(1000);

        cout << "\t\tComputer picked: " << compPickWord;
        cout << "\n\n";

        Sleep(1000);

        if (userPick == compPick) { // If the user and computer pick the same letter.
            setColor(97); // Bright White
            cout << "\t\tYOU TIED: " << userPickWord << " = " << compPickWord << endl;
            resetColor();
        }
        else if (userPick == 'P') { // If user picks paper,
            if (compPick == 'R') { // And the computer picks rock, the player wins.
                setColor(32); // Green
                cout << "\t\tWIN: PAPER covers ROCK\n";
                resetColor();
                // Increment win count
            }
            else if (compPick == 'S') { // And the computer picks scissors, the player loses.
                setColor(31); // Red
                cout << "\t\tLOSE: SCISSORS cut PAPER\n";
                resetColor();
            }
            else { // Computer picks SPOCK, player wins
                setColor(32); // Green
                cout << "\t\tWIN: PAPER exposes SPOCK as a fraud\n";
                resetColor();
            }
        }
        else if (userPick == 'R') { // If user picks rock,
            if (compPick == 'S') { // And the computer picks scissors, the player wins.
                setColor(32); // Green
                cout << "\t\tWIN: ROCK smashes SCISSORS\n";
                resetColor();
                // Increment win count
            }
            else if (compPick == 'P') { // And the computer picks paper, the player loses.
                setColor(31); // Red
                cout << "\t\tLOSE: PAPER covers ROCK\n";
                resetColor();
            }
            else { // Computer picks SPOCK, player loses
                setColor(31); // Red
                cout << "\t\tLOSE: SPOCK pulverizes ROCK\n";
                resetColor();
            }
        }
        else if (userPick == 'S') { // If user picks scissors,
            if (compPick == 'P') { // And the computer picks paper, the player wins.
                setColor(32); // Green
                cout << "\t\tWIN: SCISSORS cut PAPER\n";
                resetColor();
                // Increment win count
            }
            else if (compPick == 'R') { // And the computer picks rock, the player loses.
                setColor(31); // Red
                cout << "\t\tLOSE: ROCK Smashes SCISSORS\n";
                resetColor();
            }
            else { // Computer picks SPOCK, player loses
                setColor(31); // Red
                cout << "\t\tLOSE: SPOCK uses SCISSORS\n";
                resetColor();
            }
        }
        else if (userPick == 'K') { // If user picks SPOCK,
            if (compPick == 'R') { // And the computer picks ROCK, the player wins
                setColor(32); // Green
                cout << "\t\tWIN: SPOCK pulverizes ROCK\n";
                resetColor();
            }
            else if (compPick == 'P') { // And the computer picks PAPER, the player loses
                setColor(31); // Red
                cout << "\t\tLOSE: PAPER exposes SPOCK as a fraud\n";
                resetColor();
            }
            else { // And the computer picks SCISSORS, the player wins
                setColor(32); // Green
                cout << "\t\tWIN: SPOCK uses SCISSORS\n";
                resetColor();
            }
        }

        cout << "\n\tDo you want to play Rock, Paper, Scissors, Spock again? (Y/N): "; // Prompts the user to either continue or end the game.

        cin >> userContinue;
        userContinue = toupper(userContinue);

        if ((userContinue != 'Y') && (userContinue != 'N')) { // Catches invalid user inputs (not 'Y' or 'N') and defaults to continuing the game.
            setColor(31); // Red
            cout << "\n\t========================================\n";
            cout << "\tInvalid entry. Defaulting to play again.\n";
            cout << "\t========================================\n";
            resetColor();
        }
        else if (userContinue == 'N') {
            setColor(97); // Bright White
            cout << "\n\t===========================================\n";
            cout << "\tTerminating Rock, Paper, Scissors, Spock...\n";
            cout << "\t===========================================\n";
            resetColor();
            userContinueCheck = true;
        }
        else {
            setColor(97); // Bright White
            cout << "\n\t=========================================================\n";
            cout << "\tStarting another round of Rock, Paper, Scissors, Spock...\n";
            cout << "\t=========================================================\n";
            resetColor();
        }
    }

}

/*
====================
BLACKJACK LLM PROMPT
====================

USING CHATGPT (free)

in c++, using namespacestd, create a game of blackjack that will be played between the user and the computer.
When the game starts, initialize a deck of 52 cards and 2 empty hands (the player and computer hands).

=============================================================================
The output was left mostly unedited, but I put in a bit of formatting changes
and commented throughout the set of code to show that I understand what the
LLM did to make the game of Blackjack.
=============================================================================
*/

int blackjack() {
    const int DECK_SIZE = 52; // Initializing the limits of the decks and initial hand size
    const int INITIAL_CARDS = 2;

    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    vector<Card> deck; // Initializing the vectors for the overall deck,
    vector<Card> playerHand; // The player's hand,
    vector<Card> dealerHand; // and the dealer's hand. These vectors will store struct Card instances.

    // Initialize and shuffle deck
    initializeDeck(deck);
    shuffleDeck(deck);

    // Deal initial cards
    for (int i = 0; i < INITIAL_CARDS; ++i) {
        playerHand.push_back(drawCard(deck));
        dealerHand.push_back(drawCard(deck));
    }

    // Player's turn
    char choice;
    bool playerBusted = false; // Tracker for the player "Busting" (going over 21 points, which is essentially an automatic loss)

    setColor(35); // Magenta
    cout << "\t=====================\n";
    cout << "\tWelcome to Blackjack!\n";
    cout << "\t=====================\n\n";
    resetColor();

    while (true) {
        displayHand(playerHand, "Player");

        cout << "\n\tDo you want to (h)it or (s)tand? ";
        cin >> choice;

        if (choice == 'h') {
            playerHand.push_back(drawCard(deck));
            if (calculateHandValue(playerHand) > 21) {
                playerBusted = true;
                break;
            }
        }
        else if (choice == 's') {
            break;
        }
        else { // If the player does not input 'h' or 's', the loop continues until the player does
            setColor(31);
            cout << "\t========================================\n";
            cout << "\tInvalid choice. Please enter 'h' or 's'.\n";
            cout << "\t========================================\n";
            resetColor();
        }
    }

    // Dealer's turn
    if (!playerBusted) {
        setColor(91); // Bright Red
        cout << "\n\t==============\n";
        cout << "\tDealer's turn:\n";
        cout << "\t==============\n";
        resetColor();
        displayHand(dealerHand, "Dealer");

        while (calculateHandValue(dealerHand) < 17) { // The dealer will never attempt to draw cards if their point value is 17 or greater
            dealerHand.push_back(drawCard(deck));
            displayHand(dealerHand, "Dealer");
        }
    }

    // Determine the winner
    int playerTotal = calculateHandValue(playerHand);
    int dealerTotal = calculateHandValue(dealerHand);

    Sleep(500); // Sleep for 500 miliseconds

    if (playerBusted) { // LOSS: Player has over 21 points
        setColor(31); // Red
        cout << "\n\t========================\n";
        cout << "\tYou busted! Dealer wins.\n";
        cout << "\t========================\n";
        resetColor();
    }
    else if (dealerTotal > 21 || playerTotal > dealerTotal) { // WIN: Dealer busted, or player value greater than dealer
        setColor(32); // Green
        cout << "\n\t========\n";
        cout << "\tYou win!\n";
        cout << "\t========\n";
        resetColor();
    }
    else if (playerTotal < dealerTotal) { // LOSS: player value lesser than dealer
        setColor(31); // Red
        cout << "\n\t============\n";
        cout << "\tDealer wins.\n";
        cout << "\t============\n";
        resetColor();
    }
    else { // Player value == dealer value
        setColor(97); // Bright White
        cout << "\n\t===========\n";
        cout << "\tIt's a tie!\n";
        cout << "\t===========\n";
        resetColor();
    }

    return 0;

}

// Initialize deck with 52 cards
void initializeDeck(vector<Card>& deck) {
    const string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    for (const string& suit : suits) { // For each suit,
        for (int value = 1; value <= 10; ++value) { // For each integer between 1 and 10 (inclusive),
            deck.push_back({ value, suit }); // Create a card of that value and suit and push that back into the overall deck
        }
    }
}

// Shuffle deck
void shuffleDeck(vector<Card>& deck) { // Using an already defined function (from algorithm include), shuffle the deck
    random_shuffle(deck.begin(), deck.end());
}

// Draw a card from the deck
Card drawCard(vector<Card>& deck) {
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// Calculate the total value of a hand
int calculateHandValue(const vector<Card>& hand) {
    int total = 0;
    for (const Card& card : hand) { // For each card in the hand being calculated,
        total += card.value; // summate all cards
    }
    return total; // return the total
}

// Display the hand of cards
void displayHand(const vector<Card>& hand, const string& playerName) {
    cout << "\t";
    setColor(97); // Bright White
    cout << playerName;
    resetColor();
    cout << "'s hand: ";
    for (const Card& card : hand) { // For each card in the hand being accessed,
        cout << "\n\t";
        displayCard(card); // Display the card
        Sleep(500);
    }
    cout << "\n\t(Total: ";
    setColor(92); // Bright Green
    cout << calculateHandValue(hand);
    resetColor();
    cout << ")" << endl;
}

// Display a single card
void displayCard(const Card& card) {
    if (card.value == 1) {
        setColor(31); // Red
        cout << "A";
        resetColor();
    }
    else if (card.value == 10) {
        setColor(36); // Cyan
        cout << "10";
        resetColor();
    }
    else {
        cout << card.value;
    }
    cout << " of ";
    setColor(97); // Bright White
    cout << card.suit;
    resetColor();
}

/*
==================
HANGMAN LLM REPORT
==================

USING CHATGPT (free)

in C++, using namespacestd, make a game of hangman taking the
words-to-be-guessed as input from a resource file named "words.txt"

===============================================================
Very simple, I know. I've also gone through this set of code,
commenting my understanding of what the LLM did to make it.
I've also edited the code to add formatting changes and to make
the game ask if the player wants to start another round.
===============================================================
*/

// Display the "word"
void displayWord(const string& word, const vector<bool>& guessed) { // This is how the readout shows the word and the letters already guessed.
    for (size_t i = 0; i < word.length(); ++i) {
        setColor(97); // Bright White
        if (guessed[i]) { // If the letter has been marked as guessed,
            cout << word[i]; // Output the letter
        }
        else { // If the letter has not been marked as guessed,
            cout << '_'; // Output a 'Blank' space
        }
        resetColor();
        cout << ' ';
    }
    cout << endl;
}

// Check the boolean values of each letter of the "word"
bool allGuessed(const vector<bool>& guessed) { // This function will keep track of the "win condition", namely that the word has, indeed, been guessed
    return all_of(guessed.begin(), guessed.end(), [](bool g) { return g; });
}

// Select and return a random "word"
string selectRandomWord(const vector<string>& words) {
    if (words.empty()) return "";                    // If the words vector is empty, return an empty string
    srand(static_cast<unsigned>(time(0)));           // Seed the random number generator
    int index = rand() % words.size();               // Create an int, assign to that int a random number generated within the size of the vector of strings
    return words[index];                             // Return, as a string, whatever word is at that index of the words vector
}

int hangman() {

    ifstream file("words.txt");
    if (!file.is_open()) {                                      // Checks to see if the file was successfully opened
        cerr << "\tError opening file 'words.txt'" << endl;
        return 1;
    }

    vector<string> words;                                       // Creates the vector that will hold the words from the input file
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            words.push_back(line);                              // Push back each word to the words vector
        }
    }
    file.close();                                               // Closes the file

    if (words.empty()) {                                        // If the input file has no text in it, the function returns and ends
        cerr << "\tNo words available in 'words.txt'" << endl;
        return 1;
    }

    setColor(36); // Cyan
    cout << "\n\t===================\n";
    cout << "\tWelcome to Hangman!\n";
    cout << "\t===================\n";
    resetColor();

    char userChoice = 'Y';                                      // What the user will use to end or continue the game

    while (userChoice != 'N') {

        string word = selectRandomWord(words);                  // Randomly select a word from the list

        vector<bool> guessed(word.length(), false);             // Creates a vector of boolean values, the same length as the randomly selected word,
        // and assigns all of them to false
        int wrongGuesses = 0;
        const int maxWrongGuesses = 6;
        string guessedLetters;

        while (wrongGuesses < maxWrongGuesses && !allGuessed(guessed)) { // The game loop starts here
            cout << "\n\tCurrent word: ";
            displayWord(word, guessed);                         // Calls the displayWord function to show the player the number
            // of letters in the word, and what letters the player has guessed
            cout << "\tGuess a letter: ";
            char guess;
            cin >> guess;
            guess = tolower(guess);                             // Convert to lowercase for consistency

            if (guessedLetters.find(guess) != string::npos) {   // If the program finds that the player has already guessed the input letter,
                cout << "\tYou've already guessed that letter." << endl;
                continue;                                       // the program will fall back to the beginning of the loop, showing the word
            }

            guessedLetters += guess;

            bool correctGuess = false;                          // This set of code iterates through the specific word
            for (size_t i = 0; i < word.length(); ++i) {        // 
                if (word[i] == guess) {                         // If the letter is in the word,
                    guessed[i] = true;                          // assigns the letter at that index location to true
                    correctGuess = true;                        // and signals that the guessed letter was in the word
                }
            }

            if (!correctGuess) {                                // If the guessed letter was not found in the word,
                ++wrongGuesses;                                 // Iterate wrongGuesses integer
                cout << "\tIncorrect guess. You have " << (maxWrongGuesses - wrongGuesses) << " guesses left." << endl;
            }

            cout << endl;
        }

        if (allGuessed(guessed)) {                              // If the allGuessed function returned true, Player has won
            setColor(97); // Bright White
            cout << "\n\t=========================================\n";
            cout << "\tCongratulations! You've guessed the word:\n";
            cout << "\t" << word << endl;
            cout << "\t=========================================\n";
            resetColor();
        }
        else {
            setColor(31); // Red
            cout << "\n\t=========================\n";
            cout << "\tGame over! The word was:\n";
            cout << "\t" << word << endl;
            cout << "\t=========================\n";
            resetColor();
        }

        bool userChoiceCheck = false;                           // The condition for the end of the while loop
        while (userChoiceCheck != true) {                       // While the user has not input a proper 'Y' or 'N'
            cout << "\n\tWould you like to go again? Y or N: ";
            cin >> userChoice;
            if ((userChoice != 'Y') && (userChoice != 'N')) {   // Catches improper inputs
                setColor(31); // Red
                cout << "\n\t========================================\n";
                cout << "\tImproper input. Only 'Y' or 'N' allowed.\n";
                cout << "\t========================================\n";
                resetColor();
                continue;                                       // Continues the while loop
            }
            else if (userChoice == 'N') {                       // User chooses to stop playing craps
                setColor(97); // Bright White
                cout << "\n\t====================\n";
                cout << "\tTerminating Hangman!\n";
                cout << "\t====================\n";
                resetColor();
                userChoiceCheck = true;
            }
            else {                                              // User chooses to run another game of craps
                setColor(97); // Bright White
                cout << "\n\t==================================\n";
                cout << "\tRunning another game of Hangman...\n";
                cout << "\t==================================\n";
                resetColor();
                userChoiceCheck = true;
            }
        }
    }

    return 0;
}