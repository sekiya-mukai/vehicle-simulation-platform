#pragma once

#include "message.hpp"

/*
ECU
役割

ECUの共通インターフェースです。
*/
class ECU
{
public:
    //  = 0: 抽象クラスのため、直接生成不可
    virtual void recv(const Message& msg) = 0;

    virtual ~ECU() = default;
};