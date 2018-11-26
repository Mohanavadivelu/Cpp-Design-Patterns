#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm009
{
	class SA;
	class CA;
	class Dmat;
	class Account;
	class IUI
	{
	public:
		virtual void ShowUI(SA*) = 0;
		virtual void ShowUI(CA*) = 0;
		virtual void ShowUI(Dmat*) = 0;
		virtual void ShowUI(Account*) = 0;
	};

	class Account
	{
	protected:
		static IUI* ui;
	public:
		static void SetUI(IUI* uiPar)
		{
			ui = uiPar;
		}
		virtual void Business() = 0;
	};
	IUI* Account::ui = NULL;

	class SA :public Account
	{
	public:
		void Business()
		{
			cout << "SA Job started " << endl;
			ui->ShowUI(this);//showUi
			cout << "SA Job completed " << endl;
			cout << "_______________________________" << endl;
		}
	};
	class CA :public Account
	{
	public:
		void Business()
		{
			cout << "Current Job started " << endl;
			ui->ShowUI(this);//showUi
			cout << "Current Job completed " << endl;
			cout << "_______________________________" << endl;
		}
	};
	class Dmat :public Account
	{
	public:
		void Business()
		{
			cout << "Dmat Job started " << endl;
			ui->ShowUI(this);//showUi
			cout << "Dmat Job completed " << endl;
			cout << "_______________________________" << endl;
		}
	};


	class Child :public Account
	{
	public:
		void Business()
		{
			cout << "Child Job started " << endl;
			ui->ShowUI(this);//showUi
			cout << "Child Job completed " << endl;
			cout << "_______________________________" << endl;
		}
	};
	//-------------------------
	class ChristmasUI :public IUI
	{
	public:
		void ShowUI(SA*)
		{
			cout << "Christmas UI for Savings" << endl;
		}
		void ShowUI(CA*)
		{
			cout << "Christmas UI for Current" << endl;
		}
		void ShowUI(Dmat*)
		{
			cout << "Christmas UI for DMat" << endl;
		}
		void ShowUI(Account*)
		{
			cout << "Christmas UI for General" << endl;
		}
	};
	//DEEBAWALI
	//Deepavali

	class DeewaliUI :public IUI
	{
	public:
		void ShowUI(SA*)
		{
			cout << "Deewali UI for Savings" << endl;
		}
		void ShowUI(CA*)
		{
			cout << "Deewali UI for Current" << endl;
		}
		void ShowUI(Dmat*)
		{
			cout << "Deewali UI for DMat" << endl;
		}
		void ShowUI(Account*)
		{
			cout << "Deewali UI for General" << endl;
		}
	};

	void main()
	{
		Account::SetUI(new DeewaliUI());

		SA sa;
		CA ca;
		Dmat dm;
		Child child;

		child.Business();
		sa.Business();
		ca.Business();
		dm.Business();
	}
}