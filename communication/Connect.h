

#ifndef CONNECT_MUMAN_H
#define CONNECT_MUMAN_H

class Connect
{
public:
	static int spawnSocket();
	static void socketAddress(struct sockaddr_in &sockAddr, in_port_t serverPort, in_addr_t serverIp);
	static int connect();


};








#endif
