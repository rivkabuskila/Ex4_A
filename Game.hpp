//
// Created by rivka on 25/04/2022.
//

#ifndef COUP_A_GAME_H
#define COUP_A_GAME_H

#include <vector>
#include <string>
using namespace std;
namespace coup {
    class Game {
    public:
        vector<string> static players();
        string static turn();
        static string winner();
    };
}

#endif //COUP_A_GAME_H
