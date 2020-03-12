#include <iostream>
#include "blackjack.h"

using namespace std;

int main()
{
  //    cout << "\tWelcome to the Comp322 Blackjack game!" << endl
  //         << endl;
  //
  //    BlackJackGame game;
  //    // The main loop of the game
  //    bool playAgain = true;
  //    char answer = 'y';
  //    while (playAgain)
  //    {
  //        game.play();
  //        // Check whether the player would like to play another round
  //        cout << "Would you like another round? (y/n): ";
  //        cin >> answer;
  //        cout << endl
  //             << endl;
  //        playAgain = (answer == 'y' ? true : false);
  //    }
  //    cout << "Gave over!";
  //    return 0;

  Card card1(TEN, CLUBS);
  Card card2(QUEEN, DIAMONDS);
  Card card3(ACE, HEARTS);
  cout << card1.getValue() << endl;
  card1.displayCard();
  Hand hand;
  hand.add(card1);
  hand.add(card2);
  hand.add(card3);
  //    hand.add(card3);
  hand.display();
  cout << hand.getTotal() << endl;
  hand.clear();
  hand.display();

  Deck deck;
  deck.Populate();
  deck.display();

  cout << "Shuffling the cards..." << endl;
  deck.shuffle();
  deck.display();
  cout << "Shuffle finished." << endl;

  deck.deal(hand);
  hand.display();

  deck.display();

  HumanPlayer humanPlayer;
  humanPlayer.display();
  cout << humanPlayer.isDrawing() << endl;

  return 0;
}
