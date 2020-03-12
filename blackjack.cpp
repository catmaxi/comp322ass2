//
// Created by wenxu on 3/10/2020.
//

#include "blackjack.h"

#include <iostream>
#include <ctime>

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
  char C = 0;
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

void Hand::add(Card pCard)
{
  m_cards.push_back(pCard);
}

void Hand::clear()
{
  m_cards.clear();
}

int Hand::getTotal()
{
  int sum = 0;
  for (auto e : this->m_cards)
  {
    sum += e.getValue();
  }
  return sum;
}

void Deck::Populate()
{
  for (int rankInt = ACE; rankInt != KING; rankInt++)
  {
    Rank rank_i = static_cast<Rank>(rankInt);
    for (int typeInt = CLUBS; typeInt != SPADES; typeInt++)
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
}

void Deck::deal(Hand &hand)
{
  int n = m_cards.size();
  Card myCard = m_cards[n - 1];
  m_cards.erase(m_cards.end());
  hand.add(myCard);
}

bool AbstractPlayer::isBusted() const
{
  return false;
}

bool HumanPlayer::isDrawing() const
{
  return false;
}

void HumanPlayer::announce()
{
}

bool ComputerPlayer::isDrawing() const
{
  return false;
}

void BlackJackGame::play()
{
}
