
#include "ThreadManager.h"


void ThreadManager::eraseThread(list<Poco::Thread>::iterator &it)
{
	Poco::Mutex::ScopedLock lock(mutex);
	threads.erase(it);
}

void ThreadManager::pushBackThread(Poco::Thread &thread)
{
	Poco::Mutex::ScopedLock lock(mutex);
	threads.push_back(thread);
}

void ThreadManager::tryWait()
{
	for(list<Poco::Thread>::iterator it = threads.begin(); it != threads.end(); ++it)
	{
		if(it->tryJoin(1))
		{
			eraseThread(it);
		}
	}
}



