#include <iostream>
#include "ranks/UniqueServer.h"
#include <vector>
#include "handlers/MessageTagHandler.h"
#include "handlers/RankHandler.h"
#include "core/ComputeCore.h"
#include "communication/MessageTypes.h"
#include "ranks/ArgumentsParser.h"
#include "communication/Connect.h"
#include "communication/Protocol.h"
#include "communication/Message.h"
#include <errno.h>
#include <string.h>

using namespace std;

//receive message
//process message
//process data
//send message

// Message Handler
class echoMessage:public MessageTagHandler
{
public:
	echoMessage(int mType):MessageTagHandler(mType)
	{

	}

	int callback(Message &message)
	{
		cout << "ECHO_MESSAGE callback!" << endl;
		cout << message.getRankSource() << " -> " << message.getRankDestination() << endl;
		cout << "Got : "  << message.getContext() << endl;

		return 0;
	}
};

class RankOneHandler:public RankHandler
{
public:
	RankOneHandler(int rk, vector<UniqueServer> &ranks ,int flag):RankHandler(rk, ranks, flag)
	{

	}

	int callback()
	{
		vector<Message> outbox;
		cout << "send message..." << endl;
		int sock;
		if ( Connect::connect(ranks[0].ip, ranks[0].port, sock) < 0)
		{
			cout << "connect " << ranks[0].ip << ":" << ranks[0].port << " error" << endl;
			cout << strerror(errno) << endl;
		}
		Message message(1, 0, ECHO_MESSAGE, "Hello World");
		outbox.push_back(message);
		Protocol::sendMessage(sock, outbox);
		sleep(3);
		close(sock);

		running_flag = false;

		return 0;
	}
};


int main(int argc, char *argv[])
{
	UniqueServer rank1("127.0.0.1", 17501);
	UniqueServer rank2("127.0.0.1", 16502);
	vector<UniqueServer> ranks;
	ranks.push_back(rank1);
	ranks.push_back(rank2);

	int rank = ArgumentsParser::getRank(argc, argv);

	ComputeCore computerCore(ranks, rank);
	cout << ranks[0].ip << ":" << ranks[0].port << endl;
	
	// message handler
	echoMessage echoHandler(ECHO_MESSAGE);
	computerCore.registerMessageHandler(echoHandler);

	// rank handler
	RankOneHandler rankOneHandler(1, ranks, true);
	computerCore.registerRankHandler(rankOneHandler);

	cout << "stat running..." << endl;
	computerCore.run();

	return 0;
}

