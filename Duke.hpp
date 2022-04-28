//
// Created by rivka on 25/04/2022.
//

#ifndef COUP_A_DUKE_H
#define COUP_A_DUKE_H
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
namespace coup {
    class Duke : public Player {
    public:
        Duke(const coup::Game &game, const string &name);

        void block(Player &p);

        void tax();
    };
}

#endif //COUP_A_DUKE_H
