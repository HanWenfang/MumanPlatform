

#ifndef COMUPTECORE_MUMAN_H
#define COMUPTECORE_MUMAN_H
#include <vector>
#include "communication/Message.h"
#include "core/AsynCore.h"
#include "reactor/Reactor.h"
#include "handlers/MessageTagHandler.h"
#include <map>

using namespace std;

class ComputeCore
{
private:
	vector<Message> inbox;
	vector<Message> outbox;
	int rank;
	vector<UniqueServer> ranks;
	AsynCore asyncore;
	map<int, MessageTagHandler*> MessageTagHandlerTable;

public:
	ComputeCore(vector<UniqueServer> &rank_set):ranks(rank_set){ }
	void run();
	void ConfigRank();
	void registerMessageHandler(MessageTagHandler &messageTagHandler);
	int getRank()
	{
		return rank;
	}
};




#endif
