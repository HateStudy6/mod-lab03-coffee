// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(on, test1) {
Automata aut;
aut.on();
EXPECT_EQ(WAIT, aut.getState());
}

TEST(off, test2) {
Automata aut;
EXPECT_EQ(OFF, aut.getState());
}

TEST(off, test3) {
Automata aut;
aut.on();
aut.coin(1);
aut.off();
EXPECT_EQ(OFF, aut.getState());
}

TEST(coin, test4) {
Automata aut;
aut.on();
aut.coin(1);
aut.coin(1);
EXPECT_EQ(ACCEPT, aut.getState());}