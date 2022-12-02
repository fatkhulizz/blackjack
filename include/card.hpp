#ifndef CARD_HPP
#define CARD_HPP

class Card{
public:
  enum Suit
  {
      club,
      diamond,
      heart,
      spade,

      max_suits
  };

  enum Rank
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
private:
  Rank m_rank{};
  Suit m_suit{};
public:
  //START of FORWARD DECLARING CONSTRUCTOR
  Card();
  Card(Rank rank, Suit suit);
  //END of FORWARD DECLARING CONSTRUCTOR
  void print() const;
  int value() const;
};

#endif // !CARD_HPP
