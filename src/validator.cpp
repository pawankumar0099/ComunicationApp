#include "../include/validator.h"
#include <iostream>
#include <regex>

bool Validator::is_valid_ip(std::string ip_str)
{
    // Regular expression pattern for a valid IP address
    std::regex pattern("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");

    // Check if the string matches the pattern
    return std::regex_match(ip_str, pattern);
}

int Validator::is_valid_port(std::string port_str)
{
    std::regex port_regex("^[0-9]+$");
    if (std::regex_match(port_str, port_regex))
    {
        int port = std::stoi(port_str);
        if (port >= 0 && port <= 65535)
        {
            return port;
        }
    }
    return -1;
}