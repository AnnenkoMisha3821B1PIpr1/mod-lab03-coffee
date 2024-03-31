//Copyright 2024 Annenko Misha
#include "Automata.h"

Automata::Automata() {
cash = 0;
menu = new std::string[3]{ "Americano", "Cappuccino", "Latte" };
prices = new int[3] {6, 20, 10};
state = OFF;
}

Automata::~Automata() { } // деструктор

void Automata::on() {
if (state == OFF) {
state = WAIT;
std::cout << "Turn on machine" << std::endl;
} else {
std::cout << "Unavailable transition to a new state" << std::endl;
}
}

void Automata::off() {
if (state == WAIT) {
state = OFF;
std::cout << "Turn of machine" << std::endl;
} else {
std::cout << "Unavailable transition to a new state" << std::endl;
}
}

void Automata::coin(int Money) {
if (state == WAIT || state == ACCEPT) {
state = ACCEPT;
cash += Money;
std::cout << "On your account now at $: " << cash << std::endl;
} else {
std::cout << "Unavailable transition to a new state" << std::endl;
}
}

void Automata::getMenu() {
if (state != OFF && (state == WAIT || state == ACCEPT)) {
int count = menu->length();
std::cout << "MENU:" << std::endl;
for (int i = 0; i < count; i++) {
std::cout << "Title: " << menu[i] << "=> Price: "
<< prices[i] << "$" << std::endl;
}
}
}

STATES Automata::getState() {
return state;
}

void Automata::choice(int Choice) {
if (state == ACCEPT) {
if (Choice < 1 || Choice > 3) {
std::cout << "Error number" << std::endl;
} else {
state = CHECK;
check(Choice);
}
} else {
std::cout << "Unavailable transition to a new state" << std::endl;
}
}

void Automata::check(int Check) {
if (state == CHECK) {
if (cash >= prices[Check - 1]) {
state = CHECK;
std::cout << "Successfully verified " << std::endl;

} else {
std::cout << "Not enough money. Missing amount: "
<< prices[Check - 1] - cash << std::endl;
}
} else {
std::cout << "Deposit money and choose a drink" << std::endl;
}
}

void Automata::cancel() {
if (state == ACCEPT || state == CHECK) {
std::cout << "Canceling all operations" << std::endl;
state = WAIT;
} else {
std::cout << "Unavailable transition to a new state" << std::endl;
}
}

void Automata::cook(int num) {
if (cash >= prices[num - 1] && state == CHECK) {
state = COOK;
cash -= prices[num - 1];
std::cout << "Cook drink: " << menu[num - 1] << std::endl;
} else {
std::cout << "Deposit money and choose a drink" << std::endl;
}
}

void Automata::finish() {
if (state == COOK) {
state = WAIT;
std::cout << "Your drink redy! Enjoy it!" << std::endl;
} else {
std::cout << "Not ready yet! Please wait!" << std::endl;
}
}
