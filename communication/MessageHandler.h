

#ifndef MESSAGEHANDLER_MUMAN_H
#define MESSAGEHANDLER_MUMAN_H
#include "communication/Message.h"
#include <vector>

using namespace std;

class MessageHandler
{
public:
	int sendMessage(vector<Message> &outbox, int sock);
	int receiveMessage(vector<Message> &inbox, int sock);


};









#endif
