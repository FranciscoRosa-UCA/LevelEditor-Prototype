#include "NetworkServer.h"

NetworkServer::NetworkServer() {

}

void NetworkServer::waitConnection() {
	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Can't Initialize winsock! Quitting" << endl;
		return;
	}

	// Create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Can't create a socket! Quitting" << endl;
		return;
	}

	// Bind the ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // Could also use inet_pton .... 

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// Tell Winsock the socket is for listening 
	listen(listening, SOMAXCONN);

	// Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);

	clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	ZeroMemory(host, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		NOConexion = false;

		cout << host << " connected on port " << service << endl;
	}
	else
	{
		NOConexion = false;

		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " <<
			ntohs(client.sin_port) << endl;
	}

	// Close listening socket
	closesocket(listening);

}

void NetworkServer::receiveData(int* D) {
	char buf[4096];
	ZeroMemory(buf, 4096);

	int bytesReceived = recv(clientSocket, buf, 4096, 0);
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
		cerr << "Error in recv(). Quitting" << endl;
	}

}

void NetworkServer::sendData(int Input) {

	std::stringstream sstream;
	sstream << Input;
	string Inputstr = sstream.str();

	if (Inputstr.size() > 0)		// Make sure the user has typed in something
	{
		int sendResult = send(clientSocket, Inputstr.c_str(), Inputstr.size() + 1, 0);
		if (sendResult == SOCKET_ERROR) {
			NOConexion = true;
		}
	}
	else
	{
		NOConexion = true;
		cout << "Server disconect" << endl;
	}
}

bool NetworkServer::ConexionLost() {
	return NOConexion;
}

NetworkServer::~NetworkServer() {
	// Close the socket
	closesocket(clientSocket);

	// Cleanup winsock
	WSACleanup();

	system("pause");
}