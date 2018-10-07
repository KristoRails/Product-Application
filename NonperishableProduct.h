#pragma once
#include "Product.h"
class NonperishableProduct : public Product
{
public:
	enum class Type
	{
		Clothing, SmallAppliances, PersonalHygiene
	};
private:
	Type m_type;
	static const int32_t vat = 19;

public:
	NonperishableProduct(int32_t id, string name, float rawPrice, Type type);
	
	//Inherited from Product
	int32_t GetVat() const override;
	float GetPrice() const override;

	friend ostream& operator<<(ostream& os, const NonperishableProduct& prod);
	
};

