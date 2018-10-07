#pragma once
#include "Product.h"
class PerishableProduct : public Product
{
private:
	string m_expirationDate;
	static const int32_t vat = 7; //since GetVat is of type int32_t

public:
	//constructor
	PerishableProduct(int32_t id, string name, float rawPrice, string expirationDate);

	//Get functions
	string GetExpirationDate() const;

	//Inherited
	int32_t GetVat() const override;
	float GetPrice() const override;
};

