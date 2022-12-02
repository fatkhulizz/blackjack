#ifndef DECK_HPP
#define DECK_HPP

#include "constants.hpp"
#include <array>
#include "card.hpp"

using DeckArray = std::array<Card, g_totalCard>;
using IndexDeck = DeckArray::size_type;

class Deck{
private:
  DeckArray m_deck{};
  IndexDeck m_cardIndex{0};

public:
  //START of FORWARD DECLARING CONSTRUCTOR
  Deck();
  //END of FORWARD DECLARING CONSTRUCTOR

  void print() const;
  DeckArray shuffle();
  const Card& dealCard();


};

#endif // !DECK_HPP
