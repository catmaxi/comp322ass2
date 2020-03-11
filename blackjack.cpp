//
// Created by wenxu on 3/10/2020.
//

#include "blackjack.h"

#include <iostream>
#include <ctime>
//#include <vector>

using namespace std;

//namespace myRank {
//    enum Rank {
//        ACE = 1,
//        TWO,
//        THREE,
//        FOUR,
//        FIVE,
//        SIX,
//        SEVEN,
//        EIGHT,
//        NINE,
//        TEN,
//        JACK,
//        QUEEN,
//        KING
//    };
////}
//enum Type {
//    CLUBS,
//    DIAMONDS,
//    HEARTS,
//    SPADES
//};

class Card
{
  // deck as friend class or not?????

private:
  Rank m_rank;
  Type m_type;

public:
  Card(Rank pRank, Type pType)
  {
    this->m_rank = pRank;
    this->m_type = pType;
  }

  int getValue() const
  {
    return this->m_rank;
  }

  void displayCard() const
  {
    char C;
    switch (this->m_type)
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
  vector<Card> m_cards;

public:
  Hand() : m_cards(){};

  void add(Card pCard)
  {
    m_cards.push_back(pCard);
    // not copied before added...
  }

  void clear()
  {
    m_cards.clear();
  }

  int getTotal()
  {
    int sum = 0;
    for (auto e : this->m_cards)
    {
      sum += e.getValue();
    }
    return sum;
  }

  // void display() const; ????
};

class Deck
{
private:
  vector<Card> m_cards;

public:
  Deck() : m_cards(){};

  void Populate()
  {
    for (int rankInt = ACE; rankInt != KING; rankInt++)
    {
      Rank rank_i = static_cast<Rank>(rankInt);
      for (int typeInt = CLUBS; typeInt != SPADES; typeInt++)
      {
        Type type_i = static_cast<Type>(typeInt);
        m_cards.push_back(Card(rank_i, type_i));
      }
    }
  }

  void shuffle()
  {
    srand(time(0));
    
  }

  void deal(Hand &hand)
  {
  }
};

class AbstractPlayer : public Hand
{
public:
  virtual bool isDrawing() const = 0;

  bool isBusted() const
  {
  }
};

class HumanPlayer : public AbstractPlayer
{
private:
  bool m_isDrawing;

public:
  virtual bool isDrawing() const override
  {
    return false;
  }

  void announce()
  {
  }
};

class ComputerPlayer : public AbstractPlayer
{
private:
public:
  virtual bool isDrawing() const override
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
  void play()
  {
  }
};
