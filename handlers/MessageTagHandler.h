
#ifndef MESSAGETAGHANDLER_MUMAN_H
#define MESSAGETAGHANDLER_MUMAN_H
#include "communication/Message.h"
#include <iostream>


class MessageTagHandler
{
public:
	MessageTagHandler(int mType):message_tag(mType) {}

	int message_tag;
	virtual int callback(Message &message) { return 0;}

};





#endif


