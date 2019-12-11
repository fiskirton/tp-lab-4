//
// Created by fiskirton on 10.12.2019.
//

#include "Automata.h"

int main(){

    auto automata = new Automata();

    automata->on();
    automata->coin(20);
    automata->choice(1);
    automata->cook();
    automata->off();

    return 0;
}