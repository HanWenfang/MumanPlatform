
#include "Connect.h"
#include <string.h>


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

int Connect::connect(string &ip, int port, int &socket)
{
	socket = spawnSocket();
	if (socket < 0) {
		cout << "spawn socket error" << endl;
		return -1;
	}
	if(configSocket(SO_REUSEADDR, socket) < 0) {
		cout << "config socket error" << endl;
		return -1;
	}
	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	socketAddress(server_address, htons(port), inet_addr(ip.c_str()));

	return ::connect(socket, (struct sockaddr *)&server_address, sizeof(server_address));
}

int Connect::configSocket(int option, int &socket)
{
	int on = 1;
	return setsockopt(socket, SOL_SOCKET, option, &on, sizeof(on));
}


