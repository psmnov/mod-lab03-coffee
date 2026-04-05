//Copyright 2026 petr smirnov
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <vector>
#include <string>

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
	void on();
	void off();
	void coin(double money);
	std::vector<std::string> getMenu();
	STATES getState();
	void choice(int choice);
	void cancel();
	double getBalance();
	double getExchange();
private:
	double cash;
	STATES state;
	std::vector<std::string> menu;
	std::vector<double> prices;
	void cook(int choice);
	void finish();
	bool check(int choice);

};
#endif
