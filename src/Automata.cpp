// Copyright 2022 GHA Test Team
#include "Automata.h"
#include <iostream>

Automata::Automata()
{ cash = 0; state = OFF; }

void Automata::on() {
    if ( state == OFF)
    {cash = 0;
    state = WAIT;
    getMenu();
    }
}

void Automata::off() {
    getChange();
    cash = 0;
    state = OFF;
}

void Automata::coin(unsigned int summa) {
    if (state == ACCEPT || state == WAIT) {
        cash += summa;
        state = ACCEPT;
    }
}

void Automata::getMenu() {
    std::cout << "Menu: " << std::endl;
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        std::cout << i+1 << "." << menu[i] << " - " << prices[i] << std::endl;
    }
}

position  Automata::getState() {
    return state;
}

void Automata::choice(unsigned int num) {
    if (state == ACCEPT)
  { 
    if ((num > 0) && (sizeof(menu) / sizeof(menu[0]) >= num)) {
        num_drink = num - 1;
        state = CHECK;
        check();
    }
        else
   { std::cout << "error in selection " << std::endl; }
    else
    { std::cout << "error "  << std::endl; }
  }
}

void Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[num_drink]) {
            getChange(prices[num_drink]);
            cook();
        } else 
        {
            std::cout << "not enough money" << std::endl;
            canel();
          }
    }
}

void Automata::cancel(){
 if (state == ACCEPT || state == CHECK)
 {
     getChange();
     cash = 0;
     state = WAIT;
 } 
 else 
 {
    std::cout << "Error"<< std::endl;
 }
}



void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        std::cout << "your " << menu[num_drink] << "ready" << std::endl;
        finish();  
    }
}

void Automata::finish() {
    if (state == COOK) {
    cash = 0;
    state = WAIT;
    }
}
void Automata::getChange(unsigned int price) {
    if (cash - price != 0)
    std::cout << "your change" << cash - price << std::endl;
}
