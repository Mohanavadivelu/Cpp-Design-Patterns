#include<iostream>
#include<string>
#include<map>
using namespace std;

namespace nm016
{
	class ISubscribers
	{
	public:
		virtual void Notify(string msg) = 0;
	};
	

	class Observer
	{
		map<string, ISubscribers*> repository;
	protected:
		void NotifyAll(string msg)
		{
			map<string, ISubscribers*>::iterator itSt = repository.begin();
			map<string, ISubscribers*>::iterator itEnd = repository.end();
			while (itSt != itEnd)
			{
				itSt->second->Notify(msg);
				itSt++;
			}
		}
	public:
		virtual void ChangeInfo(string msg) = 0;
		void SetSubscriber(string key, ISubscribers* client)
		{
			repository[key] = client;
		}

	};
	
	
	
	class CricketObserver :public Observer
	{
	public:
		void ChangeInfo(string msg)
		{
			string message = "Cricket Info is " + msg;
			NotifyAll(message);
		}
	};
	
	
	class ElectionObserver :public Observer
	{
	public:
		void ChangeInfo(string msg)
		{
			string message = "Election New now " + msg;
			NotifyAll(message);
		}
	};
	

	class EntertainmentObserver :public Observer
	{
	public:
		void ChangeInfo(string msg)
		{
			string message = "Entertainment NewS " + msg;
			NotifyAll(message);
		}
	};
	

	class Publisher
	{
	protected:
		Observer *observer;
	public:
		void SetObserver(Observer *observer)
		{
			this->observer = observer;
		}
		void Notify(string msg)
		{
			this->observer->ChangeInfo(msg);
		}
	};

	class Cricket :public Publisher
	{
		string score;
	public:
		void SetScore(string score)
		{
			this->score = score;
			Notify("The score changed to " + score);
		}

	};


	class Election :public Publisher
	{
		string  status;
	public:
		void SetStatus(string status)
		{
			this->status = status;
			Notify("The Party Curruntly leading is  " + status);
		}

	};
	class Entertainment :public Publisher
	{
		string  info;
	public:
		void SetStatus(string info)
		{
			this->info = info;
			Notify("Breking News : " + this->info);
		}

	};


	class NDTV :public ISubscribers
	{
	public:
		void Notify(string msg)
		{
			cout << "NDTV : [" << msg << " ]" << endl;
		}
	};

	class DD :public ISubscribers
	{
	public:
		void Notify(string msg)
		{
			cout << "DD : (" << msg << " )" << endl;
		}
	};

	class Times :public ISubscribers
	{
	public:
		void Notify(string msg)
		{
			cout << "Times : ***" << msg << " ***" << endl;
		}
	};




	void main()
	{
		CricketObserver obsCric;
		Cricket cricket;
		cricket.SetObserver(&obsCric);

		Election elect;
		ElectionObserver obsElec;
		elect.SetObserver(&obsElec);

		Entertainment ent;
		EntertainmentObserver obsEnt;
		ent.SetObserver(&obsEnt);



		NDTV ndtv;
		Times times;
		DD dd;

		obsCric.SetSubscriber("ndtv", &ndtv);
		obsCric.SetSubscriber("dd", &dd);

		obsElec.SetSubscriber("ndtv", &ndtv);
		obsElec.SetSubscriber("dd", &dd);
		obsElec.SetSubscriber("times", &times);
		cricket.SetScore("345");
		cout << "___________________________" << endl;
		elect.SetStatus("JDS ");
	}
}


/*
DD : (Cricket Info is The score changed to 345 )
NDTV : [Cricket Info is The score changed to 345 ]
___________________________
DD : (Election New now The Party Curruntly leading is  JDS  )
NDTV : [Election New now The Party Curruntly leading is  JDS  ]
Times : ***Election New now The Party Curruntly leading is  JDS  ***

*/