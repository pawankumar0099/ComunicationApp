#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
class Validator
{
public:
    static bool is_valid_ip(std::string ip_str);
    static int is_valid_port(std::string port_str);
};
#endif