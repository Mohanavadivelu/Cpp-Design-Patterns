#include<iostream>
using namespace std;
namespace nm002
{
	class DB
	{

	public:
		virtual void Open() = 0;
		virtual void Close() = 0;
	};
	class NullDB :public DB
	{
	public:
		virtual void Open()
		{
			//do nothing
		}
		virtual void Close()
		{
			//do nothing
		}
	};
	class SqlDB :public DB
	{
	public:
		virtual void Open()
		{
			cout << "Sql Db Open " << endl;
		}
		virtual void Close()
		{
			cout << "Sql Db Close " << endl;
		}
	};
	class OracleDB :public DB
	{
	public:
		virtual void Open()
		{
			cout << "ORA Db Open " << endl;
		}
		virtual void Close()
		{
			cout << "ORA Db Close " << endl;
		}
	};


	class DBFactory
	{
	protected:
		virtual DB* BuildActualDb() = 0;
	public:

		DB* BuildDb()
		{
			cout << "DB common operation started " << endl;
			DB *db = BuildActualDb();
			cout << "DB common operation completed" << endl;
			return db;
		}
	};
	class SqlDBFactory :public DBFactory
	{
	protected:
		DB* BuildActualDb() override
		{
			cout << "SQL Build started " << endl;
			DB *db = new SqlDB();
			cout << "DB Build completed" << endl;
			return db;
		}
	};
	class OraDBFactory :public DBFactory
	{
	protected:
		DB* BuildActualDb() override
		{
			cout << "ORA Build started " << endl;
			DB *db = new OracleDB();
			cout << "ORA Build completed" << endl;
			return db;
		}
	};

	class DbManufacture
	{
	public:
		static DB* CreateDB()
		{
			//return NULL;
			//return new NullDB();//Reflection
			//return new SqlDB();
			//return new OracleDB();
			OraDBFactory fact;
			return fact.BuildDb();
		}
	};
	class Account
	{
	protected:
		Account()
		{
			this->db = DbManufacture::CreateDB();
		}
		DB *db;
		virtual void Debit() = 0;
	public:
		void Withdraw()
		{
			db->Open();
			this->Debit();
			db->Close();
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
		cout << "_____________________________" << endl;
		trans.PerformDebit(aAcct);
		cout << "_____________________________" << endl;
		trans.PerformDebit(bAcct);

	}
}