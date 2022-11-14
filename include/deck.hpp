#ifndef DECK_H
#define DECK_H

#include "card.hpp"
#include "constants.hpp"

#include <array>

using Deck = std::array<Card, g_totalCard>;
using IndexDeck = Deck::size_type;

Deck createDeck();

void printDeck(const Deck& cardDeck);

Deck shuffleDeck(Deck& cardDeck);

#endif // !DECK_H
