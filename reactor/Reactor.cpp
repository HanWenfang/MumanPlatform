
#include "Reactor.h"
#include "communication/Message.h"
#include "communication/MessageTypes.h"
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

		if(computeCore->getRank() == 1)
		{
			Message message(1, 0, ECHO_MESSAGE, "Hello World");
			outbox.push_back(message);
		}

		if (::select(sock+1, &file_descriptors, NULL, NULL, &time_value) > 0)
		{
			//receiveMessage
		}
			//processMessage

			//processData

			//sendMessage [use timeout to solve communication faulse]


	}

	return 0;
}







