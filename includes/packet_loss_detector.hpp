#pragma once

#include <iostream>

class PacketLossDetector
{
private:
    int last_sequence = 0;
    int loss_count = 0;

public:
    void check(int current_sequence)
    {
        if(last_sequence != 0)
        {
            if(current_sequence != last_sequence + 1)
            {
                std::cout
                    << "[LOSS DETECTED!]"
                    << "Expected = "
                    << last_sequence + 1
                    << "Received = "
                    << current_sequence
                    << std::endl;
                
                loss_count++;

            }
        }
    
        last_sequence = current_sequence;

    }
    void printReport() const
    // ※const: 本関数内からオブジェクトに関する情報の変更は不可であることを明示
    {
        std::cout
            << "\nPacket Loss Count = "
            << loss_count
            << std::endl;
    }
};


