#ifndef _H_RULES_
#define _H_RULES_

#include <memory>
#include <vector>
#include "Card.h"

/// Useful functions to implement poker rules
namespace Rules {

    unsigned int getCombinationRank(std::vector<Card> const & cards);

}


#endif //_H_RULES_