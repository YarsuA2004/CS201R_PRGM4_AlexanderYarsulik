#pragma once
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

void setColor(int textColor);
void resetColor();

int rollDie();
int rollScrapsDie();
bool scrapsDieTotal();
void craps();
void scraps();
void rockPaperScissors();
void rockPaperScissorsSpock();

struct Card {
    int value;
    string suit;
};

void initializeDeck(vector<Card>& deck);
void shuffleDeck(vector<Card>& deck);
Card drawCard(vector<Card>& deck);
int calculateHandValue(const vector<Card>& hand);
void displayHand(const vector<Card>& hand, const string& playerName);
void displayCard(const Card& card);
int blackjack();

void displayWord(const string& word, const vector<bool>& guessed);
bool allGuessed(const vector<bool>& guessed);
string selectRandomWord(const vector<string>& words);
int hangman();