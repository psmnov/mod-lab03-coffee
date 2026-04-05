#include <iostream>
#include "Automata.h"
#include <windows.h>
int main() {
	Automata automat;
	//1
	automat.on();
	std::cout << automat.getState() << " ";
	automat.coin(40);
	std::cout << automat.getState() << " ";
	std::cout << "Balance: " << automat.getBalance() << "\n";
	automat.cancel();
	/*методы описаны  в соотетствии с диаграммой, поэтому для того, чтобы что-то
	приготовить когда деньги уже есть на балансе, но до этого клиент выбрал отмена, допустимо нулевое пополнение*/
	//2
	std::cout << automat.getState() << " ";
	automat.coin(0);
	std::cout << automat.getState() << " ";
	std::cout << "Balance: " << automat.getBalance() << "\n";
	automat.getExchange();
	automat.choice(1);
	//3
	std::cout << automat.getState() << " ";
	automat.cancel();
	automat.coin(45);
	std::cout << automat.getState() << " ";
	std::cout << "Balance: " << automat.getBalance() << "\n";
	automat.choice(1);
	automat.getExchange();

	return 0;
}
