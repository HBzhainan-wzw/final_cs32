#ifndef GETCREATIVE_H
#define GETCREATIVE_H
#include "FootwearItem.h"
#include <map>


using namespace  std;

class GetCreative: public FootwearItem{
	public:
		GetCreative(string brand);
		virtual ~GetCreative();
		void addAccessory(string Accessory);
		virtual string composeItem();
		virtual double getPrice();
	private:
		map<string, int> Accessory;
		string brand;
		int price;

};



#endif