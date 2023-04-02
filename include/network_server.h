#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H
#include "communication.h"
#include <arpa/inet.h>
#include "constant.h"

class NetworkServer : public Communication
{
private:
    int server_socket;
    int client_socket;
    sockaddr_in server_address, client_address;
    unsigned short network_port;
    char buffer[buffer_size]{};

public:
    NetworkServer(unsigned short network_port, char *ip_address);

    void connect();
    void sendMessage();
    void recieveMessage();
    void handleMessage();
};

#endif