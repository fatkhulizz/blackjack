#include "blackjack.hpp"

#include <iostream>
#include <array>
#include <vector>

bool askToHit()
{
  char i{};
  do
  {
    std::cout << "=======================\n";
    std::cout << "(h)it or (s)tand? .. "; 
    std::cin >> i;
    std::cout << "=======================\n";
  } while(i != 'h' && i != 'H' && i != 's' && i != 'S');
  switch (i) 
  {
    case 'h':
    case 'H':
    return true;
    case 's':
    case 'S':
    return false;
    default: return false;
  }
}

void firstDeal(std::vector<Player>& allPlayer, const Deck& cardDeck)
{
  for(auto &var : allPlayer)
  {
    int firstCard{0};
    var.hand.resize(2);
    var.hand = {cardDeck[firstCard], cardDeck[1+firstCard+static_cast<int>(allPlayer.size())]};
    ++firstCard;
  }
}

bool playerTurn(std::vector<Player>& allPlayer,const Deck& cardDeck, IndexDeck& indexDeck, Player& dealer) //return true if player busted (> g_maxScore)
{
  int index{0};
  while(true)
  {
    if (askToHit()) 
    {
      allPlayer[index].hand.push_back(cardDeck[indexDeck]);
      allPlayer[index].score = allPlayer[index].getTotalValue();
      indexDeck++; 
      if(allPlayer[index].score > g_maxScore) 
      { 
        allPlayer[index].printPlayerInfo();
        std::cout << "-----------------------\n";
        dealer.printPlayerInfo();
        return true; 
      }
    }
    else {return false;}

    allPlayer[index].printPlayerInfo();
    std::cout << "-----------------------\n";
    dealer.printPlayerInfo();
  }
  return false;
}

bool dealerTurn(Player& dealer, const Deck& cardDeck, IndexDeck& indexDeck, std::vector<Player>& allPlayer)
{
  std::cout << "\n+++++++++++++++\n";
  std::cout << "DEALER TURN";
  std::cout << "\n+++++++++++++++\n\n=======================\n";
  while(dealer.score < g_minDealerScore)
  {
    dealer.hand.push_back(cardDeck[indexDeck]);
    dealer.score = dealer.getTotalValue();
    indexDeck++;
    if(dealer.score > g_maxScore)
    {
      allPlayer[0].printPlayerInfo(); //could be set to loop to show other player
      std::cout << "-----------------------\n";
      dealer.printPlayerInfo();
      std::cout << "=======================\n";
      return true;
    }
    allPlayer[0].printPlayerInfo(); //could be set to loop to show other player
    std::cout << "-----------------------\n";
    dealer.printPlayerInfo();
    std::cout << "=======================\n";
  }
  return false;
}

bool playBlackjack(const Deck& cardDeck)
{
  //initialize the player
  //could be change to loop to add more player, but now it set 1 player only
  int totalPlayer{1}; 
  std::vector<Player> allPlayer(totalPlayer);
  allPlayer[0].name = allPlayer[0].askName();
  allPlayer[0].hand = {}; 
  allPlayer[0].score ={};  

  //initialize the dealer
  Player dealer;
  dealer.name = "dealer";
  dealer.hand = {cardDeck[1]};
  dealer.score = dealer.getTotalValue();

  //draw 2 card to each player, and update player1 score after first deal 
  //could be change to loop
  firstDeal(allPlayer, cardDeck);
  allPlayer[0].score = allPlayer[0].getTotalValue();
  //print player1 and dealer info
  allPlayer[0].printPlayerInfo();
  std::cout << "-----------------------\n";
  dealer.printPlayerInfo(); //firstly print dealer info

  //player turn to draw new card from deck
  IndexDeck indexDeck{3}; //used as track index of card after first draw (2 for player, 1 for dealer)
  if(playerTurn(allPlayer, cardDeck, indexDeck, dealer)) return false;
  if(dealerTurn(dealer, cardDeck, indexDeck, allPlayer)) return true;

  return (allPlayer[0].score > dealer.score);
}

