#pragma once

#include "ecu.hpp"
#include <iostream>

class RecvECU : public ECU
{
public:
    void recv(const Message& msg) override
    {
        std::cout
            << "Receive ID="
            << msg.id
            << " DATA="
            << msg.data
            << std::endl;
    }
};