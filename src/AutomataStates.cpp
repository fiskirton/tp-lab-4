//
// Created by fiskirton on 10.12.2019.
//

#define ERR_MSG "Incorrect command"

#include "Automata.h"


void Automata::wait_state()
{

    int command;

    while(this->get_state() != OFF)
    {

        cout << "Enter command" << endl;
        cout << "0 - OFF" << endl;
        cout << "1 - START" << endl;

        string command_str;
        cin >> command_str;
        command = Automata::check_command(command_str);

        if (command < 0){
            cout << ERR_MSG << endl;
            continue;
        }

        cout << command << endl;
        switch (command)
        {
            case 0:
                this->off();
                cout << "Your cash is" << " " << this->get_cash() << endl;
                cout << "OFF" << endl;
                break;
            case 1:
                this->set_state(ACCEPT);
                this->acceptance_state();
                break;
            default:
                cout << ERR_MSG << endl;
        }
    }
}

void Automata::acceptance_state()
{

    int command;
    string choice_str;
    int choice = 0;
    int coins;
    string coins_str;

    while(this->get_state() != WAIT and this->get_state() != CHECK)
    {

        cout << "Enter command" << endl;
        cout << "0 - Cancel" << endl;
        cout << "1 - Put coins" << endl;
        cout << "2 - Make choice" << endl;
        cout << "3 - Get balance" << endl;

        string command_str;
        cin >> command_str;

        command = Automata::check_command(command_str);

        if (command < 0){
            cout << ERR_MSG << endl;
            continue;
        }

        switch(command)
        {
            case 0:
                this->cancel();
                cout << "Cancel" << endl;
                break;
            case 1:
                cout << "Put coins" << endl;
                cin >> coins_str;
                coins = Automata::check_command(coins_str);
                if (coins < 0){
                    cout << ERR_MSG << endl;
                    continue;
                }
                this->coin(coins);
                cout << "Your cash is" << " " << this->get_cash() << endl;
                continue;
            case 2:
                this->getMenu();
                cin >> choice_str;
                choice = Automata::check_command(choice_str);
                if(choice < 0 or !this->check_choice(choice)){
                    cout << ERR_MSG << endl;
                    continue;
                }
                cout << "Your check_choice is " << " " << menu[choice].name << endl;
                this->set_state(CHECK);
                break;
            case 3:
                cout << "Your cash is" << " " << this->get_cash() << endl;
                break;
            default:
                cout << ERR_MSG << endl;
        }
    }

    switch (this->get_state())
    {
        case WAIT:
            break;
        case CHECK:
            this->check_state(choice);
            break;
    }

}

void Automata::check_state(int choice)
{
    int command;
    while (this->get_state() != WAIT and this->get_state() != COOK)
    {
        cout << "Enter command" << endl;
        cout << "0 - Cancel" << endl;
        cout << "1 - Cook" << endl;

        string command_str;
        cin >> command_str;
        command = Automata::check_command(command_str);

        if (command < 0){
            cout << ERR_MSG << endl;
            continue;
        }

        switch (command)
        {
            case 0:
                this->cancel();
                cout << "Cancel" << endl;
                break;
            case 1:
                if (this->check(choice)){
                    this->set_state(COOK);
                } else{
                    cout << "Not enough money" << endl;
                    cout << "Return to the WAIT state" << endl;
                    this->set_state(WAIT);
                }
                break;
            default:
                cout << ERR_MSG << endl;
        }

    }

    switch (this->get_state())
    {
        case WAIT:
            break;
        case COOK:
            int new_cash = this->get_cash() - menu[choice].price;
            this->set_cash(new_cash);
            this->cook_state(choice);
            break;
    }
}

void Automata::cook_state(int choice) {
    Automata::cook();
    cout << "Cooking..." << endl;
    this->finish(choice);
}

