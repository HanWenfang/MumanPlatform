
#ifndef MESSAGETAGHANDLER_MUMAN_H
#define MESSAGETAGHANDLER_MUMAN_H


class MessageTagHandler
{
public:
	MessageTagHandler(int mType):message_tag(mType) {}

	int message_tag;
	void callcack();

};





#endif


