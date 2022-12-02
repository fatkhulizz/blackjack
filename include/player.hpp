#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "deck.hpp"

using Hand = std::vector<Card>;

class Player{
public:
  enum State{
    firstDraw,
    secondDraw,
    blackjack,
    busted,
    normal,
  };
  enum Result{
    playing,
    win,
    lose,
  };
private:
  std::string m_name{};
  Hand m_hand{};
  int m_score{};
  State m_state{};

public:
 //CONSTRUCTOR
  Player(); 
  Player(std::string name);
 //END CONSTRUCTOR
  void drawCard(Deck& deck); //mutate m_hand by adding new card from deck
  State getState();
  void printInfo () const; //display all variable member in console
  Result turn(Deck& deck); //do player turn
  // Result dealerTurn(Deck& deck); //do dealer turn

private:
  void score(); //mutate score
  void state(); //check state of player
  void evaluate(); //evalaute score and state
  bool isDealer() const;
  bool askToHit(); //ask decision
  bool dealerHit();
  void printHand() const; //display card in hand in console

};

#endif // !PLAYER_HPP
