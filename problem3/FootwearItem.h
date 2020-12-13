#ifndef FOOTWEARITEM_H
#define FOOTWEARITEM_H

#include <string>

class FootwearItem {
public:
	// Constructor for an Footwear. All footwear items
	// will either be "Adidas", "Nike", "Fila" or "Skechers".
	FootwearItem(std::string brand);

	// A virtual method that composes a string with the details
	// of an Footwear. See the question paper and test files
	// for examples of the format for composeItem.
	virtual std::string composeItem() = 0;

	// Returns the dollar amount of a footwear item.
	virtual double getPrice() = 0;
protected:
	double price;
	std::string brand;
};

#endif