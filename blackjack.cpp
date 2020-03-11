//
// Created by wenxu on 3/10/2020.
//

#include "blackjack.h"

#include <iostream>

using namespace std;

enum Rank
{
  ACE = 1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING
};

enum Type
{
  CLUBS,
  DIAMONDS,
  HEARTS,
  SPADES
};

class Card
{
private:
  Rank rank;
  Type type;

public:
  int getValue()
  {
    return this->rank;
  }
  void displayCard()
  {
    cout << getValue() << endl;
  }
};

class Hand
{
};

class Deck
{
};

class AbstractPlayer
{
};

class Player
{
};
class Computer
{
};

class BlackJackGame
{
};
