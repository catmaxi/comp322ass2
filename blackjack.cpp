//
// Created by wenxu on 3/10/2020.
//

#include "blackjack.h"

#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <string>
#include <utility>

using namespace std;

Card::Card(Rank pRank, Type pType)
{
  this->m_rank = pRank;
  this->m_type = pType;
}

int Card::getValue() const
{
  return this->m_rank;
}

void Card::displayCard() const
{
  string R;
  int rInt = this->getValue();
  if (rInt <= 10)
  {
    R = to_string(rInt);
  }
  else
  {
    switch (rInt)
    {
    case 11:
      R = "J";
      break;
    case 12:
      R = "Q";
      break;
    case 13:
      R = "K";
      break;
    }
  }

  char T = 0;
  switch (this->m_type)
  {
  case CLUBS:
    T = 'C';
    break;
  case DIAMONDS:
    T = 'D';
    break;
  case HEARTS:
    T = 'H';
    break;
  case SPADES:
    T = 'S';
    break;
  }

  cout << R << T << endl;
}

string Card::toString() const
{
  string R;
  int rInt = this->getValue();
  if (rInt <= 10)
  {
    R = to_string(rInt);
  }
  else
  {
    switch (rInt)
    {
    case 11:
      R = "J";
      break;
    case 12:
      R = "Q";
      break;
    case 13:
      R = "K";
      break;
    }
  }

  char T = 0;
  switch (this->m_type)
  {
  case CLUBS:
    T = 'C';
    break;
  case DIAMONDS:
    T = 'D';
    break;
  case HEARTS:
    T = 'H';
    break;
  case SPADES:
    T = 'S';
    break;
  }

  return R + T;
}

Hand::Hand() : m_cards()
{
}

//Hand::Hand(): cards() {};
void Hand::add(Card pCard)
{
  m_cards.push_back(pCard);
}

void Hand::clear()
{
  m_cards.clear();
}

int Hand::getTotal() const
{
  int sum = 0;
  for (auto e : this->m_cards)
  {
    sum += e.getValue();
  }
  return sum;
}

void Hand::display() const
{
  string str = "hand: {";
  for (auto c : this->m_cards)
  {
    str += c.toString() + ",";
  }
  str += "}";
  cout << str << endl;
}

string Hand::toString() const
{
  string str;
  for (auto &e : m_cards)
  {
    str += e.toString();
    str += " ";
  }
  return str;
}

void Deck::Populate()
{
  for (int rankInt = ACE; rankInt != KING + 1; rankInt++)
  {
    Rank rank_i = static_cast<Rank>(rankInt);
    for (int typeInt = CLUBS; typeInt != SPADES + 1; typeInt++)
    {
      Type type_i = static_cast<Type>(typeInt);
      this->m_cards.emplace_back(rank_i, type_i);
      // I'm not sure if I should use push_back instead
    }
  }
}

void Deck::shuffle()
{
  srand(time(0));
  ::shuffle(m_cards.begin(), m_cards.end(), std::mt19937(std::random_device()()));
}

void Deck::deal(Hand &hand)
{
  int n = m_cards.size();
  Card myCard = m_cards[n - 1];
  m_cards.erase(m_cards.end() - 1);
  hand.add(myCard);
}

void Deck::display() const
{
  string str = "Deck: {";
  for (auto c : m_cards)
  {
    str += c.toString() + ",";
  }
  str += "}";
  cout << str << endl;
}

bool AbstractPlayer::isBusted() const
{
  return false;
}

AbstractPlayer::AbstractPlayer() {}

bool HumanPlayer::isDrawing() const
{
  return m_isDrawing;
}

void HumanPlayer::announce()
{
}

HumanPlayer::HumanPlayer() : m_isDrawing(false) {}

void HumanPlayer::displayPlayer()
{
  string str = "Player: ";
  str += this->toString();
  str += "[" + to_string(this->getTotal()) + "]";
  cout << str << endl;
}

bool ComputerPlayer::isDrawing() const
{
  return false;
}

void ComputerPlayer::displayPlayer() const
{
  string str = "Casino: ";
  str += this->toString();
  str += "[" + to_string(this->getTotal()) + "]";
  cout << str << endl;
}

void BlackJackGame::play()
{
  cout << "The game is starting..." << endl;

  Deck deck;
  deck.Populate();
  deck.shuffle();

  ComputerPlayer CP;
  deck.deal(CP);
  CP.displayPlayer();

  HumanPlayer player;
  deck.deal(player);
  deck.deal(player);

  player.displayPlayer();
}
