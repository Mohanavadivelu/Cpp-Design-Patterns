#include<iostream>
#include<string>
#include<list>
using namespace std;

namespace nm023
{
	class Itrav
	{
	public:
		virtual void First() = 0;
		virtual void Last() = 0;
		virtual bool Next() = 0;
		virtual void MoveNext() = 0;
		virtual int Current() = 0;
	};

	class Container
	{
		int arr[5];
		int size = 4;
	public:
		Container() :arr{ 11,22,33,44,55 }
		{
		}

		class Iterator :public Itrav
		{
			Container *ptr;
			int curr = -1;
		public:
			Iterator(Container *ptr) :ptr(ptr)
			{
			}
			virtual void First() {
				curr = 0;
			}
			virtual void Last() {
				curr = this->ptr->size;
			}
			virtual bool Next() {
				return curr <= this->ptr->size;
			}
			virtual void MoveNext() {
				curr++;
			}
			virtual int Current() {
				return this->ptr->arr[curr];
			}
		};

		Container* Begin()
		{
			return this;
		}
		void Display()
		{
			for (int i = 0; i <= size; i++)
			{
				cout << "arr[" << i << "]=" << arr[i] << endl;
			}
		}
	};

	void main()
	{
		Container cnt;
		Container::Iterator it = cnt.Begin();
		it.First();
		while (it.Next())
		{
			cout << it.Current() << endl;
			it.MoveNext();
		}
		cout << "_________________" << endl;
		cnt.Display();
	}
}