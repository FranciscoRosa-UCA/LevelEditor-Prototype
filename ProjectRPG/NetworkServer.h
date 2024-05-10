#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <sstream>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

class NetworkServer {
private:
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);
	SOCKET clientSocket;

	char host[NI_MAXHOST];		// Client's remote name
	char service[NI_MAXSERV];	// Service (i.e. port) the client is connect on

	bool NOConexion = true;

public:
	NetworkServer();
	~NetworkServer();

	void waitConnection();

	void sendData(int);
	void receiveData(int*);

	bool ConexionLost();

};

