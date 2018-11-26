#include<iostream>
using namespace std;

namespace AbtsractFactory
{
	struct IAapter
	{
		virtual void FetchAdapter() = 0;
		virtual void UseAdapter() = 0;
	};
	
	struct ICommand
	{
		virtual void SetQuey() = 0;
		virtual void Execute() = 0;
	};
	struct IConnection
	{
		virtual void Open() = 0;
		virtual void Close() = 0;
	};
	struct IFactory
	{
		virtual IAapter* CreateAdapter() = 0;
		virtual ICommand* CreateCommand() = 0;
		virtual IConnection* CreateConnection() = 0;
	};
	//sql
	struct SqlAdapter :IAapter
	{
		void FetchAdapter() override
		{
			cout << "Sql Adapter handle fetched" << endl;
		}
		void UseAdapter() override
		{
			cout << "Sql Adapter Used" << endl;
		}
	};

	struct SqlCommand :ICommand
	{
		void SetQuey() override
		{
			cout << "Sql Query Set for Execution" << endl;
		}
		void Execute() override
		{
			cout << "Sql Db Engine  Executed" << endl;
		}
	};

	struct SqlConnection :IConnection
	{
		void Open() override
		{
			cout << "Sql connection openned" << endl;
		}
		void Close()override
		{
			cout << "Sql connection Closed" << endl;
		}
	};

	struct SqlFactory :IFactory
	{
		IAapter* CreateAdapter()
		{
			return new SqlAdapter();
		}
		ICommand* CreateCommand()
		{
			return new SqlCommand();
		}
		IConnection* CreateConnection()
		{
			return new SqlConnection();
		}
	};

	struct OraAdapter :IAapter
	{
		void FetchAdapter() override
		{
			cout << "Ora Adapter handle fetched" << endl;
		}
		void UseAdapter() override
		{
			cout << "Ora Adapter Used" << endl;
		}
	};

	struct OraCommand :ICommand
	{
		void SetQuey() override
		{
			cout << "Ora Query Set for Execution" << endl;
		}
		void Execute() override
		{
			cout << "Ora Db Engine  Executed" << endl;
		}
	};

	struct OraConnection :IConnection
	{
		void Open() override
		{
			cout << "Ora connection openned" << endl;
		}
		void Close()override
		{
			cout << "Ora connection Closed" << endl;
		}
	};

	struct OraFactory :IFactory
	{
		IAapter* CreateAdapter()
		{
			return new OraAdapter();
		}
		ICommand* CreateCommand()
		{
			return new OraCommand();
		}
		IConnection* CreateConnection()
		{
			return new OraConnection();
		}
	};

	void main()
	{
		IFactory *factory = new SqlFactory();
		IConnection *cnn = factory->CreateConnection();
		cnn->Open();
		IAapter *adp = factory->CreateAdapter();
		adp->FetchAdapter();
		adp->UseAdapter();
		ICommand *cmd = factory->CreateCommand();
		cmd->SetQuey();
		cmd->Execute();
		cnn->Close();
	}
}