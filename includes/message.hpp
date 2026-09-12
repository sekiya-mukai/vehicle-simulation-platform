#pragma once

#include <string>


/*
Message
役割

通信で送受信されるデータを表すクラスです。
*/


struct Message
{
    // メッセージID
    int id;
    // 通信順序番号
    std::string data;
    // 実際のデータ
    unsigned int sequence;
};
