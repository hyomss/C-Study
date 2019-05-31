//	information hiding & const
#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples == num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult()
	{
		cout << "Remaining Apples : " << numOfApples << endl;
		cout << "Sales Revenue : " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numofApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numofApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		if (money < 0)
		{
			cout << "You should give more than $0" << endl;
			return;
		}
		numofApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult()
	{
		cout << "Current Balance : " << myMoney << endl;
		cout << "Number of Apples : " << numofApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 0, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, -1);	//	fail purchase
	cout << "Current state of the Seller : " << endl;
	seller.ShowSalesResult();
	cout << "Current state of the Buyer : " << endl;
	buyer.ShowBuyResult();

		
	buyer.BuyApples(seller, 2000);	//	success purchase
	cout << "Current state of the Seller : " << endl;
	seller.ShowSalesResult();
	cout << "Current state of the Buyer : " << endl;
	buyer.ShowBuyResult();
	return 0;
}