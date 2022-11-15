#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.hpp"
#include "player.hpp"

enum class BlacjackResult
{
  player_win,
  player_lose,
  tie,
};

bool askToHit();

void firstDeal(std::vector<Player>& allPlayer, const Deck& cardDeck);

bool playerTurn(std::vector<Player>& allPlayer,const Deck& cardDeck, IndexDeck& indexDeck, Player& dealer); 

bool dealerTurn(Player& dealer, const Deck& cardDeck, IndexDeck& indexDeck, std::vector<Player>& allPlayer);

BlacjackResult playBlackjack(const Deck& cardDeck);

#endif // !BLACKJACK_H
