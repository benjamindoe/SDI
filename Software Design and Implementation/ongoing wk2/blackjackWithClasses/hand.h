#ifndef SDI_HAND_H
#define SDI_HAND_H

#include <vector>

#include "card.h"

namespace SDI_REVIEW
{
	class Hand
	{
	private:
		std::vector<Card> theHand_;
	public:
		Hand();
		void addCard();
		std::string toString();
		int currentHandSize();
		int currentHandTotal();
	};

}  //namespace
#endif