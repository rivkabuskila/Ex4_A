
// Created by rivka on 26/04/2022.
#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "doctest.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
using namespace coup;
Game game_1{};
Duke duke{game_1, "Moshe"};
Assassin assassin{game_1, "Yossi"};
Ambassador ambassador{game_1, "Meirav"};
Captain captain1{game_1, "Reut"};
Contessa contessa{game_1, "Gilad"};
Captain captain2{game_1, "Hodaya"};


TEST_CASE ("Game class") {
            SUBCASE("players function") {
        vector <string> players1 = game_1.players();
        vector <string> players2 = {"Moshe", "Yossi", "Meirav", "Reut", "Gilad","Hodaya"};
        unsigned long i = 0;
        for (string name: players1) {
                    CHECK(name == players2.at(i++));
        }
    }
            SUBCASE("turn function") {
        string name = game_1.turn();
                CHECK(name == "Moshe");
    }
}

TEST_CASE ("income function") {
    duke.income();
    CHECK(duke.coins() == 1);
    CHECK_THROWS(duke.income());
    assassin.income();
    CHECK(assassin.coins() == 1);
    CHECK_THROWS(assassin.income());
    ambassador.income();
    CHECK(ambassador.coins() == 1);
    CHECK_THROWS(ambassador.income());
    captain1.income();
    CHECK(captain1.coins() == 1);
    CHECK_THROWS(captain1.income());
    contessa.income();
    CHECK(contessa.coins() == 1);
    CHECK_THROWS(contessa.income());
    captain2.income();
    CHECK(captain2.coins() == 1);
    CHECK_THROWS(captain2.income());

}
TEST_CASE("foreign_aid function") {
    duke.foreign_aid();
    CHECK(duke.coins() == 3);
    CHECK_THROWS(duke.foreign_aid());
    assassin.foreign_aid();
    CHECK(assassin.coins() == 3);
    CHECK_THROWS(assassin.foreign_aid());
    ambassador.foreign_aid();
    CHECK(ambassador.coins() == 3);
    CHECK_THROWS(ambassador.foreign_aid());
    captain1.foreign_aid();
    CHECK(captain1.coins() == 3);
    CHECK_THROWS(captain1.foreign_aid());
    contessa.foreign_aid();
    CHECK(contessa.coins() == 3);
    CHECK_THROWS(contessa.foreign_aid());
    captain2.foreign_aid();
    CHECK(captain2.coins() == 3);
    CHECK_THROWS(captain2.foreign_aid());

}
TEST_CASE("coins function") {
    CHECK(duke.coins() == 3);
    CHECK(assassin.coins() == 3);
    CHECK(ambassador.coins() == 3);
    CHECK(captain1.coins() == 3);
    CHECK(contessa.coins() == 3);
    duke.income();
    CHECK(duke.coins() == 4);
}
TEST_CASE("role function") {
    CHECK(duke.role() == "Duke");
    CHECK(assassin.role() == "Assassin");
    CHECK(ambassador.role() == "Ambassador");
    CHECK(captain1.role() == "Captain");
    CHECK(contessa.role() == "Contessa");
}

TEST_CASE ("Duke class") {
     SUBCASE("block function") {
           assassin.foreign_aid();
           duke.block(assassin);
           CHECK(assassin.coins() == 4);
           ambassador.foreign_aid();
           duke.block(ambassador);
           CHECK(ambassador.coins() == 4);
           captain1.foreign_aid();
           duke.block(captain1);
           CHECK(captain1.coins() == 4);
           contessa.foreign_aid();
           duke.block(contessa);
           CHECK(contessa.coins() == 4);
           captain2.foreign_aid();
           duke.block(captain2);
           CHECK(captain2.coins() == 4);

    }
    SUBCASE("tax function") {
        duke.tax();
        CHECK(duke.coins() == 7);
    }
}
TEST_CASE ("Assassin class") {
            SUBCASE("coup function") {
        assassin.coup(duke);
            vector <string> players1 = game_1.players();
            vector <string> players2 = {"Yossi", "Meirav", "Reut", "Gilad","Hodaya"};
            unsigned long i = 0;
            for (string name: players1) {
                        CHECK(name == players2.at(i++));
            }
    }
}
TEST_CASE ("Contessa class") {
    SUBCASE("block function") {
        contessa.block(assassin);
        vector <string> players1 = game_1.players();
        vector <string> players2 = {"Moshe", "Yossi", "Meirav", "Reut", "Gilad","Hodaya"};
        unsigned long i = 0;
        for (string name: players1) {
                    CHECK(name == players2.at(i++));
        }
    }
}
TEST_CASE ("Ambassador class") {
            SUBCASE("transfer function") {
        ambassador.transfer(duke, assassin);
                CHECK(duke.coins() == 6);
                CHECK(assassin.coins() == 5);
}
            SUBCASE("block function") {
                captain1.steal(duke);
                ambassador.block(captain1);
                CHECK(duke.coins() == 6);
    }
}



TEST_CASE ("Captain class") {
            SUBCASE("steal function") {
                contessa.income();
                captain2.steal(contessa);
                CHECK(captain2.coins()==8);

    }
            SUBCASE("block function") {
                captain1.block(captain2);
                CHECK(captain2.coins() == 6);
    }
}

TEST_CASE ("coup function") {
    duke.tax();
    assassin.coup(ambassador);
    vector <string> players1 = game_1.players();
    vector <string> players2 = {"Moshe", "Yossi", "Reut", "Gilad","Hodaya"};
    unsigned long i = 0;
    for (string name: players1) {
                CHECK(name == players2.at(i++));
    }
    captain1.steal(contessa);
    contessa.foreign_aid();
    captain2.steal(contessa);
    duke.coup(captain2);
    players1 = game_1.players();
    players2 = {"Moshe", "Yossi", "Reut", "Gilad"};
    i = 0;
    for (string name: players1) {
                CHECK(name == players2.at(i++));
    }
    assassin.foreign_aid();
    captain1.steal(contessa);
    contessa.foreign_aid();
    duke.tax();
    assassin.coup(captain1);
    players1 = game_1.players();
    players2 = {"Moshe", "Yossi", "Gilad"};
    i = 0;
    for (string name: players1) {
                CHECK(name == players2.at(i++));
    }
    contessa.foreign_aid();
    duke.tax();
    assassin.foreign_aid();
    duke.coup(contessa);
    players1 = game_1.players();
    players2 = {"Moshe", "Yossi"};
    i = 0;
    for (string name: players1) {
                CHECK(name == players2.at(i++));
    }
    assassin.coup(duke);
    players1 = game_1.players();
    players2 = {"Yossi"};
    i = 0;
    for (string name: players1) {
                CHECK(name == players2.at(i++));
    }
}
TEST_CASE("winner function") {
CHECK(game_1.winner()== "Assassin");
}

