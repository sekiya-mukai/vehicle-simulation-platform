#pragma once

#include "message.hpp"

class ECU
{
public:
    virtual void recv(const Message& msg) = 0;

    virtual ~ECU() = default;
};