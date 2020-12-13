#include "FootwearItem.h"

using namespace std;

FootwearItem::FootwearItem(string brand){
	this->brand = brand;
	price = 0;

}

double FootwearItem::getPrice(){
	return this->price;
}