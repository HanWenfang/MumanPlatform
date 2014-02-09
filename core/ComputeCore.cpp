
#include "ComputeCore.h"
#include "reactor/Reactor.h"


void ComputeCore::run()
{
	asyncore.initialize(rank, ranks);
	Reactor reactor(this);

	for(;;)
	{
		
		if(asyncore.select() > 0)
		{
			reactor.start(asyncore.acceptSocket()); // reactor
		}

		// rank
		if(rank == 1)
		{
			
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
