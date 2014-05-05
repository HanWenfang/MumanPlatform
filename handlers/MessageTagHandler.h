
#ifndef MESSAGETAGHANDLER_MUMAN_H
#define MESSAGETAGHANDLER_MUMAN_H
#include "communication/Message.h"
#include "communication/MessageTypes.h"
#include <iostream>


class MessageTagHandler
{
public:
	MessageTagHandler(int mType):message_tag(mType) {}

	int message_tag;
	virtual Message callback(Message &message) { return Message(0, 1, BLANK_MESSAGE, ""); }

};





#endif


