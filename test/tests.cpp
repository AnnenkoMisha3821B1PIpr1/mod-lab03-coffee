// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
protected:
Automata CoffeMachine;
};

TEST(AutomataTest, TURN_ON) {
  Automata CoffeMachine;
  CoffeMachine.on();
  EXPECT_EQ(WAIT, CoffeMachine.getState());
}

TEST(AutomataTest, TURN_OFF) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.off();
  EXPECT_EQ(OFF, CoffeMachine.getState());
}

TEST(AutomataTest, CHOICE_DRINKING) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.coin(25);
  CoffeMachine.choice(1);
  EXPECT_EQ(CHECK, CoffeMachine.getState());
}

TEST(AutomataTest, UNAVAILABLE_DRINK) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.coin(7);
  CoffeMachine.choice(3);
  EXPECT_EQ(CHECK, CoffeMachine.getState());
}

TEST(AutomataTest, CYCLE_SOME_OPERATION) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.coin(7);
  CoffeMachine.choice(3);
  CoffeMachine.cancel();
  CoffeMachine.coin(5);
  CoffeMachine.choice(3);
  EXPECT_EQ(CHECK, CoffeMachine.getState());
}

TEST(AutomataTest, COOK_TRUE) {
Automata CoffeMachine;
CoffeMachine.on();
CoffeMachine.coin(10);
CoffeMachine.choice(1);
CoffeMachine.cook(1);
EXPECT_EQ(COOK, CoffeMachine.getState());
}

TEST(AutomataTest, COOK_FALSE) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.coin(8);
  CoffeMachine.choice(3);
  CoffeMachine.check(3);
  CoffeMachine.cook(3);
  EXPECT_EQ(CHECK, CoffeMachine.getState());
}

TEST(AutomataTest, COOK_NOT_CANCEL) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.coin(10);
  CoffeMachine.choice(1);
  CoffeMachine.cook(1);
  CoffeMachine.cancel();
  EXPECT_EQ(COOK, CoffeMachine.getState());
}

TEST(AutomataTest, COOK_CAN_FINISH) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.coin(40);
  CoffeMachine.choice(2);
  CoffeMachine.cook(2);
  CoffeMachine.finish();
  EXPECT_EQ(WAIT, CoffeMachine.getState());
}

TEST(AutomataTest, CYCLE_COIN_IN_ACCEPT) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.coin(7);
  CoffeMachine.coin(11);
  CoffeMachine.coin(22);
  EXPECT_EQ(ACCEPT, CoffeMachine.getState());
}

TEST(AutomataTest, CHECK_OFF_AFTER_OPERATIONS) {
  Automata CoffeMachine;
  CoffeMachine.on();
  CoffeMachine.coin(6);
  CoffeMachine.choice(3);
  CoffeMachine.cancel();
  CoffeMachine.coin(40);
  CoffeMachine.choice(3);
  CoffeMachine.check(3);
  CoffeMachine.cook(3);
  CoffeMachine.finish();
  CoffeMachine.off();
  EXPECT_EQ(OFF, CoffeMachine.getState());
}
