// Copyright 2022 GHA Test Team
#include "Automata.h"
#include <iostream>

Automata::Automata() : cash(0), state(OFF), choice_(0), current_(0) {}

void Automata::on() {
    state = WAIT;
    std::cout << "The automata is on and waiting for your order\n";
}

void Automata::off() {
    state = OFF;
    std::cout << "The automata is turned off\n";
}

void Automata::coin(int coin) {
    if (state == ACCEPT || state == CHECK) {
        cash += coin;
        state = CHECK;
        std::cout << "The amount on the account: " << cash << " rubles\n";
    }
}

void Automata::getMenu() {
    menu = { "coffee", "tea", "milk" };
    prices = { 50, 30, 40 };
    std::cout << "Menu:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i+1 << "." << menu[i] << " - " << prices[i] << "rubles\n";
    }
}

Automata::STATES Automata::getState() {
    return state;
}

void Automata::choice(int item) {
    if (state == WAIT) {
        current_ = item - 1;
        state = ACCEPT;
        std::cout << "You have chosen: " << menu[current_] << "\n";
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash < prices[current_]) {
            std::cout << "Not enough money on the account\n";
            return false;
        } else {
            state = COOK;
            return true;
          }
    }
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        std::cout << "Order canceled\n";
    }
}

void Automata::cook() {
    if (state == COOK) {
        std::cout << "Making " << menu[current_] << "...\n";
        state = WAIT;
        cash -= prices[current_];
    }
}

void Automata::finish() {
    if (state == COOK) {
        std::cout << "Your " << menu[current_] << " is ready. Take it.\n";
        state = WAIT;
        cash -= prices[current_];
    }
}
