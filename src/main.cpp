//Copyright 2024 Annenko Misha
#include <iostream>
#include "Automata.h"

int main()
{
	Automata coffeMachine;
	Work_Automata(coffeMachine);
}

void Work_Automata(Automata CoffeMachine) {
	CoffeMachine.on();
	CoffeMachine.coin(8);
	CoffeMachine.choice(3);
	CoffeMachine.cancel();
	CoffeMachine.coin(12);
	CoffeMachine.check(3);
	CoffeMachine.cook(3);
	CoffeMachine.finish();
	CoffeMachine.off();
}
