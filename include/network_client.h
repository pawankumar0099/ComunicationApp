#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H
#include "communication.h"
#include <arpa/inet.h>
#include "constant.h"
class NetworkClient : public Communication
{
private:
    int client_socket;
    sockaddr_in server_address;
    unsigned short network_port;
    char buffer[buffer_size]{};

public:
    NetworkClient(unsigned short network_port, std::string ip_address);

    void connect();
    void sendMessage();
    void recieveMessage();
    void handleMessage();
};
#endif