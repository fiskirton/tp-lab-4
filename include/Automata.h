//
// Created by fiskirton on 10.12.2019.
//

#ifndef AUTOMATA_AUTOMATA_H
#define AUTOMATA_AUTOMATA_H

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

struct position{
    string name;
    int price;
};

enum STATES{OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {

    map <int, position> menu = {
            {1, {"Water", 10}},
            {2, {"Soda", 15}},
            {3, {"Green tea", 15}},
            {4, {"Black tea", 15}},
            {5, {"Espresso", 30}},
            {6, {"Latte", 45}},
            {7, {"Cappuccino", 50}},
            {8, {"Double espresso", 60}},
            {9, {"Double latte", 75}},
            {10, {"Mocaccino", 100}}
    };

private:
    int cash;
    STATES state;

    void wait_state();
    void acceptance_state();
    void check_state(int );
    void cook_state(int );


public:

    Automata(){
        cash = 0;
        state = OFF;
    }

    ~Automata() = default;

    int get_cash(){return this->cash;}
    int get_state(){ return this->state;}

    void set_cash(int value){ this->cash = value;}
    void set_state(STATES value){ this->state = value;}

    void off();
    void cancel();

    void coin(int );
    bool check(int );
    void finish(int );
    int check_choice(int );
    static void cook();
    void getMenu();
    static int check_command(const string& );
    void on();

};

#endif //AUTOMATA_AUTOMATA_H
