#include <iostream>
#include <string>

#include "FootwearOrder.h"
#include "PreMadeDeal.h"
#include "GetCreative.h"
#include "tddFuncs.h"

using namespace std;

int main() {
	cout << "Running tests from: " << __FILE__ << endl;

	FootwearOrder order1;

	PreMadeDeal* item1 = new PreMadeDeal("Nike Package", "Nike");
	order1.addItem(item1);
	GetCreative* item2 = new GetCreative("Nike");
	item2->addAccessory("socks");
	order1.addItem(item2);

	string expected = 
"PremadeDeal Brand: Nike\n\
Name: Nike Package\n\
Price: $40.00\n\
-----\n\
GetCreative Brand: Nike\n\
Accessories:\n\
socks: 1 quantity\n\
Price: $35.00\n\
-----\n\
Total: $75.00\n";

 	ASSERT_EQUALS(expected,order1.printBill());
 	delete item1;
 	delete item2;

 	FootwearOrder order2;
 	GetCreative* item3 = new GetCreative("Fila");
 	item3->addAccessory("socks");
 	item3->addAccessory("socks");
 	item3->addAccessory("socks");
 	order2.addItem(item3);
 	GetCreative* item4 = new GetCreative("Adidas");
 	item4->addAccessory("laces");
 	item4->addAccessory("laces");
 	item4->addAccessory("laces");
 	order2.addItem(item4);

 	expected =
"GetCreative Brand: Fila\n\
Accessories:\n\
socks: 1 quantity\n\
socks: 1 quantity\n\
socks: 1 quantity\n\
Price: $45.00\n\
-----\n\
GetCreative Brand: Adidas\n\
Accessories:\n\
laces: 3 quantity\n\
Price: $50.00\n\
-----\n\
Total: $95.00\n";

 	ASSERT_EQUALS(expected,order2.printBill());
 	delete item3;
 	delete item4;

	FootwearOrder order3;
	PreMadeDeal* item5 = new PreMadeDeal("Fila Package", "Fila");
	order3.addItem(item5);
	PreMadeDeal* item6 = new PreMadeDeal("Adidas Package", "Adidas");
	order3.addItem(item6);
	GetCreative* item7 = new GetCreative("Adidas");
	item7->addAccessory("shoe polish");
	item7->addAccessory("socks");
	item7->addAccessory("socks");
	order3.addItem(item7);

	expected = 
"PremadeDeal Brand: Fila\n\
Name: Fila Package\n\
Price: $40.00\n\
-----\n\
PremadeDeal Brand: Adidas\n\
Name: Adidas Package\n\
Price: $45.00\n\
-----\n\
GetCreative Brand: Adidas\n\
Accessories:\n\
shoe polish: 1 quantity\n\
socks: 2 quantity\n\
Price: $50.00\n\
-----\n\
Total: $135.00\n";

	ASSERT_EQUALS(expected,order3.printBill());
	delete item5;
	delete item6;
	delete item7;
}