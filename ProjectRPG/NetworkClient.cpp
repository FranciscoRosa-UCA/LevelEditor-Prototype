#include "NetworkClient.h"

NetworkClient::NetworkClient(string ipAddress, int port) {
	this->ipAddress = ipAddress;
	this->port = port;
}

void NetworkClient::searchConnection() {
	wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Can't start Winsock, Err #" << wsResult << endl;
		return;
	}

	// Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "Can't create socket, Err #" << WSAGetLastError() << endl;
		WSACleanup();

	}

	// Fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Connect to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cerr << "Can't connect to server, Err #" << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();

	}
	else {
		NOConexion = false;
		cout << "Coneccted" << endl;
	}

}

void NetworkClient::sendData(int Input) {

	std::stringstream sstream;
	sstream << Input;
	string Inputstr = sstream.str();

	if (Inputstr.size() > 0)		// Make sure the user has typed in something
	{
		// Send the text
		int sendResult = send(sock, Inputstr.c_str(), Inputstr.size() + 1, 0);
		if (sendResult == SOCKET_ERROR)
		{
			NOConexion = true;
			cout << "Error al enviar el mensaje" << endl;
		}
	}
	else {
		NOConexion = true;
		cout << "Desconectando del servidor" << endl;
	}
}

void NetworkClient::receiveData(int* D) {
	char buf[4096];
	// Wait for response
	ZeroMemory(buf, 4096);
	int bytesReceived = recv(sock, buf, 4096, 0);
	if (bytesReceived > 0 && bytesReceived != SOCKET_ERROR)
	{
		string DATA = string(buf, 0, bytesReceived);
		stringstream intDATA(DATA);
		int DATAINT = 0;
		intDATA >> DATAINT;

		*D = DATAINT;

	}
	else {
		NOConexion = true;
		cout << "Disconected" << endl;
	}

}

bool NetworkClient::ConexionLost() {
	return NOConexion;
}

NetworkClient::~NetworkClient() {
	// Gracefully close down everything
	closesocket(sock);
	WSACleanup();
}