#include "player.hpp"
#include "constants.hpp"
#include <iostream>

//CONSTRUCTOR for player
Player::Player() : m_state{Player::firstDraw}{
  // drawCard(deck);
  std::string name{"player"};
  static int s_indexPlayer{49};//49 is '1' in ascii
  name.push_back(s_indexPlayer); //add number after string "player"
  m_name = name;
  ++s_indexPlayer;
}
//CONSTRUCTOR for dealer
Player::Player(std::string name) : m_name{name}, m_state{Player::firstDraw}{}

//============= variable member MUTATOR =================

void Player::drawCard(Deck& deck){ //add one card from deck to player hand
  Card nextCard{deck.dealCard()};
  m_hand.push_back(nextCard);
}

void Player::score(){
  m_score = 0;
  for (auto& card : m_hand) {
    m_score += card.value();
  }
}

void Player::state(){
  if (m_score > g_maxScore) m_state = Player::busted;
  else if (m_score == g_maxScore) m_state = Player::blackjack;
  else m_state = Player::normal;
}

void Player::evaluate(){
  score();
  state();
}

//============= variable member DISPLAY =================

void Player::printHand() const{
  if(isDealer() && m_state == State::secondDraw){m_hand[0].print(); std::cout << ' ';}
  else{
    for(auto &card : m_hand){
      card.print(); std::cout << ' ';
    }
  }
}

void Player::printInfo() const{
  std::cout << "\nkartu " << m_name << " adalah: ";
  printHand(); std::cout << " = " << m_score << "\n";
  
  if (m_state == State::blackjack) {
    std::cout << m_name << " BLACKJACK!\n";
  } else if (m_state == State::busted) {
    std::cout << m_name << " BUSTED!\n";
  }
}

//============= variable member GETTER =================

bool Player::isDealer() const{
  return(m_name == "dealer");
}

Player::State Player::getState(){
  return m_state;
}

//============= class INTERFACE =================

bool Player::askToHit() {
  char i{};
  do {
    // std::cout << '\n';
    printInfo();
    std::cout << m_name << ", (h)it or (s)tand? .. ";
    std::cin >> i;
  } while (i != 'h' && i != 'H' && i != 's' && i != 'S');
  switch (i) {
  case 'h':
  case 'H':
    return true;
  case 's':
  case 'S':
    return false;
  default:
    return true;
  }
}

bool Player::dealerHit() {
  printInfo();
  if(m_score < 17)
    return true;
  else return false;
}

Player::Result Player::turn(Deck& deck) {
  while(true){
    switch (m_state) {
      case State::blackjack: 
        evaluate();
        printInfo();
        return Result::win; 
      case State::busted: 
        evaluate();
        printInfo();
        return Result::lose; 

      case State::firstDraw:
        drawCard(deck);
        m_state = State::secondDraw;
        return Result::playing;
      case State::secondDraw:
        drawCard(deck);
        // isDealer() ? state() : evaluate();
        if(!isDealer()){evaluate();}
        printInfo();
        if(isDealer()){state();}
        return Result::playing;
      case State::normal:
        if(isDealer()){
          // std::cout << '\n';
          if(m_hand.size() == 2){
            evaluate();
            printInfo();
            // std::cout << '\n';
          }
          if(dealerHit()){ //ask if player want to hit or stand
            drawCard(deck);
            evaluate();
            // return Result::playing; 
          } 
          else {
            return Result::playing; 
          }
        } 
        else{
          if(askToHit()){ //ask if player want to hit or stand
              drawCard(deck);
              evaluate();
          } else return Result::playing; // player not ask to hit
        }
    }
  }
}

