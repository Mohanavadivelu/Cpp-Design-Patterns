#include<iostream>
#include<string>
using namespace std;


namespace nm004 {
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

	class ISMSProvider
	{
	public:
		virtual void Dispatch(string msg) = 0;
	};
	class BSNL :public ISMSProvider
	{
	public:
		void Dispatch(string msg) override
		{
			cout << "BSNL SMS Sent " << msg << endl;
		}
	};

	class Verizon :public ISMSProvider
	{
	public:
		void Dispatch(string msg) override
		{
			cout << "Verizon SMS Sent " << msg << endl;
		}
	};

	class SMS
	{
		static ISMSProvider *provider;
	public:
		static void SetProvider(ISMSProvider *prov)
		{
			provider = prov;
		}
		static void SendSms(string msg)
		{
			provider->Dispatch(msg);
		}
	};
	ISMSProvider *SMS::provider;

	class Account
	{
	protected:
		DB db;
		virtual void Debit() = 0;
		virtual string GetMsg() = 0;
		string smsMsg = "";
	public:
		void Withdraw()
		{
			db.Open();
			this->Debit();
			string msg = GetMsg();
			SMS::SendSms(msg);
			db.Close();
		}
	};


	class SavingsAccount :public Account
	{

	protected:
		string GetMsg()
		{
			return smsMsg;
		}
		void Debit() override
		{
			cout << "Savings Account Withdraw job done" << endl;
			smsMsg = "Savings Info";
		}
	};

	class CurrentAccount :public Account
	{

	protected:
		string GetMsg()
		{
			return smsMsg;
		}
		void Debit() override
		{
			cout << "Current Account Withdraw job done" << endl;
			smsMsg = "Current Info";
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
		SMS::SetProvider(new Verizon());
		SavingsAccount aAcct;
		CurrentAccount bAcct;
		TransactionHelper trans;
		trans.PerformDebit(aAcct);
		cout << "_____________________________" << endl;
		trans.PerformDebit(bAcct);

	}
}