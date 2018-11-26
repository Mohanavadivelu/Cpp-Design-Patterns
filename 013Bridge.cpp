#include<iostream>
using namespace std;


namespace nm013
{
	class IOutput
	{
	public:
		virtual void Click() = 0;
		virtual void Move() = 0;
		virtual void Zoom() = 0;
	};

	class Screen :public IOutput
	{
	public:
		void Click() {
			cout << "Screen selected " << endl;
		}
		void Move() {
			cout << "Screen Relocated " << endl;
		}
		void Zoom() {
			cout << "Screen Magnified " << endl;
		}
	};
	class Audio :public IOutput
	{
	public:
		void Click() {
			cout << "Audio Oink " << endl;
		}
		void Move() {
			cout << "Audio Screetch " << endl;
		}
		void Zoom() {
			cout << "Audio Volume Increased " << endl;
		}
	};

	class Input
	{
	protected:
		IOutput *output;
	public:
		void SetOutPut(IOutput *output)
		{
			this->output = output;
		}
	};

	class Gesture :public Input
	{
	public:
		void Tap()
		{
			this->output->Click();
		}
		void Swipe()
		{
			this->output->Move();
		}
		void Pan()
		{
			this->output->Zoom();
		}
	};


	class Mouse :public Input
	{
	public:
		void Click()
		{
			this->output->Click();
		}
		void Drag()
		{
			this->output->Move();
		}
		void Wheel()
		{
			this->output->Zoom();
		}
	};
	void main()
	{
		//ouputs
		Screen scr;
		Audio audio;
		//inputs
		Gesture ges;
		Mouse mouse;

		mouse.SetOutPut(&audio);
		mouse.Click();
		mouse.Drag();
		mouse.Wheel();
		cout << "____________________" << endl;
		ges.SetOutPut(&scr);
		ges.Tap();
		ges.Swipe();
		ges.Pan();
		cout << "____________________" << endl;
	}
}