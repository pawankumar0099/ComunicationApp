#include <iostream>
#include "../include/communication.h"
#include "../include/communication_object_factory.h"

int main(int argc, char *argv[])
{
    // user did't provide any cmdline arguments
    if (argc < 2)
    {
        std::cerr << "Invalid number of arguments. Use: " << argv[0] << " network <server/client> <ip_address> <network_port>" << std::endl;
        return 1;
    }

    try
    {
        // creating object
        Communication *communication = CommunicationObjectFactory::getObject(argc, argv);
        communication->connect();
        communication->handleMessage();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "runtime error occured" << std::endl;
    }

    return 0;
}
