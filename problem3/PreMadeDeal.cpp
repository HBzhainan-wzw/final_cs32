#include "PreMadeDeal.h"
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

PreMadeDeal::PreMadeDeal(string name, string brand): FootwearItem(brand){
    this->name = name;
    this->brand = brand;
    if(brand == "Adidas"){
        price = 45.00;
    }
    if(brand == "Nike"){
        price = 40.00;
    }
    if(brand == "Fila"){
        price = 40.0;
    }
    if(brand == "Skechers"){
        price = 35.00;
    }
}

PreMadeDeal::~PreMadeDeal(){}

string PreMadeDeal::composeItem(){
	string output = "";
	output+= "PremadeDeal Brand: ";
	output+= this->brand;
    output+= "\nName: ";
    output+= this->name;
    output+= "\n";
	output+="Price: $";
	stringstream ss;
	ss << fixed << setprecision(2) << this->getPrice();
	output+= ss.str();
	output+="\n";
	return output;


}
double PreMadeDeal::getPrice(){
    return this->price;
}