#pragma once

#include "message.hpp"

class SenderECU
{
public:
    Message createMessage()
    {
        Message msg;

        msg.id = 100;
        msg.data = "speed=60";

        return msg;
    }
};