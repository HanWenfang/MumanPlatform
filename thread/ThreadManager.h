

#ifndef THREADMANAGER_MUMAN_H
#define THREADMANAGER_MUMAN_H
#include <Poco/Thread.h>
#include <vector>

using namespace std;

class ThreadManager
{
private:
	vector<Thread> threads;

public:

	int tryWait();

};







#endif
