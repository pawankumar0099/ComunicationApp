#include <iostream>
#include "../include/communication.h"
#include "../include/communication_object_factory.h"

int main(int argc, char *argv[])
{
    // user did't provide any cmdline arguments
    if (argc == 1)
    {
        std::cout << "Opstions :" << std::endl
                  << "\t network" << std::endl
                  << "\t\t server \t start application as a server" << std::endl
                  << "\t\t client \t start application as a client" << std::endl
                  << "\t\t ip address \t provide ip address" << std::endl
                  << "\t\t port \t\t provide port of application" << std::endl
                  << std::endl;

        std::cerr << "Use: " << argv[0] << " network <server/client> <ip_address> <network_port>" << std::endl;
        return 1;
    }

    try
    {
        // creating object
        Communication *communication = CommunicationObjectFactory::getObject(argc, argv);
        communication->connect();
        communication->handleMessage();

        delete communication;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
