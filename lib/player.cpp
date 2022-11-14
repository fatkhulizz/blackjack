#include "constants.hpp"
#include "player.hpp"

#include <iostream>

int Player::getTotalValue() const
{
  int totalValue{};
  int temp{};
  for(auto &eachCard: hand)
  {
    temp = eachCard.getCardValue();
    totalValue += temp;
  }
  return totalValue;
}

void Player::printEachCard() const
{
  for(auto &eachCard : hand)
  {
    eachCard.printCard(); std::cout << ' ';
  }
}

void Player::printPlayerInfo() const
{
  std::cout << "kartu " << name << " adalah: ";
  printEachCard();
  std::cout << "\nTotal skor " << name << " adalah : " << score << std::endl;
  // std::cout << "-----------------------\n";
}

const std::string Player::askName() const
{
  std::cout << "masukkan nama anda: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  std::cout << "=======================\n";
  return name;
}
