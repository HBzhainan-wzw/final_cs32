#include "GetCreative.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

GetCreative::GetCreative(string brand): FootwearItem(brand){
    this->brand = brand;
    if(brand == "Adidas"){
        price = 35.00;
    }
    if(brand == "Nike"){
        price = 30.00;
    }
    if(brand == "Fila"){
        price = 30.0;
    }
    if(brand == "Skechers"){
        price = 25.00;
    }

}

GetCreative::~GetCreative(){}


void GetCreative::addAccessory(std::string Accessory){
	if(this->Accessory.find(Accessory) != this->Accessory.end()){
		this->Accessory[Accessory]++;
	}else
	{
        this->Accessory[Accessory] = 1;
	}
	this->price += 5;
}
string GetCreative::composeItem(){
	string output = "";
	output+= "GetCreative Brand:";
	output+= this->brand;
	output+= "\nAccessories:\n";
	for(map<string, int>::iterator i = this->Accessory.begin();i!= this->Accessory.end();i++){
		output+= i->first;
		output+= ": ";
		output+= to_string(i->second);
		output+= " quantity\n";
	}
	output+="Price: $";
	stringstream ss;
	ss << fixed << setprecision(2) << this->getPrice();
	output+= ss.str();
	output+="\n";
	return output;
}

double GetCreative::getPrice(){
	return this->price;
}