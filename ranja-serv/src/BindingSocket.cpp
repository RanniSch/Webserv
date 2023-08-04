
#include "BindingSocket.hpp"

// Constructor
BindingSocket::BindingSocket(int domain, int service, int protocol,
    int port, u_long interface) : SocketSimple(domain, service, protocol,
    port, interface)
{
    // Establish the connection
    setConnection(connectToNetwork(getSock(), getAddress()));
    testConnection(getConnection());
}

// Definition of connectToNetwork virtual function
int BindingSocket::connectToNetwork(int _sock, struct sockaddr_in _address)
{
    return (bind(_sock, (struct sockaddr *)&_address, sizeof(_address)));
}