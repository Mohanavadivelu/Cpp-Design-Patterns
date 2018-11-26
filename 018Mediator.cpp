#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm018
{
	class ChatServer;

	class ChatClient {
	protected:
		string Name;
		ChatServer *server;
		ChatClient(string name) :Name(name)
		{
		}
	public:
		void SetServer(ChatServer *server)
		{
			this->server = server;
		}
		virtual void Send(string msg, string to) = 0;
		virtual void Recieve(string msg, string from) = 0;
		void ConnectToChat();

		void DisConnectFromChat();

	};




	class ChatServer
	{
		map<string, ChatClient*> clients;
		string Name;
	public:
		ChatServer(string Name) :Name(Name)
		{
		}
		void Connect(string key, ChatClient *client)
		{
			cout << key << " Connected to room " << Name << endl;
			clients[key] = client;
		}
		void DisConnect(string key)
		{
			cout << key << " Disconnected from room " << Name << endl;
			clients.erase(key);
		}
		void Dispatch(string msg, string to, string from)
		{
			if (to == "")
			{
				map<string, ChatClient*>::iterator it1 = clients.begin();
				auto it2 = clients.end();
				while (it1 != it2)
				{
					if (it1->first != from)
					{
						it1->second->Recieve(msg, from);
					}
					it1++;
				}
			}
			else
			{
				clients[to]->Recieve(msg, from);
			}
		}
	};



	void ChatClient::ConnectToChat()
	{
		server->Connect(Name, this);
	}
	void ChatClient::DisConnectFromChat()
	{
		server->DisConnect(Name);
	}

	class IndianChatClient :public ChatClient
	{
	public:
		IndianChatClient(string name) :ChatClient(name)
		{

		}
		void Send(string msg, string to)
		{
			//changes of messages 
			server->Dispatch(msg, to, Name);
		}
		void Recieve(string msg, string from)
		{
			cout << Name << " : [From " << from << "] " << msg << endl;
		}
	};
	void main()
	{
		ChatServer server1("IndiaRoom");
		ChatServer server2("Delhi");
		IndianChatClient sewag("sewag");
		IndianChatClient sachin("sachin");
		IndianChatClient rahul("rahul");
		IndianChatClient vvs("vvs");
		sewag.SetServer(&server1);
		sachin.SetServer(&server1);
		rahul.SetServer(&server1);
		vvs.SetServer(&server1);

		sewag.ConnectToChat();
		sachin.ConnectToChat();
		rahul.ConnectToChat();
		vvs.ConnectToChat();
		cout << "____________________________" << endl;

		rahul.Send("India plays Afganisthan ", "");
		cout << "____________________________" << endl;
		rahul.Send("Virat not taking part ", "vvs");
		cout << "____________________________" << endl;
	}
}