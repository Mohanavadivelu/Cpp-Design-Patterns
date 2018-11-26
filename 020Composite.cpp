#include<iostream>
#include<string>
#include<list>
using namespace std;


namespace nm20
{
	class Player
	{
		string _name;
	public:
		Player(string name) :_name(name)
		{
		}
		void Display()
		{
			cout << "\t\t\t\t" << _name << endl;
		}
	};

	class PlayerList :public list<Player*>
	{
	public:
		void Display()
		{

			auto it1 = begin();
			auto it2 = end();
			while (it1 != it2)
			{
				(*it1)->Display();
				it1++;
			}
		}
	};

	class Team
	{
		PlayerList players;
		string name;
	public:
		Team(string name) :name(name)
		{

		}
		void AddPlayer(Player *ply)
		{
			players.push_back(ply);
		}
		void Display()
		{
			cout << "\t\t\t" << name << endl;
			players.Display();
		}

	};

	class Teamlist :public list<Team*>
	{
	public:
		void Display()
		{

			auto it1 = begin();
			auto it2 = end();
			while (it1 != it2)
			{
				(*it1)->Display();
				it1++;
			}
		}
	};


	class Division
	{
		Teamlist teams;
		string Name;
	public:
		Division(string Name) :Name(Name)
		{
		}
		void AddTeam(Team * team)
		{
			teams.push_back(team);
		}
		void Display()
		{
			cout << "\t\t" << Name << endl;
			teams.Display();
		}
	};
	void main()
	{
		Team *team;

		Division div1("Apple");
		div1.AddTeam(team = new Team("Alpha"));
		team->AddPlayer(new Player("sewag"));
		team->AddPlayer(new Player("rahul"));
		team->AddPlayer(new Player("vvs"));
		team->AddPlayer(new Player("sachin"));
		team->AddPlayer(new Player("zaheer"));

		div1.AddTeam(team = new Team("Beta"));
		team->AddPlayer(new Player("virat"));
		team->AddPlayer(new Player("rohith"));
		team->AddPlayer(new Player("rahane"));
		team->AddPlayer(new Player("dhoni"));
		team->AddPlayer(new Player("rahul"));

		div1.AddTeam(team = new Team("Gama"));
		team->AddPlayer(new Player("prabakar"));
		team->AddPlayer(new Player("ajay"));
		team->AddPlayer(new Player("azhar"));
		team->AddPlayer(new Player("mongia"));

		div1.Display();

		Division div2("orange");
		div2.AddTeam(team = new Team("Alpha"));
		team->AddPlayer(new Player("sewag"));
		team->AddPlayer(new Player("rahul"));
		team->AddPlayer(new Player("vvs"));
		team->AddPlayer(new Player("sachin"));
		team->AddPlayer(new Player("zaheer"));

		div2.AddTeam(team = new Team("Beta"));
		team->AddPlayer(new Player("virat"));
		team->AddPlayer(new Player("rohith"));
		team->AddPlayer(new Player("rahane"));
		team->AddPlayer(new Player("dhoni"));
		team->AddPlayer(new Player("rahul"));

		div2.AddTeam(team = new Team("Gama"));
		team->AddPlayer(new Player("prabakar"));
		team->AddPlayer(new Player("ajay"));
		team->AddPlayer(new Player("azhar"));
		team->AddPlayer(new Player("mongia"));

		div2.Display();
	}
}