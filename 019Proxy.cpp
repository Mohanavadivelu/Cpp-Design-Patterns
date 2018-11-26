#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm019
{
	struct Data
	{
		int x;
		int y;
	};
	class RealObject
	{
		Data data;
	public:
		RealObject()
		{
		}
		void ProcessBusiness(Data data)
		{
			this->data.x = data.x;
			this->data.y = data.y;
		}
		void Display()
		{
			cout << "X : " << data.x << endl;
			cout << "Y : " << data.y << endl;
		}
	};


	class Proxy
	{
		RealObject *real;
	public:
		Proxy(RealObject *real) :real(real)
		{
		}
		void ProcessBusiness(int x, int y)
		{
			Data data;
			data.x = x;
			data.y = y;
			real->ProcessBusiness(data);
		}
		void Display()
		{
			//data.x conerted to rupees
			real->Display();
		}
	};
	void main()
	{
		RealObject real;
		Proxy proxy(&real);



		proxy.ProcessBusiness(10, 20);
		proxy.Display();
	}
}