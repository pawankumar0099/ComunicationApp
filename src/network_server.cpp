#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/network_server.h"
#include "../include/emojis.h"
#include "../include/constant.h"

// constructor to create a socket,bind and listen
NetworkServer::NetworkServer(unsigned short network_port, std::string ip_address)
{
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << "Failed to create socket" << std::endl;
        throw std::runtime_error("Failed to create socket");
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address.c_str());
    server_address.sin_port = htons(network_port);

    // bind socket to server address
    if (bind(server_socket, (sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        std::cerr << "Failed to bind socket to address" << std::endl;
        throw std::runtime_error("Failed to bind socket to address");
    }

    // listen for incoming connections
    if (listen(server_socket, backlog_queue) < 0)
    {
        std::cerr << "Failed to listen for incoming connections" << std::endl;
        throw std::runtime_error("Failed to listen for incoming connections");
    }
    std::cout << "Server listening on port " << network_port << std::endl;
}

void NetworkServer::connect()
{
    socklen_t client_address_len = sizeof(client_address);
    if ((client_socket = accept(server_socket, (sockaddr *)&client_address, &client_address_len)) < 0)
    {
        std::cerr << "Failed to accept incoming connection" << std::endl;
        throw std::runtime_error("Failed to accept incoming connection");
    }

    std::cout << "Client connected" << std::endl;
}

void NetworkServer::sendMessage()
{
    std::string message;
    std::cout << "Enter message : ";
    std::getline(std::cin, message);
    message = Emojis::replace_with_unicode(message);
    int bytes_sent = ::send(client_socket, message.c_str(), message.length(), 0);
    if (bytes_sent == -1)
    {
        throw std::runtime_error("Error in sending message");
    }
    else if (bytes_sent != message.length())
    {
        throw std::runtime_error("complete message not sent");
    }
}

void NetworkServer::recieveMessage()
{
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = ::recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received == -1)
    {
        throw std::runtime_error("Error receiving message");
    }
    else if (bytes_received == 0)
    {
        throw std::runtime_error("Connection closed");
    }
    else
    {
        std::cout << "Received message from client: " << buffer << std::endl;
    }
}

void NetworkServer::handleMessage()
{
    while (1)
    {
        recieveMessage();
        sendMessage();
    }
}