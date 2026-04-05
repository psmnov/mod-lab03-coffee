//Copyright 2026 petr smirnov
#include "Automata.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>

Automata::Automata() {
    cash = 0;
    state = OFF;
    menu = { "espresso", "latte", "hot chocolate" };
    prices = { 30, 40, 45 };
}
void Automata::on() {
    state = (state == OFF) ? WAIT : state;
}
void Automata::off() {
    state = (state == WAIT) ? OFF : state;
}
double Automata::getBalance() {
    return cash;
}
void Automata::coin(double money) {
    if (money < 0) {
        std::cout << "must be > 0 \n";
        return;
    }
    if (state == ACCEPT || state == WAIT) {
        state = ACCEPT;
        cash += money;
        std::cout << "Added " << money << " , balance: " << cash << "\n";
    } else {
      std::cout << "incorrect state for deposit\n";
	}
}
std::vector<std::string> Automata::getMenu() {
    return menu;
}
STATES Automata::getState() {
    return state;
}
void Automata::choice(int index) {
    if (state != ACCEPT) return;
    if (index < 0 || index >= menu.size()) {
        std::cout << "no such position\n";
        return;
    }
    state = CHECK;
	cook(index);
}
bool Automata::check(int index) {
    if (state != CHECK) return false;
    if (prices[index] > cash) {
        std::cout << "not enough cash\n";
        return false;
    }
    return true;
}
void Automata::cook(int index) {
    if (!check(index)) return;
    state = COOK;
    cash -= prices[index];
    std::cout << menu[index] << " cooking...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    finish();
}
void Automata::cancel() {
    state = (state == CHECK || state == ACCEPT) ? WAIT : state;
}
void Automata::finish() {
    if (state != COOK) return;
    if (cash > 0) {
        std::cout << "Your exchange: " << cash << "\n";
        cash = 0;
    }
    state = WAIT;
    std::cout << "Process finished\n";
}
double Automata::getExchange() {
    if ((state == WAIT || state == ACCEPT) && cash > 0) {
        std::cout << "Your exchange: " << cash << "\n";
        double temp = cash;
        cash = 0;
        return temp;
    } else {
        std::cout << "Nothing to return or wrong state.\n";
    }
}
