#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm11
{
	class Parts
	{
		string _make;
		string _series;
		string _processor;
		static map<string, Parts*> repo;
	public:
		Parts(string make,
			string series,
			string processor) :_make(make), _series(series), _processor(processor)
		{
			count++;
		}
		static string CreatePart(string make, string series, string processor)
		{
			string key = make + series + processor;
			if (repo.find(key) == repo.end())
				repo[key] = new Parts(make, series, processor);
			return key;
		}
		static Parts* GetPart(string key)
		{
			return repo[key];
		}
		friend class Computer;
		static int count;
	};
	int Parts::count;
	map<string, Parts*> Parts::repo;

	class Computer
	{
		string key;
		string _ram;
		string _hd;
		string _screen;
	public:
		static int count;
		Computer(string make,
			string series,
			string processor,
			string ram,
			string hd,
			string screen) :key(Parts::CreatePart(make, series, processor)), _ram(ram), _hd(hd), _screen(screen)
		{
			count++;
		}


		void Display()
		{
			Parts *part = Parts::GetPart(key);
			cout << "Make      : " << part->_make << endl;
			cout << "Series    : " << part->_series << endl;
			cout << "Processor : " << part->_processor << endl;
			cout << "RAM       : " << _ram << endl;
			cout << "HD        : " << _hd << endl;
			cout << "Screen    : " << _screen << endl;
			cout << "____________________________________________________" << endl;
		}
	};

	int Computer::count = 0;

	void main()
	{
		Computer comp1("Dell", "Lattitude", "Intel", "16gb", "1tb", "15inch");
		Computer comp2("Dell", "Lattitude", "Intel", "8gb", "2tb", "14inch");
		Computer comp3("Hp", "Flash", "Cellron", "16gb", "1tb", "15inch");
		Computer comp4("Hp", "Flash", "Cellron", "8gb", "1tb", "15inch");
		Computer comp5("Dell", "Lattitude", "Intel", "16gb", "1tb", "14inch");


		comp1.Display();
		comp2.Display();
		comp3.Display();
		comp4.Display();
		comp5.Display();
		cout << "Computers ordered is " << Computer::count << endl;
		cout << "Computers Parts is " << Parts::count << endl;
	}
}