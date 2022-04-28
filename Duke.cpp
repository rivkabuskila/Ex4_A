//
// Created by rivka on 25/04/2022.
//

#include "Duke.hpp"
namespace coup {

    Duke::Duke(const coup::Game &game, const string &name): Player::Player(game,name){}

    void Duke::block(Player &p) {}

    void Duke::tax() {}
}