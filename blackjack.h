//
// Created by wenxu on 3/10/2020.
//

#ifndef BLACKJACK_BLACKJACK_H
#define BLACKJACK_BLACKJACK_H

#include <vector>
#include <string>
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
  // deck as friend class or not?????
private:
  Rank m_rank;
  Type m_type;

public:
  Card(Rank pRank, Type pType);
  int getValue() const;

  void displayCard() const;

  // Helper methods
  string toString();
};

class Hand
{
private:
  vector<Card> m_cards;

public:
  explicit Hand();
  //    Hand(vector<Card> mCards);

  void add(Card pCard);
  void clear();
  int getTotal();
  void display() const;
};

class Deck
{
private:
  vector<Card> m_cards;

public:
  Deck() : m_cards(){};

  void Populate();

  void shuffle();

  void deal(Hand &hand);

  void display() const;
};

class AbstractPlayer : public Hand
{
public:
  AbstractPlayer();

  virtual bool isDrawing() const = 0;

  bool isBusted() const;
};

class HumanPlayer : public AbstractPlayer
{
private:
  bool m_isDrawing;

public:
  HumanPlayer();

  bool isDrawing() const override;

  void announce();
};

//class ComputerPlayer : public AbstractPlayer {
//private:
//public:
//    virtual bool isDrawing() const override;
//};
//
//class BlackJackGame {
//private:
//    Deck m_deck;
//    ComputerPlayer m_casino;
//public:
//    void play();
//};

#endif //BLACKJACK_BLACKJACK_H
