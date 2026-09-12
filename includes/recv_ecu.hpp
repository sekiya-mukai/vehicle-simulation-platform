#pragma once

#include "ecu.hpp"
#include <iostream>

// 役割　受信ECU
class RecvECU : public ECU
{
public:
    void recv(const Message& msg) override
    {
        // 受信処理WO行う関数だが、今の実装は「Receive ID=100 DATA=speed=60」のように表示するだけ
        std::cout
            << "Receive ID="
            << msg.id
            << " DATA="
            << msg.data
            << std::endl;
    }
};