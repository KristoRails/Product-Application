#include <iostream>
#include <fstream>
#include <vector>
#include <regex> // new library, ask

//headers
#include "PerishableProduct.h"
#include "NonperishableProduct.h"
using namespace std;

bool isDate(const string& date)
{
	//what is regex
	return regex_match(date, regex(R"(\d\d\d\d-\d\d-\d\d)"));
}

NonperishableProduct::Type ProductType(const string& productType)
{
	if (productType == "Clothing")
		return NonperishableProduct::Type::Clothing;
	else if (productType == "SmallAppliances")
		return NonperishableProduct::Type::SmallAppliances;
	else if (productType == "PersonalHygiene")
		return NonperishableProduct::Type::PersonalHygiene;
	
}


int main()
{
	vector<IPriceable*> listPriceables;
	int32_t id;
	string name;
	float rawPrice;
	int32_t vat;
	string dateOrType;

	for (ifstream read("product.prodb"); !read.eof();)
	{
		read >> id >> name >> rawPrice >> vat >> dateOrType;

		//create object based on date or type
		if (isDate(dateOrType))
			listPriceables.push_back(new PerishableProduct(id, name, rawPrice, dateOrType));
		else
			listPriceables.push_back(new NonperishableProduct(id, name, rawPrice, ProductType(dateOrType)));
	}

	//auto sets the type without personal input
	//ask what the code down below does

	auto nameComparator = [](const IPriceable* left, IPriceable* right)
	{
		return dynamic_cast<const Product*>(left)->GetName() < dynamic_cast<const Product*>(right)->GetName();
	};
	auto priceComparator = [](const IPriceable* left, IPriceable* right)
	{
		return left->GetPrice() < right->GetPrice();
	};

	//sort function
	sort(listPriceables.begin(), listPriceables.end(), priceComparator);

	//print (ask)
	for (auto priceable : listPriceables)
	{
		auto perishableProduct = dynamic_cast<NonperishableProduct*>(priceable);
		if (perishableProduct != nullptr)
			cout << *perishableProduct << endl;
	}
	
	//clean up (ask)
	for (auto priceable : listPriceables)
		delete priceable;

	system("pause");
	return 0;
}