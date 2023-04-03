#ifndef COMMUNICATION_OBJECT_FACTORY_H
#define COMMUNICATION_OBJECT_FACTORY_H
#include "communication.h"

// class to return object
class CommunicationObjectFactory
{
public:
    static Communication *getObject(int argc, char *argv[]);
};

#endif