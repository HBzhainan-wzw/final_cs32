#ifndef PREMADEDEAL_H
#define PREMADEDEAL_H
#include "FootwearItem.h"
using namespace std;

class PreMadeDeal: public FootwearItem{
    public:
        PreMadeDeal(string name, string brand);
        virtual ~PreMadeDeal ();
		virtual string composeItem();
		virtual double getPrice();
    private:
        string name;
        string brand;
        int price;
};





#endif