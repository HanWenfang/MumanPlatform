
#ifndef TREACTOR_MUMAN_H
#define TREACTOR_MUMAN_H
#include <arpa/inet.h>
#include <list>
#include <vector>
#include <iostream>
#include "communication/MessageHandler.h"
#include "core/ComputeCore.h"
#include "communication/Protocol.h"
#include <Poco/Thread.h>
#include <Poco/Runnable.h>
#include <Poco/Mutex.h>

class ComputeCore;

using namespace std;

class TReactor: public Poco::Runnable
{
private:
	bool isAlive;
	bool isClosed;

	vector<Message> inbox;
	vector<Message> outbox;
	ComputeCore *computeCore;
	list<int> descriptors;
	Poco::Mutex mutex;

public:
	TReactor(ComputeCore *computeC):isAlive(true),isClosed(false),computeCore(computeC)
	{
		
	}

	//atomic operation
	int addDescriptor(int sock);
	void removeDescriptor(int sock);
	unsigned int copyDescriptorSet(list<int> &dset);
	int max(list<int> &dset);

	int start();
	virtual void run();
};











#endif
