#include "PerishableProduct.h"

PerishableProduct::PerishableProduct(int32_t id, string name, float rawPrice, string expirationDate) :
	Product(id, name, rawPrice), m_expirationDate(expirationDate)
{
	//member initializer
}

string PerishableProduct::GetExpirationDate() const
{
	return m_expirationDate;
}

int32_t PerishableProduct::GetVat() const
{
	return vat;
}

float PerishableProduct::GetPrice() const
{
	return m_rawPrice + m_rawPrice * GetVat() / 100;
}
