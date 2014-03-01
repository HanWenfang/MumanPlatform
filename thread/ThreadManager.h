

#ifndef THREADMANAGER_MUMAN_H
#define THREADMANAGER_MUMAN_H
#include <Poco/Thread.h>
#include <list>
#include <Poco/Mutex.h>

using namespace std;

// thread-safe except tryWait(
class ThreadManager
{
private:
	list<Poco::Thread *> threads;
	Poco::Mutex mutex;

public:
	void eraseThread(list<Poco::Thread *>::iterator &it);
	void pushBackThread(Poco::Thread *thread);
	void tryWait();
};







#endif

