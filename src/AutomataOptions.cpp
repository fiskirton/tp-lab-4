//
// Created by fiskirton on 10.12.2019.
//

#include "Automata.h"

int Automata::on()
{

    this->set_state(WAIT);
    return this->get_state();

}

int Automata::off()
{
    if (this->get_state() == WAIT)
    {
        this->set_state(OFF);
        return this->get_state();
    } else
    {
        return  -1;
    }


}

int Automata::cancel()
{

    this->set_state(WAIT);
    return this->get_state();

}

int Automata::finish()
{

    this->set_cash(this->get_cash() - Automata::menu[this->get_user_choice()].price);
    this->set_state(WAIT);
    return this->get_state();


}

int Automata:: cook()
{
    if (this->get_state() == ACCEPT && this->check(this->get_user_choice()))
    {
        this->set_state(COOK);
        this->finish();
        return this->get_state();
    } else
    {
        this->cancel();
        return -1;
    }


}

bool Automata::check(int choice)
{
    return this->get_cash() >= menu[choice].price;
}

int Automata::choice(int to_check)
{
    if (this->get_state() == ACCEPT and this->in_menu(to_check))
    {
        this->set_user_choice(to_check);
        return this->get_user_choice();
    } else
    {
        this->cancel();
        return -1;
    }
}

void Automata::getMenu()
{
    cout << "№" <<  " | " << "Position" << " | " << "Price" << endl;
    for(const auto& pos: menu)
    {
        cout << pos.first << " | " << pos.second.name << " | " << pos.second.price << endl;
    }
}

int Automata::coin(int coins)
{

    if (this->get_state() == ACCEPT || this->get_state() == WAIT)
    {
        this->set_state(ACCEPT);

        if (coins < 0)
        {
            return -1;
        }
        int new_cash = this->get_cash() + coins;
        this->set_cash(new_cash);

        return this->get_cash();
    }else
    {
        return -1;
    }

}

int Automata::in_menu(int to_check)
{
    return menu.find(to_check) != menu.end();
}

int Automata::get_user_choice() const {
    return user_choice;
}

void Automata::set_user_choice(int userChoice) {
    user_choice = userChoice;
}
