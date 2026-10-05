#include<iostream>

// Decorator Pattern
// 装饰模式，就是已有对象已有功能添加新的功能，生成新的对象，不改变原有对象的结构。

class Drink {
public:
	Drink() {}
	virtual std::string GetName() = 0;
	virtual double GetPrice() = 0;
	virtual ~Drink() {}
};

class Coffee : public Drink
{
public:
	Coffee()
	{
		m_Name = "Coffee";
		m_Price = 5.0;
	}
	std::string GetName() override
	{
		return m_Name;
	}

	double GetPrice() override
	{
		return m_Price;
	}



private:
	std::string m_Name;
	double m_Price;
};


class IceDecorator :public Drink
{
public:
	IceDecorator(Drink* drink)
	{
		this->drink = drink;
	}
	std::string GetName() override
	{
		return drink->GetName() + " with Ice";
	}
	double GetPrice() override
	{
		return drink->GetPrice() + 1.0;
	}
private:
	Drink* drink = {};
};


class MilkDecorator :public Drink
{
public:
	MilkDecorator(Drink* drink)
	{
		this->drink = drink;
	}
	std::string GetName() override
	{
		return drink->GetName() + " with Milk";
	}
	double GetPrice() override
	{
		return drink->GetPrice() + 2.0;
	}	
private:
	Drink* drink = {};
};


int main() {
	Coffee coffee;
	std::cout << "Name: " << coffee.GetName() << std::endl;
	std::cout << "Price: " << coffee.GetPrice() << std::endl;

	IceDecorator iceCoffee(&coffee);
	std::cout << "Name: " << iceCoffee.GetName() << std::endl;
	std::cout << "Price: " << iceCoffee.GetPrice() << std::endl;

	MilkDecorator milkCoffee(&iceCoffee);
	std::cout << "Name: " << milkCoffee.GetName() << std::endl;
	std::cout << "Price: " << milkCoffee.GetPrice() << std::endl;
	return 0;
}