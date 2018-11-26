#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm015
{
	class CareTaker;
	class Momento
	{
	public:
		string Name;
		virtual ~Momento()
		{
		}
	};
	class EmpMomento :public Momento
	{
	public:
		string _dept;
	};
	class ProdMomento :public Momento
	{
	public:
		string type;
	};

	class IStore
	{
	protected:
		CareTaker *taker;
	public:
		void SetCaretaker(CareTaker *taker)
		{
			this->taker = taker;
		}
		virtual void Hyderate() = 0;
		virtual void DeHyderate() = 0;

	};

	class CareTaker
	{
		map<IStore*, Momento*> repo;
	public:
		void SetMomento(IStore *key, Momento *value)
		{
			repo[key] = value;
		}
		Momento* GetMomento(IStore *key)
		{
			Momento *temp = repo[key];
			repo.erase(key);
			return temp;
		}
	};

	class Employee :public IStore
	{
	public:
		int _eid;
		string _name;
		string _dept;

		Employee(int eid, string name, string dept) :_name(name), _eid(eid), _dept(dept)
		{
		}
		virtual void Hyderate()
		{
			EmpMomento *em = new EmpMomento();
			em->Name = this->_name;
			em->_dept = this->_dept;
			taker->SetMomento(this, em);
		}
		virtual void DeHyderate()
		{
			EmpMomento *em = dynamic_cast<EmpMomento*>(taker->GetMomento(this));
			this->_name = em->Name;
			this->_dept = em->_dept;
			delete em;
		}
		void Display()
		{
			cout << "ID      : " << _eid << endl;
			cout << "Name    : " << _name << endl;
			cout << "Dept    : " << _dept << endl;
			cout << "_______________________" << endl;
		}
	};

	class Product :public IStore
	{
	public:
		int pId;
		string Name;
		string type;

		Product(int pId, string name, string type) :pId(pId), Name(name), type(type)
		{
		}
		virtual void Hyderate()
		{
			ProdMomento *prod = new ProdMomento();
			prod->Name = this->Name;
			prod->type = this->type;
			taker->SetMomento(this, prod);
		}
		virtual void DeHyderate()
		{
			ProdMomento *prod = dynamic_cast<ProdMomento*>(taker->GetMomento(this));
			this->Name = prod->Name;
			this->type = prod->type;
			delete prod;
		}
		void Display()
		{
			cout << "ID      : " << pId << endl;
			cout << "Name    : " << Name << endl;
			cout << "type    : " << type << endl;
			cout << "_______________________" << endl;
		}
	};

	void main()
	{
		CareTaker taker1;
		//CareTaker taker2;
		Employee emp(101, "sachin", "batsman");
		emp.SetCaretaker(&taker1);
		Product prod(111, "Eye Comb", "Cosmetics");
		prod.SetCaretaker(&taker1);
		//-------------
		emp.Hyderate();
		prod.Hyderate();
		//------------
		emp.Display();
		prod.Display();
		prod.Name = "Cheek Color";
		emp._name = "tendulkar";
		emp.Display();
		prod.Display();
		emp.DeHyderate();
		prod.DeHyderate();
		emp.Display();
		prod.Display();
	}
}