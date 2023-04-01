#include <iostream>
#include "../include/communication.h"

#include "../include/communication_object_factory.h"
#include "../include/enums.h"
#include <cstring>
#include <string>
#include <stdexcept>



int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Invalid number of arguments. Usage: " << argv[0] << " network <server/client> <ip_address> <network_port>" << std::endl;
        return 1;
    }

    try
    {
        int com_type = Com_Type::NETWORK;
        char *server_or_client = argv[2];
        char *ip_address = argv[3];
        int network_port = std::stoi(argv[4]);
        unsigned short us_network_port = static_cast<unsigned short>(network_port);

        Communication *communication = CommunicationObjectFactory::getObject(com_type, server_or_client, ip_address, us_network_port);
        communication->handleMessage();

        delete communication;
        communication = nullptr;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
