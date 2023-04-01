#include <iostream>
#include "../include/emojis.h"

std::string Emojis::replace_with_unicode(std::string message)
{
    while (message.find(":)") != std::string::npos)
        message.replace(message.find(":)"), sizeof(":)") - 1, "\U0001F60A");

    while (message.find(":(") != std::string::npos)
        message.replace(message.find(":("), sizeof(":(") - 1, "\U0001F614");

    while (message.find("<3") != std::string::npos)
        message.replace(message.find("<3"), sizeof("<3") - 1, "\u2764\ufe0f");

    while (message.find("(y)") != std::string::npos)
        message.replace(message.find("(y)"), sizeof("(y)") - 1, "\U0001F44D");

    return message;
}