#ifndef __SERVEROBJ__
#define __SERVEROBJ__

// ·þÎñÆ÷×´Ì¬
enum
{
	enumServerStateOK = 1,
};

class ServerObj
{
private:
	ServerObj();
	ServerObj(const ServerObj&);
	ServerObj& operator=(const ServerObj&);
	~ServerObj();
	/*ServerObj& GetServerObj();*/
	int Initialize();
	
public:
	static ServerObj& getInstance(int& nRetCode);
	int UnInitialize();
	void ThreadFunction();

private:
	bool bInited;
};


#endif // __SERVEROBJ__
