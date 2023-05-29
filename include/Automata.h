// Copyright 2022 GHA Test Team
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum position {off, wait, accept, check, cook};
class Automata {
   private:
   unsigned int cash;
   std::string menu[7] = {"espresso", "americano", "cappuccino", "latte", "ice coffee", "tea", "cacao"};
 unsigned int prices[7] = {80, 90, 120, 130, 150, 100, 125};
 position state;
 unsigned int num_drink
 public:
    Automata();
    void on();
    void off();
    void coin(unsigned int summa);
    void getMenu();
    position getState();
    void choice(unsigned int num);
    bool check();
    void cancel();
   
 private:
 void check();
 void cook();
 void finish();
void getChange(unsigned int price=0);
};
#endif // INCLUDE_AUTOMATA_H_
