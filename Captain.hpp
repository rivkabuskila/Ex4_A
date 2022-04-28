//
// Created by rivka on 25/04/2022.
//

#ifndef COUP_A_CAPTAIN_H
#define COUP_A_CAPTAIN_H
#include "Player.hpp"
#include <string>
#include "Game.hpp"
using namespace std;
namespace coup {

    class Captain : public Player {
    public:
        Captain(const coup::Game &game, const string &name);

        void steal(Player &p);

        void block(Player &p);
    };

}
#endif //COUP_A_CAPTAIN_H
