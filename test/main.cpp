#define BOOST_TEST_MAIN 1
#include <boost/test/unit_test.hpp>
using namespace boost::unit_test;

#define BOOST_TEST_MODULE TestPoker

#include "TestCard.hpp"

BOOST_AUTO_TEST_SUITE(TestEnvironment)

BOOST_AUTO_TEST_CASE(test_success)
{
    BOOST_CHECK( true );
}

BOOST_AUTO_TEST_SUITE_END()