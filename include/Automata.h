

#include <string>


enum position {off, wait, accept, check, cook};

class Automata {
   
   private:
unsigned int cash;
std::string menu[7] = { "espresso",
 "americano", 
 "cappuccino",
 "latte",
 "ice coffee", 
 "tea", 
 "cacao" };
unsigned int prices[7] = {80, 90, 120, 130, 150, 100, 125};
position state;
unsigned int num_drink;

 public:
Automata();
void on();
void off();
void coin(unsigned int summa);
void getMenu();
position getState();
void choice(unsigned int num);
void check();
void cancel();
 private:
void check();
void cook();
void finish();
void getChange(unsigned int price = 0);
};

