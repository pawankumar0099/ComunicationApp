#include <iostream>
#include "../include/communication_object_factory.h"
#include "../include/enums.h"
#include <cstring>
#include "../include/network_server.h"
#include "../include/network_client.h"

Communication *CommunicationObjectFactory::getObject(int com_type, char *server_or_client, char *ip_address, unsigned short network_port)
{
    switch (com_type)
    {
    case NETWORK:
    {
        if (strcmp(server_or_client, "server") == 0)
        {
            return new NetworkServer(network_port, ip_address);
        }
        else if (strcmp(server_or_client, "client") == 0)
        {
            return new NetworkClient(network_port, ip_address);
        }
        else
        {
            throw std::invalid_argument("Invalid input");
        }
        break;
    default:
        throw std::invalid_argument("Invalid communication type");
        break;
    }
    }
}