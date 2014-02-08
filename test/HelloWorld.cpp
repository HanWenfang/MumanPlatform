#include <iostream>
#include "Ranks/UniqueServer.h"
#include <vector>
#include "handlers/MessageTagHandler.h"
#include "core/ComputeCore.h"
#include "communication/MessageTypes.h"

using namespace std;

//receive message
//process message
//process data
//send message

class echoMessage:public MessageTagHandler
{
public:
	echoMessage(int mType):MessageTagHandler(mType)
	{

	}

	void callback()
	{
		cout << "ECHO_MESSAGE callback!" << endl;
	}
};

int main(int argc, char *argv[])
{
	UniqueServer rank1("127.0.0.1", 50501);
	UniqueServer rank2("127.0.0.1", 50502);
	vector<UniqueServer> ranks;
	ranks.push_back(rank1);
	ranks.push_back(rank2);

	ComputeCore computerCore(ranks);
	// message handler
	echoMessage echoHandler(ECHO_MESSAGE);

	computerCore.registerMessageHandler(echoHandler);
	
	cout << "Hello World!" << endl;
	return 0;
}

