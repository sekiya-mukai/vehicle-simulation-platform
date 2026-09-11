#pragma once

#include "ecu.hpp"

class CANBus
{
private:
    ECU* receiver;

public:
    explicit CANBus(ECU* recv)
        : receiver(recv)
    {
    }

    void send(const Message& msg)
    {
        receiver->recv(msg);
    }
};