//Copyright 2024 Annenko Misha
#include <iostream>
#include "Automata.h"

void Work_Automata(Automata CoffeMachine) {
	CoffeMachine.on();
	CoffeMachine.coin(8);
	CoffeMachine.choice(3);
	CoffeMachine.cancel();
	CoffeMachine.coin(12);
	CoffeMachine.choice(3);
	CoffeMachine.cook(3);
	CoffeMachine.finish();
	CoffeMachine.off();
}

int main()
{
	Automata coffeMachine;
	Work_Automata(coffeMachine);
	
}
