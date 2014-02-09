
#ifndef REACTOR_MUMAN_H
#define REACTOR_MUMAN_H
#include <arpa/inet.h>
#include <vector>
#include <iostream>
#include "communication/MessageHandler.h"
#include "core/ComputeCore.h"
#include "communication/Protocol.h"

class ComputeCore;

using namespace std;

class Reactor
{
private:
	bool isAlive;
	vector<Message> inbox;
	vector<Message> outbox;
	ComputeCore *computeCore;
public:
	Reactor(ComputeCore *computeC):isAlive(true),computeCore(computeC)
	{
		
	}
	int start(int sock);
};









#endif
