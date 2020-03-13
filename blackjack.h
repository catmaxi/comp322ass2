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
  string toString() const;
};

class Hand
{
private:
  vector<Card> m_cards;

public:
  explicit Hand();

  void add(Card pCard);
  void clear();
  int getTotal() const;

  // Helper functions
  void display() const;
  string toString() const;
  int getNumberAces() const;
};

class Deck
{
private:
  vector<Card> m_cards;

public:
  Deck() : m_cards(){};

  void Populate();

  void shuffle();
  // This functions deals a card to the hand.
  void deal(Hand &hand);

  // helper methods
  void display() const;
};

class AbstractPlayer : public Hand
{
public:
  AbstractPlayer();

  virtual bool isDrawing() const = 0;

  bool isBusted() const;
};

class ComputerPlayer : public AbstractPlayer
{
public:
  bool isDrawing() const override;

  // helper function
  void displayPlayer() const;
};

class HumanPlayer : public AbstractPlayer
{
private:
  bool m_isBusted;

public:
  HumanPlayer();

  bool isDrawing() const override;

  // This function takes the computer player to check and announce if anyone won or if it's a push.
  void announce(const ComputerPlayer &casino);

  // helper function
  void displayPlayer();
};

class BlackJackGame
{
private:
  Deck m_deck;
  ComputerPlayer m_casino;

public:
  // This functions serves to play the game once and deals with all the logistics and loops of playing the game once.
  void play();
};

#endif //BLACKJACK_BLACKJACK_H
