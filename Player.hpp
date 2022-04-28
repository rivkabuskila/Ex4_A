//
// Created by rivka on 25/04/2022.
//

#ifndef COUP_A_PLAYER_H
#define COUP_A_PLAYER_H
#include <string>
#include "iostream"
#include "Game.hpp"
using namespace std;
namespace coup {
    class Player {
    public:
        Player(const coup::Game &game, const string &name);
        static int coins();
        static string role();
        void income();
        void foreign_aid();
        void coup(Player p);
    };
}
#endif //COUP_A_PLAYER_H
