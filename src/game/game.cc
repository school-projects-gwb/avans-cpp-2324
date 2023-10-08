#include <string>
#include <iostream>
#include "game.h"

Game::Game() : scanner_() {

}

void Game::HandleInput(char input) {
  std::cout << input;
}
