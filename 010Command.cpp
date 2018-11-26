#include<iostream>
#include<stack>
using namespace std;


namespace nm10
{
	class Account
	{
		int id;
		int amount;
	public:
		int getBalance()
		{
			return amount;
		}
		void Withdraw(int amt)
		{
			this->amount -= amt;
		}
		void Deposit(int amt)
		{
			this->amount += amt;
		}
		Account(int id, int amt) :id(id), amount(amt)
		{
		}

	};

	class Command
	{
	public:
		virtual void Execute(Account &acc) = 0;
		virtual void UnExecute(Account &acc) = 0;
	};
	class WithdrawCommand :public Command
	{
		int amt;
	public:
		WithdrawCommand(int amt) :amt(amt)
		{
		}
		void Execute(Account &acc)
		{
			acc.Withdraw(amt);
		}
		void UnExecute(Account &acc)
		{
			acc.Deposit(amt);
		}
	};

	class DepositCommand :public Command
	{
		int amt;
	public:
		DepositCommand(int amt) :amt(amt)
		{
		}
		void Execute(Account &acc)
		{
			acc.Deposit(amt);
		}
		void UnExecute(Account &acc)
		{
			acc.Withdraw(amt);
		}
	};
	class TransactionHelper
	{
		Account &acc;
		stack<Command*> repo;
	public:
		TransactionHelper(Account &acc) :acc(acc)
		{
		}
		void Debit(int amt)
		{
			Command *cmd = new WithdrawCommand(amt);
			repo.push(cmd);
			cmd->Execute(acc);
		}
		void Credit(int amt)
		{
			Command *cmd = new DepositCommand(amt);
			repo.push(cmd);
			cmd->Execute(acc);
		}
		int RetrieveBalance()
		{
			return acc.getBalance();
		}
		void Undo()
		{
			Command *cmd = repo.top();
			repo.pop();
			cmd->UnExecute(acc);
		}

	};

	void main()
	{
		Account acc(101, 50000);
		TransactionHelper trans(acc);

		trans.Credit(10000);
		trans.Credit(20000);
		trans.Debit(20000);
		trans.Credit(50000);
		trans.Debit(10000);
		trans.Undo();
		trans.Undo();
		trans.Undo();
		trans.Undo();
		trans.Undo();

		cout << "Balance is " << trans.RetrieveBalance() << endl;
	}
}