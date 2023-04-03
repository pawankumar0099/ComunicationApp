#ifndef COMMUNICATIONSERVER_H
#define COMMUNICATIONSERVER_H

#include <iostream>

class Communication
{
public:
    virtual void connect() = 0;
    virtual void sendMessage() = 0;
    virtual void recieveMessage() = 0;
    virtual void handleMessage() = 0;
};

#endif