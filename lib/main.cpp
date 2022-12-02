#include "blackjack.hpp"

int main() {
  Deck deck{};

  deck.shuffle();
  deck.print();

  playBlackjack(deck);

  return 0;
}
