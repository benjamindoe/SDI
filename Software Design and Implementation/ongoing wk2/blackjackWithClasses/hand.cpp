#ifndef SDI_HAND_CPP
#define SDI_HAND_CPP


#include <string>
#include <cassert>
#include <vector>
#include <iostream>

#include "hand.h"

namespace SDI_REVIEW
{
	Hand::Hand() {

	}

	std::string Hand::toString() {
		std::string result;
		if (theHand_.size() > 0) {
			for (int i = 0; i < theHand_.size(); i++) {
				result += theHand_[i].toString() + "\n";
			}
		}
		else {
			result = "No cards in hand.";
		}
		return result;

	}

	int Hand::currentHandSize() {
		return theHand_.size();
	}

	int Hand::currentHandTotal() {
		int total;
		int i = 0;
		do {
			total += theHand_[i].toString
			i++;
		} while (currentHandSize() < )
	}
	void Hand::addCard() {

	}
}  //namespace
#endif