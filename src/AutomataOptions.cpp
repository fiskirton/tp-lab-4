//
// Created by fiskirton on 10.12.2019.
//

#include <zconf.h>
#include "Automata.h"

void Automata::on()
{
    this->set_state(WAIT);
    this->wait_state();
}

void Automata::off()
{

    this->set_state(OFF);
}

void Automata::cancel()
{

    this->set_state(WAIT);

}

void Automata::finish(int choice) {
    cout << "Your" << " " << menu[choice].name << ", " << "Sir" << endl;
    cout << "Your cash is" << " " << this->get_cash() << endl;
}

void Automata:: cook()
{

    sleep(3);

}

bool Automata::check(int choice)
{
    return this->cash >= menu[choice].price;
}

int Automata::check_choice(int to_check)
{
    return menu.find(to_check) != menu.end();
}

void Automata::getMenu() {
    cout << "№" <<  " | " << "Position" << " | " << "Price" << endl;
    for(const auto& pos: menu){
        cout << pos.first << " | " << pos.second.name << " | " << pos.second.price << endl;
    }
}

void Automata::coin(int coins) {

    int new_cash = this->get_cash() + coins;
    this->set_cash(new_cash);
}

int Automata::check_command(const string& command_str)
{
    int command;

    try
    {
        command = stoi(command_str);
    }

    catch (exception &ex)
    {
        return -1;
    }

    return command;
}