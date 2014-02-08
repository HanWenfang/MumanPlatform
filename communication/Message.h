

#ifndef MESSAGE_MUMAN_H
#define MESSAGE_MUMAN_H
#include <string>

using namespace std;

class Message
{
private:
	int rank_source;
	int rank_destination;
	
	int message_tag;

	string context; // stream protocol

public:
	Message(int rank_src, int rank_des, int message_t, string cont)\
	:rank_source(rank_src), rank_destination(rank_des), message_tag(message_t), context(cont)
	{

	}

};






#endif

