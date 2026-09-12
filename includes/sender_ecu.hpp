#pragma once

#include "message.hpp"

// 役割　送信ECU
class SenderECU
{
private:
    int sequence = 0;

public:
    // メッセージを生成
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