#include<iostream>
#include<string>
#include<map>
using namespace std;
class Dummy
{
};

class Employee
{
	static map<int, Employee*> repo;
protected:
	int eId;
	string _name;
	Employee(int id, string nm) :_name(nm), eId(id)
	{
	}
	Employee(Dummy&,int key) 
	{
		repo[key] = this;
	}
public:
	virtual Employee* Clone() = 0;
	virtual void DoJob() = 0;
	static Employee* CreateEmp(int key)
	{
		return repo[key]->Clone();
	}
};
map<int, Employee*> Employee::repo;

class Manager :public Employee
{
	string ProjectId;
public:
	Manager(Dummy& dum,int key) :Employee(dum,key)
	{
		eId = 103;
		_name = "saurav";
		ProjectId = "12345";
	}
	Manager(int id, string nm,string pId):ProjectId(pId),Employee(id,nm)
	{
	}
	Employee* Clone()
	{
		return new Manager(eId, _name, ProjectId);
	}
	void DoJob()
	{
		cout << "Manager" << endl;
		cout << "Id   : " << eId << endl;
		cout << "Name : " << _name << endl;
		cout << "Proj : " << ProjectId << endl;
	}
};

class Tester :public Employee
{
	string ProjectId;
public:
	Tester(Dummy& dum, int key) :Employee(dum, key)
	{
		eId = 102;
		_name = "rahul";
		ProjectId = "1234";
	}
	Tester(int id, string nm, string pId) :ProjectId(pId), Employee(id, nm)
	{
	}
	Employee* Clone()
	{
		return new Tester(eId, _name, ProjectId);
	}
	void DoJob()
	{
		cout << "Tester" << endl;
		cout << "Id   : " << eId << endl;
		cout << "Name : " << _name << endl;
		cout << "Proj : " << ProjectId << endl;
	}
};


class Developer :public Employee
{
	string ProjectId;
public:
	Developer(int id, string nm, string pId) :ProjectId(pId), Employee(id, nm)
	{
	}
	Developer(Dummy& dum, int key) :Employee(dum, key)
	{
		eId = 101;
		_name = "sachin";
		ProjectId = "123";
	}
	Employee* Clone()
	{
		return new Developer(eId, _name, ProjectId);
	}
	void DoJob()
	{
		cout << "Developer" << endl;
		cout << "Id   : " << eId << endl;
		cout << "Name : " << _name << endl;
		cout << "Proj : " << ProjectId << endl;
	}
};

void Register()
{
	Dummy d;
	new Manager(d, 10);
	new Developer(d, 20);
	new Tester(d, 30);
}
void main()
{
	Register();
	Employee *emp = Employee::CreateEmp(10);
	emp->DoJob();
}