#include<iostream>
#include<string>
using namespace std;
namespace nm007
{
	class ILogger
	{
	public:
		virtual void LogMsg(string msg) = 0;
	};
	class NullLogger :public ILogger
	{
	public:
		virtual void LogMsg(string msg) {
			//do nothing
		}
	};

	class LoggerHelper :public ILogger
	{
		ILogger *il;
	protected:
		LoggerHelper(ILogger *il) :il(il)
		{
		}
	public:
		virtual void LogMsg(string msg) {
			il->LogMsg(msg);
		}
	};

	class ConsoleLogger :public LoggerHelper
	{
	public:
		ConsoleLogger(ILogger *il) :LoggerHelper(il)
		{
		}
		virtual void LogMsg(string msg) {
			cout << "Console Logger ( " << msg << " )" << endl;
			LoggerHelper::LogMsg(msg);
		}
	};

	class FileLogger :public LoggerHelper
	{
	public:
		FileLogger(ILogger *il) :LoggerHelper(il)
		{
		}
		virtual void LogMsg(string msg) {
			cout << "File Logger [ " << msg << " ]" << endl;
			LoggerHelper::LogMsg(msg);
		}
	};

	class ServiceLogger :public LoggerHelper
	{
	public:
		ServiceLogger(ILogger *il) :LoggerHelper(il)
		{
		}
		virtual void LogMsg(string msg) {
			cout << "Service Logger ---> " << msg << " <---" << endl;
			LoggerHelper::LogMsg(msg);
		}
	};

	class EtwLogger :public LoggerHelper
	{
	public:
		EtwLogger(ILogger *il) :LoggerHelper(il)
		{
		}
		virtual void LogMsg(string msg) {
			cout << "ETW Logger *** " << msg << " ***" << endl;
			LoggerHelper::LogMsg(msg);
		}
	};

	class LoggerFactory
	{
	public:
		static ILogger* GetLoggers()
		{
			//return new NullLogger();
			//return new ConsoleLogger();
			//return new FileLogger();
			//return new ServiceLogger();
			return  new EtwLogger(new ServiceLogger(new ConsoleLogger(new FileLogger(new NullLogger()))));
		}
	};
	//-----------------------------------------
	void main()
	{
		cout << "Business Started  ..." << endl;
		ILogger *logger = LoggerFactory::GetLoggers();
		logger->LogMsg("Withdraw done ");
		cout << "Business Completed ..." << endl;
	}
}
