#ifndef PLAYER_H
#define PLAYER_H

#include "card.hpp"

#include <string>
#include <vector>

using Hand = std::vector<Card>;
using IndexHand = Hand::size_type;

struct Player
{
  std::string name{};
  Hand hand{};
  int score{};

  //constructor
  Player(){};

  int getTotalValue() const;
  void printEachCard() const;
  void printPlayerInfo() const;
  const std::string askName() const;
};

#endif // !PLAYER_H
