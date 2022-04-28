//
// Created by rivka on 25/04/2022.
//

#include "Ambassador.hpp"
namespace coup {
    Ambassador::Ambassador(const coup::Game &game, const string &name): Player::Player(game,name){}

    void Ambassador::transfer(Player &p1, Player &p2) {}

    void Ambassador::block(Player &p1) {}
}