
#ifndef MESSAGETAGHANDLER_MUMAN_H
#define MESSAGETAGHANDLER_MUMAN_H
#include "communication/Message.h"
#include <iostream>


class MessageTagHandler
{
public:
	MessageTagHandler(int mType):message_tag(mType) {}

	int message_tag;
	virtual void callback(Message &message) {}

};





#endif


