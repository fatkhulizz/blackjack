#include "deck.hpp"
#include <algorithm> // for std::shuffle
#include <cassert>
#include <ctime> // for std::time
#include <iostream>
#include <random> // for std::mt19937

// START of FORWARD DECLARING CONSTRUCTOR
Deck::Deck() {
  int index{0};

  for (int rank{0}; rank < static_cast<int>(Card::Rank::max_ranks); ++rank) {
    for (int suit{0}; suit < static_cast<int>(Card::Suit::max_suits); ++suit) {
      m_deck[index] = {static_cast<Card::Rank>(rank),
                       static_cast<Card::Suit>(suit)};
      ++index;
    }
  }
}
// END of FORWARD DECLARING CONSTRUCTOR

void Deck::print() const {
  for (const auto &var : m_deck) {
    var.print();
    std::cout << ' ';
  }
  std::cout << '\n';
}

DeckArray Deck::shuffle() {
  static std::mt19937 mt{
      static_cast<std::mt19937::result_type>(std::time(nullptr))};

  std::shuffle(m_deck.begin(), m_deck.end(), mt);
  //RESET card index
  m_cardIndex = 0;
  return m_deck;
}

const Card& Deck::dealCard() {
  assert(m_cardIndex < m_deck.size());

  return m_deck[m_cardIndex++];
}
