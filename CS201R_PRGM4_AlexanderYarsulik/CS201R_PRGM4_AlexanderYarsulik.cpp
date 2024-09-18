// NAME: Alexander Yarsulik
// DATE: 09/17/2024
// PROGRAM: Program 4 - Games
//
// List of websites I used:
// https://www.geeksforgeeks.org/how-to-change-console-color-in-cpp/ (For changing the color of console text)
// ChatGPT (Free version)

#include "Games.h"
#include "Functions.h"

int main() {
    string userChoice;
    bool userContinue = true;
    int userMenuOptions[7] = { 'C', 'S', 'R', 'E', 'B', 'H', 'Q' };

    setColor(97); // Bright White
    cout << "Welcome to Your Games!\n";
    resetColor();

    while (userContinue == true) {

        Sleep(150);

        setColor(97);
        cout << "\n\t========================================================\n";
        cout << "\tWhat game would you like to play? (Choose between these)\n";
        cout << "\t========================================================\n\n";
        resetColor();

        Sleep(150);
        setColor(32); // Green              (CRAPS)
        cout << "\tC - Craps\n";
        Sleep(150);
        setColor(92); // Bright Green       (SCRAPS)
        cout << "\tS - Scraps\n";
        Sleep(150);
        setColor(31); // Red                (RPS)
        cout << "\tR - Rock, Paper, Scissors\n";
        Sleep(150);
        setColor(91); // Bright Red         (RPS-Spock)
        cout << "\tE - Rock, Paper, Scissors, Spock\n";
        Sleep(150);
        setColor(35); // Magenta            (BLACKJACK)
        cout << "\tB - Blackjack\n";
        Sleep(150);
        setColor(36); // Cyan               (HANGMAN)
        cout << "\tH - Hangman\n";
        Sleep(150);
        setColor(97); // Bright White       (QUIT)
        cout << "\tQ - Quit\n";
        Sleep(150);
        resetColor();

        cout << "\n\tInput choice: ";
        cin >> userChoice;
        cout << endl;
        Sleep(150);

        if (isMenuItem(userChoice)) {

            if (userChoice == "C") {      // If the user decides to play Craps (user input "C")
                craps();
            }
            else if (userChoice == "S") { // If the user decides to play Scraps (user input "S")
                scraps();
            }
            else if (userChoice == "R") { // If the user decides to play Rock, Paper, Scissors (user input "R")
                rockPaperScissors();
            }
            else if (userChoice == "E") { // If the user decides to play Rock, Paper, Scissors, Spock (user input "E")
                rockPaperScissorsSpock();
            }
            else if (userChoice == "B") { // If the user decides to play Blackjack (user input "B")
                blackjack();
            }
            else if (userChoice == "H") { // If the user decides to play Hangman (user input "H")
                hangman();
            }
            else {                        // If the user decides to quit (user input "Q")
                setColor(97); // Bright White
                cout << "\t=========================\n";
                cout << "\tTerminating Your Games...\n";
                cout << "\t=========================\n";
                resetColor();
                Sleep(500);
                return 0;
            }

        }
        else {                            // If the user improperly inputs the choice
            setColor(31); // Red
            cout << "\t===============\n";
            cout << "\tImproper input!\n";
            cout << "\t===============\n";
            resetColor();
            Sleep(500);
            continue;
        }

    }

}