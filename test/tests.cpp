// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
Automata a = Automata();
a.on();
a.getMenu();
a.choice(1);
a.coin(20);
EXPECT_EQ(Automata::CHECK, a.getState());
EXPECT_FALSE(a.check());
}

TEST(task1, test2) {
Automata a = Automata();
a.on();
a.getMenu();
a.choice(3);
a.coin(40);
a.check();
EXPECT_EQ(Automata::COOK, a.getState());
a.finish();
EXPECT_EQ(Automata::WAIT, a.getState());
}

TEST(task1, test3) {
Automata a = Automata();
a.on();
a.getMenu();
a.choice(1);
a.coin(50);
a.check();
EXPECT_EQ(Automata::COOK, a.getState());
}

TEST(task1, test4) {
Automata a = Automata();
a.on();
a.off();
EXPECT_EQ(Automata::OFF, a.getState());
a.on();
a.getMenu();
a.choice(1);
a.coin(50);
a.check();
EXPECT_EQ(Automata::COOK, a.getState());
a.off();
EXPECT_EQ(Automata::OFF, a.getState());
}
