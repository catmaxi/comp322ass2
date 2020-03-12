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
    int value = e.getValue();
    if (value == 1)
    {
      sum += 11;
    }
    else
    {
      sum += value;
    }
  }
  int num = this->getNumberAces();
  if (sum > 21)
  {
    sum -= num * 10;
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

int Hand::getNumberAces() const
{
  int num = 0;
  for (auto const &c : m_cards)
  {
    if (c.getValue() == 1)
    {
      num++;
    }
  }
  return num;
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
  return this->getTotal() > 21;
}

AbstractPlayer::AbstractPlayer() {}

bool HumanPlayer::isDrawing() const
{
  cout << "Do you want to draw? (y/n):";
  char answer;
  cin >> answer;
  bool drawAgain = (answer == 'y');
  //    m_isDrawing = drawAgain;
  return drawAgain;
}

void HumanPlayer::announce(const ComputerPlayer &casino)
{
  if (this->isBusted())
  {
    cout << "Player busts." << endl;
    cout << "Casino wins." << endl;
  }
  else if (casino.isBusted())
  {
    cout << "Casino busts." << endl;
    cout << "Player wins." << endl;
  }
  else if (this->getTotal() == casino.getTotal())
  {
    cout << "Push: No one wins." << endl;
  }
  else if (this->getTotal() > casino.getTotal())
  {
    cout << "Player wins." << endl;
  }
  else if (this->getTotal() < casino.getTotal())
  {
    cout << "Casino wins." << endl;
  }
}

HumanPlayer::HumanPlayer() : m_isBusted(false) {}

void HumanPlayer::displayPlayer()
{
  string str = "Player: ";
  str += this->toString();
  str += "[" + to_string(this->getTotal()) + "]";
  cout << str << endl;
}

bool ComputerPlayer::isDrawing() const
{
  return this->getTotal() <= 16;
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
  //    cout << "The game is starting..." << endl;

  Deck deck;
  deck.Populate();
  deck.shuffle();

  ComputerPlayer casino;
  deck.deal(casino);
  casino.displayPlayer();

  HumanPlayer player;
  deck.deal(player);
  deck.deal(player);
  player.displayPlayer();

  bool playEnded = false;
  while (player.isDrawing())
  {
    deck.deal(player);
    player.displayPlayer();

    if (player.isBusted())
      break;
  }

  if (player.isBusted())
  {
    player.announce(casino);
  }
  else
  {
    while (casino.isDrawing())
    {
      deck.deal(casino);
      casino.displayPlayer();
      if (casino.isBusted())
      {
        break;
      }
    }

    player.announce(casino);
  }
}
