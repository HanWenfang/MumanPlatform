
#include "ComputeCore.h"
#include "reactor/Reactor.h"

void ComputeCore::ConfigRank()
{

}


void ComputeCore::run()
{
	ConfigRank();
	asyncore.initialize(rank, ranks);
	Reactor reactor(this);

	for(;;)
	{
		
		if(asyncore.select() > 0)
		{
			reactor.start(asyncore.acceptSocket()); // reactor
		}
		
		//if(errno == EINTR) { continue; }
	}

}

void ComputeCore::registerMessageHandler(MessageTagHandler &messageTagHandler)
{
	MessageTagHandlerTable[messageTagHandler.message_tag] = &messageTagHandler;
}


