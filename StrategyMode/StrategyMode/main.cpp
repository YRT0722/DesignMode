#include<iostream>

class PriceStrategy {
public:
	virtual void calculatePrice(int &nPrice) = 0;

};

void checkout(PriceStrategy* strategy, int& price)
{
	strategy->calculatePrice(price);
}

class NormalPrice :public PriceStrategy
{
public:
	void calculatePrice(int &nPrice) 
	{
		nPrice = nPrice;
		std::cout << "Normal price calculation: "<< nPrice << std::endl;
	}
};

class DiscountPrice :public PriceStrategy 
{
public:
	void calculatePrice(int &nPrice) {
		nPrice = nPrice * 0.8;
		std::cout << "Discount price calculation: " << nPrice<< std::endl;
	}
};

class FullReductionPrice : public PriceStrategy
{
public:
	void calculatePrice(int& nPrice)
	{
		nPrice >= 300 ? nPrice=nPrice - 100 : nPrice= nPrice;
		std::cout << "Discount price calculation: " << nPrice << std::endl;
	}
};


int main() 
{
	int nPrice = 100;
	class NormalPrice priceStrategy1;
	checkout(&priceStrategy1, nPrice);

	nPrice = 100;
	class DiscountPrice priceStrategy2;
	checkout(&priceStrategy2, nPrice);

	nPrice = 300;
	class FullReductionPrice priceStrategy3;
	checkout(&priceStrategy3, nPrice);

	return 0;
}