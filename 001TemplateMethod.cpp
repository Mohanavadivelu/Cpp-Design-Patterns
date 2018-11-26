#include<iostream>
using namespace std;

/*
Template Method is used, when a set of algorithm steps are common between subclasses and deferring steps are implemented in subclasses.
without changing the algorithm step;

For example, A bank client may have more the one bank account type (Saving, current, credit ..), and he want to withdraw the amount.   
With the above scenario all account type transaction, first connect to Database, check the account exist, perform the deposit and close Database 

In this "opening" and "close" the Database is common. where are "deposit" may differ based on the table the data stored or SQL query.

For the above problem, Template Method helps to put the command operation in to template method and lets the "deposit" implementation 
in to subclasses. 

*/

namespace TemplateMethod
{
	class DB
	{

	public:
		void Open()
		{
			cout << "open DB" << endl;
		}
		void Close()
		{
			cout << "close DB" << endl;
		}
	};
	class Account
	{
	protected:
		DB db;
		virtual void Debit() = 0;
	public:
		void Withdraw()
		{
			db.Open();
			this->Debit();
			db.Close();
		}
	};

	class SavingsAccount :public Account
	{

	protected:
		void Debit() override
		{
			cout << "Savings Account Withdraw job done" << endl;
		}
	};

	class CurrentAccount :public Account
	{

	protected:
		void Debit() override
		{
			cout << "Current Account Withdraw job done" << endl;
		}
	};

	class TransactionHelper
	{
	public:
		void PerformDebit(Account &acc)
		{
			cout << "transaction started " << endl;
			acc.Withdraw();
			cout << "transaction completed " << endl;
		}

	};

	void main()
	{
		SavingsAccount aAcct;
		CurrentAccount bAcct;
		TransactionHelper trans;
		trans.PerformDebit(aAcct);
		cout << "_____________________________" << endl;
		trans.PerformDebit(bAcct);

	}
}


/*

transaction started 
open DB
Savings Account Withdraw job done
close DB
transaction completed 
_____________________________
transaction started 
open DB
Current Account Withdraw job done
close DB
transaction completed 

*/