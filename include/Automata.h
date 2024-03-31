//Copyright 2024 Annenko Misha

#pragma once
#include <iostream>

enum STATES {
OFF,
WAIT,
ACCEPT,
CHECK,
COOK
};

class Automata {
 public:
Automata();
~Automata();
void on();
void off();
void coin(int Money);
void getMenu();
STATES getState();
void choice(int Choice);
void check(int Check);
void cancel();
void cook(int num);
void finish();
 private:
int cash;
string* menu;
int* prices;
STATES state;
};
