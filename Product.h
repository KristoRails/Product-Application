#pragma once
#include "IPriceable.h"
class Product : public IPriceable
{

protected:
	int32_t m_id;
	string m_name;
	float m_rawPrice;
public:
	//constructor
	Product(int32_t id, string name, float rawPrice);
	
	//Get functions
	int32_t GetID() const;
	string GetName() const;
	float GetRawPrice() const;

};

