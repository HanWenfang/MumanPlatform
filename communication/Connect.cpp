
#include "Connect.h"



int Connect::spawnSocket()
{
	return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}


void Connect::socketAddress(struct sockaddr_in &sockAddr, in_port_t serverPort, in_addr_t serverIp)
{
	sockAddr.sin_family = AF_INET; //IPv4
	sockAddr.sin_port = serverPort;
	sockAddr.sin_addr.s_addr = serverIp;
}






