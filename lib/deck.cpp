#include "deck.hpp"

#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937
#include <iostream>

Deck createDeck()
{
  //declare Deck array
  Deck cardDeck{};

  //filling Deck array with all card
  int index{0};
  for(int iii{0}; iii < static_cast<int>(Suit::max_suits); ++iii)
    {
      for(int jjj{0}; jjj < static_cast<int>(Rank::max_ranks); ++jjj)
        {
          // std::cout << '#' << index << ' ' << "rank = " << jjj << " suit = " << iii << std::endl;
          cardDeck.at(index).suit = static_cast<Suit>(iii);
          cardDeck.at(index).rank = static_cast<Rank>(jjj);
          ++index;
        }
    }
  return cardDeck;
}

void printDeck(const Deck& cardDeck)
{
  for(const auto& var : cardDeck)
  {
    var.printCard();
    std::cout << ' ';
  }
  std::cout << '\n';
}

Deck shuffleDeck(Deck& cardDeck)
{
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
 
  std::shuffle(cardDeck.begin(), cardDeck.end(), mt);
  return cardDeck;
}
