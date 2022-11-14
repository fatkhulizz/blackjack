#include "blackjack.hpp"

#include <iostream>

int main()
{
  auto cardDeck {createDeck()};

  shuffleDeck(cardDeck);
  // printDeck(cardDeck);
  std::cout << '\n';

  if (playBlackjack(cardDeck)) {
    std::cout << "\n--------------" << std::endl;
    std::cout << "player MENANG" << std::endl;
    std::cout << "--------------\n" << std::endl;
  }
  else {
    std::cout << "\n--------------" << std::endl;
    std::cout << "Player KALAH" << std::endl;
    std::cout << "--------------\n" << std::endl;
  }

  return 0;
}
