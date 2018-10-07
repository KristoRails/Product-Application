#include "Product.h"


Product::Product(int32_t id, string name, float rawPrice) :
	m_id(id), m_name(name), m_rawPrice(rawPrice)
{
	//member initializer
}

int32_t Product::GetID() const
{
	return m_id;
}

string Product::GetName() const
{
	return m_name;
}

float Product::GetRawPrice() const
{
	return m_rawPrice;
}
