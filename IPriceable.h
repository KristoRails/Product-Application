#pragma once
#include<cstdint>
#include<string>
using namespace std;

class IPriceable
{
public:
	virtual int32_t GetVat() const = 0;
	virtual float GetPrice() const = 0;
};

