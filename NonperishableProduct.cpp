#include "NonperishableProduct.h"

NonperishableProduct::NonperishableProduct(int32_t id, string name, float rawPrice, Type type) :
	Product(id, name, rawPrice), m_type(type)
{
	//member initializer
}

int32_t NonperishableProduct::GetVat() const
{
	return vat;
}

float NonperishableProduct::GetPrice() const
{
	return m_rawPrice + m_rawPrice * vat / 100;
}


ostream & operator<<(ostream & os, const NonperishableProduct & prod)
{
	//Note to self: Operator needed to display information
	os << prod.GetID() << ' ' << prod.GetName() << ' ' << prod.GetPrice();
	return os;
}
