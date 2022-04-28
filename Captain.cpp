//
// Created by rivka on 25/04/2022.
//

#include "Captain.hpp"
namespace coup {

    Captain::Captain(const coup::Game &game, const string &name): Player::Player(game,name){}

    void Captain::steal(Player &p) {}

    void Captain::block(Player &p) {}
}