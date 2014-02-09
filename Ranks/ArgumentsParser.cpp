
#include "ArgumentsParser.h"
#include <Poco/NumberParser.h>
#include <string.h>

int ArgumentsParser::getRank(int argc, char *argv[])
{
	for(int i=1; i<argc; i+=2)
	{
		if(strcmp(argv[i], "-rank") == 0) return Poco::NumberParser::parse(argv[i+1]);
	}

	return -1;
}




