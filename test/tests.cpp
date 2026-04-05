// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <string>
#include <vector>

TEST(AutomataTest, GetsMenu) {
    std::vector<std::string> menu = { "espresso", "latte", "hot chocolate" };
    Automata autom;
    autom.on();
    EXPECT_EQ(autom.getMenu(), menu);
}
TEST(AutomataTest, GetsBalance) {
    Automata autom;
    autom.on();
    autom.coin(123128631872361);
    EXPECT_EQ(autom.getBalance(), 123128631872361);
}
TEST(AutomataTest, StateChangesToWait) {
    Automata autom;
    autom.on();
    EXPECT_EQ(autom.getState(), WAIT);
}
TEST(AutomataTest, FirstStateOff) {
    Automata autom;
    EXPECT_EQ(autom.getState(), OFF);
}
TEST(AutomataTest, CoinChangesToACCEPT) {
    Automata autom;
    autom.on();
    autom.coin(5);
    EXPECT_EQ(autom.getState(), ACCEPT);
}
TEST(AutomataTest, CoinDoNotChangesToACCEPT) {
    Automata autom;
    autom.on();
    autom.coin(-1);
    EXPECT_EQ(autom.getState(), WAIT);
}
TEST(AutomataTest, CancelWorks) {
    Automata autom;
    autom.on();
    autom.coin(5);
    autom.cancel();
    EXPECT_EQ(autom.getState(), WAIT);
}
TEST(AutomataTest, CoinChangesBalance) {
    Automata autom;
    autom.on();
    autom.coin(5);
    autom.cancel();
    EXPECT_EQ(autom.getBalance(), 5);
}
TEST(AutomataTest, CoinDoChangesBalance) {
    Automata autom;
    autom.on();
    autom.coin(5);
    autom.coin(-5);
    autom.cancel();
    EXPECT_EQ(autom.getBalance(), 5);
}
TEST(AutomataTest, ChoiceStartsThenFinishes) {
    Automata autom;
    autom.on();
    autom.coin(55);
    autom.choice(1);
    EXPECT_EQ(autom.getState(), WAIT);
}
TEST(AutomataTest, GetsExchage) {
    Automata autom;
    autom.on();
    autom.coin(55);
    EXPECT_EQ(autom.getExchange(), 55);
}
