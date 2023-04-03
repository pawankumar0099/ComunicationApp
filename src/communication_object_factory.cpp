#include <iostream>
#include <cstring>
#include "../include/enums.h"
#include "../include/communication_object_factory.h"
#include "../include/network_server.h"
#include "../include/network_client.h"
#include "../include/validator.h"


// convert string into enum
communication_type stringToEnum(const std::string &str)
{
    if (str == "network")
    {
        return communication_type::NETWORK;
    }
    else
    {
        throw std::invalid_argument("Invalid communication_type: " + str + " you can enter network only");
    }
}

// Object Factory
Communication *CommunicationObjectFactory::getObject(int argc, char *argv[])
{
    int communication_type = stringToEnum(argv[1]);

    switch (communication_type)
    {
    case NETWORK:
    {
        // for network communication 4 arguments required
        if (argc < 5)
        {
            std::cerr << "Invalid number of arguments. Use: " << argv[0] << " network <server/client> <ip_address> <network_port>" << std::endl;
            throw std::invalid_argument("Invalid input");
        }
        try
        { // start application as server or client
            std::string server_or_client = argv[2];
            std::string ip_address = argv[3];
            std::string port_str = argv[4];
            if (!Validator::is_valid_ip(ip_address))
            {
                throw std::invalid_argument("Invalid IP address");
            }
            int network_port = Validator::is_valid_port(port_str);
            if (network_port == -1)
            {
                throw std::invalid_argument("Invalid port");
            }

            if (server_or_client == "server")
            {
                // retuen Server object
                return new NetworkServer(network_port, ip_address);
            }
            else if (server_or_client == "client")
            {
                // return client object
                return new NetworkClient(network_port, ip_address);
            }
            else
            {
                throw std::invalid_argument("Invalid input : please enter server or client");
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
            throw std::invalid_argument("Invalid input");
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            throw std::invalid_argument("enter valid port");
        }

        break;
    default:
        throw std::invalid_argument("Invalid communication type this application support only network communication");
        break;
    }
    }
}