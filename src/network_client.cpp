#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/network_client.h"
#include "../include/emojis.h"

// constructor to create socket
NetworkClient::NetworkClient(unsigned short network_port, std::string ip_address)
{
    // create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Failed to create socket" << std::endl;
        throw std::runtime_error("Failed to create socket");
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(network_port);

    if (inet_pton(AF_INET, ip_address.c_str(), &server_address.sin_addr) <= 0)
    {
        std::cerr << "Invalid server address" << std::endl;
        throw std::runtime_error("Invalid server address");
    }
}

// connect to server
void NetworkClient::connect()
{
    if (::connect(client_socket, (sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        std::cerr << "Failed to connect to server" << std::endl;
        throw std::runtime_error("Failed to connect to server");
    }
}

void NetworkClient::sendMessage()
{
    std::string message;
    std::cout << "Enter message : ";
    std::getline(std::cin, message);
    // replacing emojis with unicode
    message = Emojis::replace_with_unicode(message);
    // send message to server
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

void NetworkClient::recieveMessage()
{
    // receive message from server
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
        std::cout << "Received message from server: " << buffer << std::endl;
    }
}

void NetworkClient::handleMessage()
{
    while (1)
    {
        sendMessage();
        recieveMessage();
    }
}