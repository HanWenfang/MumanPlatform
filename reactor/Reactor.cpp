
#include "Reactor.h"
#include "communication/Message.h"
#include <sys/select.h>

int Reactor::start(int sock)
{
	fd_set file_descriptors;
	struct timeval time_value;

	while(isAlive)
	{
		FD_ZERO(&file_descriptors);
		FD_SET(sock, &file_descriptors);
		time_value.tv_sec = 5;
		time_value.tv_usec = 200;

		if (::select(sock+1, &file_descriptors, NULL, NULL, &time_value) > 0)
		{
			//receiveMessage
			if ( Protocol::receiveMessage(sock, inbox) == 0)
			{
				close(sock);
				isAlive = false;
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
			if(!outbox.empty()) Protocol::sendMessage(sock, outbox);
	}

	return 0;
}







