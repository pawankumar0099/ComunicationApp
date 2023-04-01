#ifndef COMMUNICATION_OBJECT_FACTORY_H
#define COMMUNICATION_OBJECT_FACTORY_H
#include "communication.h"

class CommunicationObjectFactory
{
public:
    static Communication *getObject(int com_type, char *server_or_client, char *ip_address, unsigned short network_port);
};


#endif