
#include "Protocol.h"
#include <unistd.h>
#include <string>
#include <Poco/NumberParser.h>
#include <Poco/NumberFormatter.h>

int Protocol::receiveMessage(int sock, vector<Message> &inbox)
{
	int message_tag = -1;
	int data_length = -1;
	int source = -1;
	int destination = -1;
	int globalReadCounter = 0;

	int counter = 0;
	char character;
	string message_stream;
	bool line_one = true;
	bool line_two = false;

	while(read(sock,&character, 1) == 1)
	{
		++globalReadCounter;
		if(character == ':' && line_one)
		{
			source = Poco::NumberParser::parse(message_stream);
			message_stream.clear();
		}
		else if(character == '\n' && line_one)
		{
			destination = Poco::NumberParser::parse(message_stream);
			message_stream.clear();
			line_one = false;
			line_two = true;
		}
		else if(character == ':' && line_two)
		{
			message_tag = Poco::NumberParser::parse(message_stream);
			message_stream.clear();
		}
		else if(character == '\n' && line_two)
		{
			data_length = Poco::NumberParser::parse(message_stream);
			message_stream.clear();
			line_two=false;
			break;
		}
		else
		{
			message_stream.push_back(character);
		}
	}

	while(read(sock,&character, 1) == 1)
	{
		++globalReadCounter;
		message_stream.push_back(character);
		++counter;
		if(counter == data_length) break;
	}
	if(globalReadCounter == 0) return 0;
	
	inbox.push_back(Message(source, destination, message_tag, message_stream));

	return 1;
}

int Protocol::sendMessage(int sock, vector<Message> &outbox)
{
	string stream;
	int left;
	int written;
	vector<Message> exchange;

	for(vector<Message>::iterator it = outbox.begin(); it != outbox.end(); ++it)
	{
		stream = messageToStream(*it);
		left = stream.size(); 
		char const *temp = stream.c_str();

		while(left>0 && (written = write(sock, temp, left)) > 0)
		{
			left -= written;
			temp += written;
		}

		if(left != 0)
		{
			exchange.push_back(*it);
		}
	}

	outbox = exchange; // fault-tolerance
	return 0;
}

string Protocol::messageToStream(Message &message)
{
	string stream;
	Poco::NumberFormatter::append(stream, message.getRankSource());
	stream.append(":");
	Poco::NumberFormatter::append(stream, message.getRankDestination());
	stream.append("\n");
	Poco::NumberFormatter::append(stream, message.getMessageTag());
	stream.append(":");
	Poco::NumberFormatter::append(stream, message.getContextSize());
	stream.append("\n");
	stream.append(message.getContext());

	return stream;
}


