#pragma once

#include "message.hpp"
#include <fstream>
#include <chrono>
#include <iomanip>

class Logger
{
public:
    void log(const Message& msg)
    {
        std::ofstream file(
            "logs/can.log",
            std::ios::app);
        
        auto now =
            std::chrono::system_clock::now();
        
        auto current_time =
            std::chrono::system_clock::to_time_t(now);

        file
            << std::put_time(
                std::localtime(&current_time),
                "%Y-%m-%d %H:%M:%S")
            << ","
            << msg.id
            << ","
            << msg.data
            << std::endl;
    }

};


