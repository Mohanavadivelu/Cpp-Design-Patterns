#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm017
{
	class RBI
	{
	public:
		void SendInfo(string msg)
		{
			cout << "RBI recieved info " << msg << endl;
		}
	};

	class IncomeTax
	{
	public:
		void TaxInfo(string msg)
		{
			cout << "Income Tax  recieved info " << msg << endl;
		}
	};

	class ServiceTax
	{
	public:
		void TaxMessage(string msg)
		{
			cout << "Service Tax  recieved msg " << msg << endl;
		}
	};

	class CommercialTax
	{
	public:
		void TaxMessage(string msg)
		{
			cout << "Commercial Tax  recieved msg " << msg << endl;
		}
	};


	class FlowHelper
	{
		RBI rbi;
		IncomeTax it;
		ServiceTax st;
		CommercialTax ct;
	public:
		void SbAccount(string msg)
		{
			rbi.SendInfo(msg);
			it.TaxInfo(msg);

		}
		void CurrentAccount(string msg)
		{
			rbi.SendInfo(msg);
			it.TaxInfo(msg);
			st.TaxMessage(msg);
			ct.TaxMessage(msg);
		}
	};

	void main()
	{
		FlowHelper flow;

		flow.SbAccount("Amount deducted is 40000 for customer 101");
		cout << "__________________________________________" << endl;
		flow.CurrentAccount("506 deposited 5000000");
	}
}