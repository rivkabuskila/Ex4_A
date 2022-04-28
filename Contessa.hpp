//
// Created by rivka on 25/04/2022.
//

#ifndef COUP_A_CONTESSA_H
#define COUP_A_CONTESSA_H
#include "Player.hpp"
#include <string>
#include "Game.hpp"
using namespace std;
namespace coup {
    class Contessa : public Player {
    public:
        Contessa(const coup::Game &game, const string &name);

        void block(Player &p);

    };
}

#endif //COUP_A_CONTESSA_H
