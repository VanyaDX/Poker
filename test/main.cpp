#define BOOST_TEST_MAIN 1
#include <boost/test/unit_test.hpp>
#include "Card.h"
using namespace boost::unit_test;

#define BOOST_TEST_MODULE TestPoker

class Stack {
public:
	static Card makeCard(Card::Suit suit, Card::Value value) {
		auto p1 = std::make_shared<Player>();
		Card card(value, suit);
		card.setOwner(p1);
		card.open(p1);
		return std::move(card);
	}

	Card makeCard() {
		Card card(Card::D2, Card::Sprade);
		return std::move(card);
	}

	Card makeCard(std::shared_ptr<Player> const & player) {
		Card card(Card::D2, Card::Sprade);
		card.setOwner(player);
		return std::move(card);
	}
};


#include "TestCard.hpp"
#include "TestRules.hpp"

BOOST_AUTO_TEST_SUITE(TestEnvironment)

BOOST_AUTO_TEST_CASE(test_success)
{
    BOOST_CHECK( true );
}

BOOST_AUTO_TEST_SUITE_END()