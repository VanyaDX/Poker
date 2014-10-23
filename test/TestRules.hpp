#include <boost/test/unit_test.hpp>
#include "Rules.h"
#include "Exceptions.h"


BOOST_AUTO_TEST_SUITE(TestCard)


BOOST_AUTO_TEST_CASE(TestOnePair)
{
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D2)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Club, Card::D2)));
	BOOST_CHECK_EQUAL(Rules::Pair, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_CASE(TestTwoPair)
{
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D2)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Club, Card::D2)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D3)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Club, Card::D3)));
	BOOST_CHECK_EQUAL(Rules::TwoPairs, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_SUITE_END()