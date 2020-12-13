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
		string composeItem();
		double getPrice();
	private:
		int hasAccessory(string Accessory);
		map<string, int> Accessory;

};



#endif