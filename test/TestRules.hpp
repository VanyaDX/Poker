#include <boost/test/unit_test.hpp>
#include "Rules.h"
#include "Exceptions.h"


BOOST_AUTO_TEST_SUITE(TestRules)


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

BOOST_AUTO_TEST_CASE(TestSet)
{
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D2)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Club, Card::D2)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::D2)));
	BOOST_CHECK_EQUAL(Rules::Set, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_CASE(TestStraight)
{
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D2)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Club, Card::D3)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::D4)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D5)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::D6)));
	BOOST_CHECK_EQUAL(Rules::Straight, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_CASE(TestLowestStraight)
{
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D2)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Club, Card::D3)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::D4)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D5)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::ACE)));
	BOOST_CHECK_EQUAL(Rules::Straight, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_CASE(TestHighestStraight)
{
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::ACE)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Club, Card::KING)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::QUEEN)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::KNAVE)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::D10)));
	BOOST_CHECK_EQUAL(Rules::Straight, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_CASE(TestFlush)
{
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::ACE)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::KING)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::QUEEN)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::KNAVE)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D2)));
	BOOST_CHECK_EQUAL(Rules::Flush, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_CASE(TestStraightFlush)
{
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::ACE)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::KING)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::QUEEN)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::KNAVE)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::D10)));
	BOOST_CHECK_EQUAL(Rules::StraightFlush, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_CASE(TestFullHouse) {
	std::vector<Card> cards;
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::ACE)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::ACE)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::QUEEN)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Diamond, Card::QUEEN)));
	cards.emplace_back(std::move(Stack::makeCard(Card::Heart, Card::QUEEN)));
	BOOST_CHECK_EQUAL(Rules::FullHouse, Rules::getCombinationRank(cards) & 0xFF000000);
}

BOOST_AUTO_TEST_SUITE_END()