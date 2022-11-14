#ifndef CARD_H
#define CARD_H

enum class Suit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum class Rank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

struct Card
{
  Suit suit{};
  Rank rank{};

  //constructor
  Card(){};

  void printCard() const;

  int getCardValue() const;
};

#endif // !CARD_H
