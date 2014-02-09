#include <iostream>
#include "Ranks/UniqueServer.h"
#include <vector>
#include "handlers/MessageTagHandler.h"
#include "core/ComputeCore.h"
#include "communication/MessageTypes.h"
#include "Ranks/ArgumentsParser.h"

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

	void callback(Message &message)
	{
		cout << "ECHO_MESSAGE callback!" << endl;
		cout << message.getRankSource() << " -> " << message.getRankDestination() << endl;
		cout << "Got : "  << message.getContext() << endl;
	}
};

int main(int argc, char *argv[])
{
	UniqueServer rank1("127.0.0.1", 50501);
	UniqueServer rank2("127.0.0.1", 50502);
	vector<UniqueServer> ranks;
	ranks.push_back(rank1);
	ranks.push_back(rank2);

	int rank = ArgumentsParser::getRank(argc, argv);

	ComputeCore computerCore(ranks, rank);

	// message handler
	echoMessage echoHandler(ECHO_MESSAGE);

	computerCore.registerMessageHandler(echoHandler);
	
	computerCore.run();

	return 0;
}

