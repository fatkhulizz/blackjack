#include <iostream>
#include <vector>
#include "blackjack.hpp"

using Players = std::vector<Player>;
using IndexPlayers = Players::size_type;

int askTotalPlayer() {
  int totalPlayer{};
  do {
    std::cout << "berapa pemain? (1-6).. ";
    std::cin >> totalPlayer;
  } while (totalPlayer < 1 || totalPlayer > 6);
  return totalPlayer;
}

void playBlackjack(Deck &deck) {
  Players players(askTotalPlayer());
  Player dealer{"dealer"};

  players.push_back(dealer);

  using PState = Player::State;
  for (int i{0}; i < 3; ++i) {
    for(auto &player : players)
    {
      if(player.getState() != PState::busted && player.getState() !=  PState::blackjack){
        player.turn(deck);
      }
    }
    // dealer.turn(deck);
  }
}
