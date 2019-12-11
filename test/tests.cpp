#include "gtest/gtest.h"
#include "Automata.h"
#include <string>


class AutomataTestSuit : public ::testing::Test {
public:
    virtual ~AutomataTestSuit() {
        delete automata;
    }

protected:
    virtual void SetUp() {
        automata = new Automata();
    }

    Automata * automata;
};


TEST_F(AutomataTestSuit, test_off) {
    automata->off();
    EXPECT_EQ(automata->get_state(), OFF);
}

TEST_F(AutomataTestSuit, test_cancel) {
    automata->cancel();
    EXPECT_EQ(automata->get_state(), WAIT);
}

TEST_F(AutomataTestSuit, test_coin_automata_off) {
    automata->coin(10);
    EXPECT_EQ(automata->get_cash(), 0);
}


TEST_F(AutomataTestSuit, test_coin_automata_on) {
    automata->on();
    automata->coin(20);
    EXPECT_EQ(automata->get_cash(), 20);
}

TEST_F(AutomataTestSuit, test_coin_negative) {
    automata->on();
    automata->coin(-20);
    EXPECT_EQ(automata->get_cash(), 0);
}

TEST_F(AutomataTestSuit, test_coin_accept_state) {
    automata->on();
    automata->coin(20);
    EXPECT_EQ(automata->get_state(), ACCEPT);
}

TEST_F(AutomataTestSuit, test_cook_state1) {
    automata->on();
    automata->coin(20);
    automata->choice(10);
    automata->cook();
    EXPECT_EQ(automata->get_cash(), 20);
}

TEST_F(AutomataTestSuit, test_cook_state2) {
    automata->on();
    automata->coin(20);
    automata->choice(-1);
    automata->cook();
    EXPECT_EQ(automata->get_cash(), 20);
}


TEST_F(AutomataTestSuit, test_cook_state3) {
    automata->on();
    automata->coin(20);
    automata->choice(1);
    automata->cook();
    EXPECT_EQ(automata->get_cash(), 10);
}




