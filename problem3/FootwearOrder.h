#ifndef FOOTWEARORDER_H
#define FOOTWEARORDER_H

#include <vector>
#include <string>
#include "FootwearItem.h"

class FootwearOrder {
public:
	std::string printBill() const;
	void addItem(FootwearItem* item);
private:
	std::vector<FootwearItem*> items;
};

#endif
