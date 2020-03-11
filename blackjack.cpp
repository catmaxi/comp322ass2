//
// Created by wenxu on 3/10/2020.
//

#include "blackjack.h"

#include <iostream>
#include <vector>

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
  Card()
  {
  }

  int getValue()
  {
    return this->rank;
  }

  void displayCard()
  {
    char C;
    switch (this->type)
    {
    case CLUBS:
      C = 'C';
      break;
    case DIAMONDS:
      C = 'D';
      break;
    case HEARTS:
      C = 'H';
      break;
    case SPADES:
      C = 'S';
      break;
    }

    cout << getValue() << C << endl;
  }
};

class Hand
{
private:
  vector<int> cards;

public:
  Hand()
  {
  }
  void add()
  {
  }
  void clear()
  {
  }
  int getTotal()
  {
  }
};

class Deck
{
private:
  vector<int> cards;

public:
  Deck()
  {
  }
  void Populate()
  {
  }
  void shuffle()
  {
  }
  void deal()
  {
  }
};

class AbstractPlayer
{
public:
  virtual bool isDrawing() const = 0;
  bool isBusted()
  {
  }
};

class HumanPlayer : public AbstractPlayer
{
private:
public:
  virtual bool isDrawing()
  {
  }
  void announce()
  {
  }
};

class ComputerPlayer : public AbstractPlayer
{
private:
public:
  virtual bool isDrawing()
  {
    return false;
  }
};

class BlackJackGame
{
private:
  Deck m_deck;
  ComputerPlayer m_casino;

public:
};
