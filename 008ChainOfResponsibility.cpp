#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm008
{
	//typedef bool(*FPTR)();
	using FPTR = bool(*)(int);
	class Criteria
	{
	public:
		static map<string, FPTR> repository;
		static void RegisterCriteria(string key, FPTR fp)
		{
			repository[key] = fp;
		}
		static bool GetCriteria(string key, int amount)
		{
			FPTR fp = repository[key];
			return fp(amount);
		}
	};
	map<string, FPTR> Criteria::repository;

	class Approver
	{
	protected:
		string name;
		Approver *successor;
		Approver(string name) :successor(NULL), name(name)
		{
		}
	public:
		void SetSuccessor(Approver *successor)
		{
			this->successor = successor;
		}
		bool Validate(int amount)
		{
			return Criteria::GetCriteria(typeid(*this).name(), amount);
		}
		void MoveToSucessor(int amount)
		{
			if (this->successor != NULL)
				this->successor->ProcessLoan(amount);
		}
		virtual void ProcessLoan(int amount) = 0;

	};
	class Cashier :public Approver
	{
	public:
		Cashier(string name) :Approver(name)
		{
		}
		void ProcessLoan(int amount)
		{
			if (Validate(amount))
			{
				cout << "Cahier " << name << " processed loan of " << amount << endl;
			}
			else
			{
				cout << "Cahier " << name << " Cannot process this loan of " << amount << endl;
				MoveToSucessor(amount);
			}
		}
	};

	class Manager :public Approver {
	public:
		Manager(string name) :Approver(name)
		{
		}
		void ProcessLoan(int amount)
		{
			if (Validate(amount))
			{
				cout << "Manager " << name << " processed loan of " << amount << endl;
			}
			else
			{
				cout << "Manager " << name << " Cannot process this loan of " << amount << endl;
				MoveToSucessor(amount);
			}
		}
	};

	class Director :public Approver {
	public:
		Director(string name) :Approver(name)
		{
		}
		void ProcessLoan(int amount)
		{
			if (Validate(amount))
			{
				cout << "Director " << name << " processed loan of " << amount << endl;
			}
			else
			{
				cout << "Director " << name << " Cannot process this loan of " << amount << endl;
				MoveToSucessor(amount);
			}
		}
	};

	void main()
	{
		Criteria::RegisterCriteria(typeid(Cashier).name(), [](int amt) {return amt <=  100000; });
		Criteria::RegisterCriteria(typeid(Manager).name(), [](int amt) {return amt <= 200000; });
		Criteria::RegisterCriteria(typeid(Director).name(), [](int amt) {return amt <= 300000; });
		Cashier John("John");
		Manager James("James");
		Director Tom("Tom");


		John.SetSuccessor(&James);
		James.SetSuccessor(&Tom);

		John.ProcessLoan(250000);

	}
}