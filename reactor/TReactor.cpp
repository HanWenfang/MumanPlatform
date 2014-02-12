
#include "TReactor.h"

int TReactor::addDescriptor(int sock)
{
	if(sock < 0) return -1;

	Poco::Mutex::ScopedLock lock(mutex);

	if(descriptors.size() >= FD_SETSIZE) return -1;

	descriptors.push_front(sock);
	return 0;
}

void TReactor::removeDescriptor(int sock)
{
	Poco::Mutex::ScopedLock lock(mutex);
	list<int>::iterator it=descriptors.begin();

	for(; it != descriptors.end(); ++it)
	{
		if(*it == sock) break;
	}

	if(it != descriptors.end()) descriptors.erase(it);
}

unsigned int TReactor::copyDescriptorSet(list<int> &dset)
{
	Poco::Mutex::ScopedLock lock(mutex);
	unsigned int counter = 0;
	
	for(list<int>::iterator it=descriptors.begin(); it != descriptors.end(); ++it)
	{
		dset.push_front(*it);
		++counter;
	}

	return counter;
}

int TReactor::max(list<int> &dset)
{
	int maxA = -1;
	for(list<int>::iterator it=dset.begin(); it != dset.end(); ++it)
	{
		if (*it > maxA) maxA = *it;
	}
	return maxA;
}

int TReactor::start()
{
	fd_set file_descriptors;
	fd_set *file_descriptors_ptr = NULL;
	struct timeval time_value;

	list<int> descriptorSet;
	int maxSock;

	while(isAlive)
	{
		if(copyDescriptorSet(descriptorSet) == 0) file_descriptors_ptr = NULL;
		else file_descriptors_ptr = &file_descriptors;

		maxSock = max(descriptorSet);

		FD_ZERO(&file_descriptors);
		
		for(list<int>::iterator it=descriptorSet.begin(); it != descriptorSet.end(); ++it)
		{
			FD_SET(*it, &file_descriptors);
		}

		time_value.tv_sec = 5;
		time_value.tv_usec = 200;

		if (::select(maxSock+1, file_descriptors_ptr, NULL, NULL, &time_value) > 0)
		{
			//receiveMessage
			for(list<int>::iterator it=descriptorSet.begin(); it != descriptorSet.end(); ++it)
			{
				if(FD_ISSET(*it, file_descriptors))
				{
					if ( Protocol::receiveMessage(sock, inbox) == 0)
					{
						close(sock);
						removeDescriptor(sock);
					}

				}
			}
		}
			cout << "inbox: " << inbox.size() << endl;
			//processData
			for(vector<Message>::iterator it=inbox.begin(); it != inbox.end(); ++it)
			{
				cout << "Rank: " << computeCore->getRank() << endl;
				computeCore->getMessageHandler(it->getMessageTag())->callback(*it);
			}
			//processMessage
			if(!inbox.empty()) inbox.clear();

			//sendMessage [use timeout to solve communication faulse]
			if(!outbox.empty()) Protocol::sendMessage(sock, outbox); // ??????????
	}

	return 0;
}

void run()
{
	start();
}