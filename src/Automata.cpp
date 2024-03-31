//Copyright 2024 Annenko Misha
#include "Automata.h"

Automata::Automata() {
cash = 0;
menu = new string[3]{ "Americano", "Cappuccino", "Latte" };
prices = new int[3] {6, 20, 10};
state = OFF;
}

Automata::~Automata() { } // деструктор

void Automata::on() {
if (state == OFF) {
state = WAIT;
cout << "Turn on machine" << endl;
} else {
cout << "Unavailable transition to a new state" << endl;
}
}

void Automata::off() {
if (state == WAIT) {
state = OFF;
cout << "Turn of machine" << endl;
} else {
cout << "Unavailable transition to a new state" << endl;
}
}

void Automata::coin(int Money) {
if (state == WAIT || state == ACCEPT) {
state = ACCEPT;
cash += Money;
cout << "On your account now at $: " << cash << endl;
} else {
cout << "Unavailable transition to a new state" << endl;
}
}

void Automata::getMenu() {
if (state != OFF && (state == WAIT || state == ACCEPT)) {
int count = menu->length();
cout << "MENU:" << endl;
for (int i = 0; i < count; i++) {
cout << "Title: " << menu[i] << "=> Price: " << prices[i] << "$" << endl;
}
}
}

STATES Automata::getState() {
return state;
}

void Automata::choice(int Choice) {
if (state == ACCEPT) {
if (Choice < 1 || Choice > 3) {
cout << "Error number" << endl;
} else {
state = CHECK;
check(Choice);
}
} else {
cout << "Unavailable transition to a new state" << endl;
}
}

void Automata::check(int Check) {
if (state == CHECK) {
if (cash >= prices[Check - 1]) {
state = CHECK;
cout << "Successfully verified " << endl;

} else {
cout << "Not enough money. Missing amount: "
<< prices[Check - 1] - cash << endl;
}
} else {
cout << "Deposit money and choose a drink" << endl;
}
}

void Automata::cancel() {
if (state == ACCEPT || state == CHECK) {
cout << "Canceling all operations" << endl;
state = WAIT;
} else {
cout << "Unavailable transition to a new state" << endl;
}
}

void Automata::cook(int num) {
if (cash >= prices[num - 1] && state == CHECK) {
state = COOK;
cash -= prices[num - 1];
cout << "Cook drink: " << menu[num - 1] << endl;
} else {
cout << "Deposit money and choose a drink" << endl;
}
}

void Automata::finish() {
if (state == COOK) {
state = WAIT;
cout << "Your drink redy! Enjoy it!" << endl;
} else {
cout << "Not ready yet! Please wait!" << endl;
}
}
