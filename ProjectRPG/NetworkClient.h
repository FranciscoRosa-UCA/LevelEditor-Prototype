#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include <sstream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

class NetworkClient {
private:
	string ipAddress;			// IP Address of the server
	int port;
	// Initialize WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult;
	SOCKET sock;

	bool NOConexion = true;


public:
	NetworkClient(string, int);
	~NetworkClient();

	void searchConnection();

	void sendData(int);
	void receiveData(int*);

	bool ConexionLost();

};

