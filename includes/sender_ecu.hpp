#pragma once

#include "message.hpp"

class SenderECU
{
private:
    int sequence = 0;

public:
    Message createMessage()
    {
        Message msg;

        sequence++;

        msg.sequence = sequence;
        msg.id = 100;
        msg.data = "speed=60";

        return msg;
    }
};