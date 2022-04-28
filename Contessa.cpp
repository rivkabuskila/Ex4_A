//
// Created by rivka on 25/04/2022.
//

#include "Contessa.hpp"
namespace coup {

    Contessa::Contessa(const coup::Game &game, const string &name): Player::Player(game,name){}

    void Contessa::block(Player &p) {}

}