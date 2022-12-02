# Blackjack

## Synopsis

Simple command line based blackjack game.

For now, its only can be played with 1 player only (player vs dealer), and score for ACE card is fixed to 11 (in blackjack it could be 1 or 11)

## What I learn

- class
- struct
- dynamic size array (std::vector)
- working with multiple files
- makefile

## Installation

Compile all `cpp` file in `./lib` directory and include all header file in `./include` directory using your favorite C++ compiler, then execute the program on the command line

Example using gcc

```
  g++ -I ./include/ ./lib/*.cpp -o blackjack
```

or better run `make`

## Example
![blackjackExample](https://github.com/fatkhulizz/blackjack/raw/main/asset/blackjack_example.png)
