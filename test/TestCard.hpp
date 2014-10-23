#include <boost/test/unit_test.hpp>
#include "Card.h"
#include "Exceptions.h"

class Player {

};

BOOST_AUTO_TEST_SUITE(TestCard)

BOOST_AUTO_TEST_CASE(CreateCard)
{
    Stack().makeCard();
}

BOOST_AUTO_TEST_CASE(CheckLookThrow)
{
    BOOST_CHECK_THROW(Stack().makeCard().look(std::shared_ptr<Player>()), InvalidAccess);
}

BOOST_AUTO_TEST_CASE(CheckLookThrowAnotherPlayer)
{
    auto p = std::make_shared<Player>();
    auto p1 = std::make_shared<Player>();
    BOOST_CHECK_THROW(Stack().makeCard(p).look(p1), InvalidAccess);
}


BOOST_AUTO_TEST_CASE(CheckLookNoThrowAndValid)
{
    auto p = std::make_shared<Player>();
    Card c = std::move(Stack().makeCard(p));
    BOOST_CHECK_EQUAL(Card::Sprade, c.look(p).first);
    BOOST_CHECK_EQUAL(Card::D2, c.look(p).second);
}

BOOST_AUTO_TEST_CASE(CheckLookNoThrowAfterOpen)
{
    auto p = std::make_shared<Player>();
    auto p1 = std::make_shared<Player>();
    Card c = std::move(Stack().makeCard(p));
    c.open(p);
    BOOST_CHECK_EQUAL(Card::Sprade, c.look(p1).first);
    BOOST_CHECK_EQUAL(Card::D2, c.look(p1).second);
}

BOOST_AUTO_TEST_SUITE_END()