#include "blackjack.hpp"

#include <iostream>

int main()
{
  auto cardDeck {createDeck()};

  shuffleDeck(cardDeck);
  // printDeck(cardDeck);
  std::cout << '\n';

  switch (playBlackjack(cardDeck)) {
    case BlacjackResult::player_win:
      std::cout << "\n--------------" << std::endl;
      std::cout << "player MENANG" << std::endl;
      std::cout << "--------------\n" << std::endl;
      break;
    case BlacjackResult::player_lose:
      std::cout << "\n--------------" << std::endl;
      std::cout << "player KALAH" << std::endl;
      std::cout << "--------------\n" << std::endl;
      break;
    case BlacjackResult::tie:
      std::cout << "\n--------------" << std::endl;
      std::cout << "IMBANG" << std::endl;
      std::cout << "--------------\n" << std::endl;
      break;
    default:
      break;
  }

  // if (playBlackjack(cardDeck)) {
  //   std::cout << "\n--------------" << std::endl;
  //   std::cout << "player MENANG" << std::endl;
  //   std::cout << "--------------\n" << std::endl;
  // }
  // else {
  //   std::cout << "\n--------------" << std::endl;
  //   std::cout << "Player KALAH" << std::endl;
  //   std::cout << "--------------\n" << std::endl;
  // }

  return 0;
}
