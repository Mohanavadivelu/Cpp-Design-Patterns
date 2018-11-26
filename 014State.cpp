#include<iostream>
#include<string>
using namespace std;
namespace nm014
{
	class CardHolder
	{
	protected:
		string type;
		CardHolder(string type) :type(type)
		{
		}
	public:
		virtual void Facilities() = 0;
	};
	class GoldCard :public CardHolder
	{
	public:
		GoldCard() :CardHolder("Gold")
		{
		}
		void Facilities()
		{
			cout << "You are a " << type << " member" << endl;
			cout << "Avail loan without documents" << endl;
			cout << "Use this for fuel @ 2% discount" << endl;
			cout << "Use this card for shopping upto 5000 and get 50rs." << endl;
			cout << "_______________________________________________________" << endl;
		}
	};

	class SilverCard :public CardHolder
	{
	public:
		SilverCard() :CardHolder("Silver")
		{
		}
		void Facilities()
		{
			cout << "You are a " << type << " member" << endl;
			cout << "Avail loan with minimum documents" << endl;
			cout << "Use this for fuel @ 1% discount" << endl;
			cout << "Use this card for shopping upto 2000 and get 10rs." << endl;
			cout << "_______________________________________________________" << endl;
		}
	};

	class NormalCard :public CardHolder
	{
	public:
		NormalCard() :CardHolder("Normal")
		{
		}
		void Facilities()
		{
			cout << "You are a " << type << " member" << endl;
			cout << "loan not allowed" << endl;
			cout << "Use this for fuel please" << endl;
			cout << "Use this card for every shopping and get 2rs off " << endl;
			cout << "_______________________________________________________" << endl;
		}
	};

	class CardFactory
	{
	public:
		static CardHolder* CreateCard(int amount)
		{
			if (amount > 50000)
			{
				return new GoldCard();
			}
			else if (amount > 30000)
			{
				return new SilverCard();
			}
			else
			{
				return new NormalCard();
			}
		}
	};

	class Account
	{
		int id;
		int amount;
		CardHolder *card;
	public:
		int getBalance()
		{

			return amount;
		}
		void Withdraw(int amt)
		{
			this->amount -= amt;
			CheckState();
		}
		void Deposit(int amt)
		{
			this->amount += amt;
			CheckState();
		}
		void CheckState()
		{
			card = CardFactory::CreateCard(this->amount);
			card->Facilities();
		}
		Account(int id, int amt) :id(id), amount(amt), card(CardFactory::CreateCard(amount))
		{

		}

	};


	void main()
	{
		Account acc(101, 2000);
		acc.Deposit(10000);
		acc.Deposit(50000);
		acc.Withdraw(20000);
		cout << "Balance is " << acc.getBalance() << endl;
	}
}