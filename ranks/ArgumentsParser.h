

#ifndef ARGUMENTSPARSER_MUMAN_H
#define ARGUMENTSPARSER_MUMAN_H


class ArgumentsParser
{
public:
	static int getRank(int argc, char *argv[]);
	static int parse(int argc, char *argv[], int *rank, int *master_mode, int *slave_mode);


};












#endif
