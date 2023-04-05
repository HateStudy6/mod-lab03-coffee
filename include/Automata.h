// Copyright 2022 GHA Test Team
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

class Automata {
 public:
    Automata();
    void on();
    void off();
    void coin(int coin);
    void getMenu();
    enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
    STATES state;
    STATES getState();
    void choice(int item);
    bool check();
    void cancel();
    void cook();
    void finish();
 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    int choice_;
    int current_;
};
#endif // INCLUDE_AUTOMATA_H_