#include <algorithm>
#include "Rules.h"

namespace Rules {
	unsigned int getCombinationRank(std::vector <Card> const & cards, 
		std::shared_ptr<Player> const & player) {
		std::vector<size_t> values(Card::ACE + 1, 0);
		Card::Value highestCard = Card::NONE;
		for (auto & c : cards) {
			Card::Value curValue = c.look(player).second;
			if (++values[curValue - Card::D2] == 2) {
				highestCard = std::max(highestCard, curValue);
			}
		}
		
        return Rules::Pair | highestCard;
    }
}
