
#include "ComputeCore.h"
#include "reactor/Reactor.h"
#include "communication/Connect.h"
#include "communication/Protocol.h"
#include "communication/Message.h"
#include "communication/MessageTypes.h"
#include <errno.h>
#include <string.h>

void ComputeCore::run()
{
	if (asyncore.initialize(rank, ranks) < 0)
	{
		cout << "initialize asyncore error." << endl;
		return;
	}

	Reactor reactor(this);
	int flag = true;

	for(;;)
	{
		if(asyncore.select() > 0)
		{
			reactor.start(asyncore.acceptSocket()); // reactor
		}

		cout << "rank: " << rank <<endl;
		// rank
		if(rank == 1 && flag)
		{
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

			flag = false;
		}

		//if(errno == EINTR) { continue; }
	}

}

void ComputeCore::registerMessageHandler(MessageTagHandler &messageTagHandler)
{
	MessageTagHandlerTable[messageTagHandler.message_tag] = &messageTagHandler;
}

MessageTagHandler* ComputeCore::getMessageHandler(int message_tag)
{
	return MessageTagHandlerTable[message_tag];
}
