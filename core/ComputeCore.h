

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
	vector<UniqueServer> ranks;
	int rank;
	AsynCore asyncore;
	map<int, MessageTagHandler*> MessageTagHandlerTable;

public:
	ComputeCore(vector<UniqueServer> &rank_set, int rk):ranks(rank_set), rank(rk){ }
	void run();
	void registerMessageHandler(MessageTagHandler &messageTagHandler);
	MessageTagHandler* getMessageHandler(int message_tag);
	int getRank()
	{
		return rank;
	}
};




#endif
