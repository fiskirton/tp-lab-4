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

TEST_F(AutomataTestSuit, test_check_command_test1)
{
    string test_str = "test";
    int res = Automata::check_command(test_str);

    EXPECT_EQ(res, -1);
}


TEST_F(AutomataTestSuit, test_check_command_test2)
{
    string test_str = "0";
    int res = Automata::check_command(test_str);

    EXPECT_EQ(res, 0);
}


TEST_F(AutomataTestSuit, test_off) {
    automata->off();
    EXPECT_EQ(automata->get_state(), OFF);
}

TEST_F(AutomataTestSuit, test_cancel) {
    automata->cancel();
    EXPECT_EQ(automata->get_state(), WAIT);
}

TEST_F(AutomataTestSuit, test_coin1) {
    automata->coin(10);
    EXPECT_EQ(automata->get_cash(), 10);
}

TEST_F(AutomataTestSuit, test_coin2) {
    automata->coin(-100);
    EXPECT_EQ(automata->get_state(), 0);
}

TEST_F(AutomataTestSuit, test_check_cash1) {
    automata->coin(100);
    EXPECT_EQ(automata->check(1), 1);
}

TEST_F(AutomataTestSuit, test_check_cash2) {
    automata->coin(50);
    EXPECT_EQ(automata->check(10), 0);
}

TEST_F(AutomataTestSuit, test_check_choice1) {
    EXPECT_EQ(automata->check_choice(101), 0);
}

TEST_F(AutomataTestSuit, test_check_choice2) {
    EXPECT_EQ(automata->check_choice(1), 1);
}

TEST_F(AutomataTestSuit, test_check_choice3) {
    EXPECT_EQ(automata->check_choice(0), 0);
}

TEST_F(AutomataTestSuit, test_check_choice4) {
    EXPECT_EQ(automata->check_choice(-1), 0);
}





