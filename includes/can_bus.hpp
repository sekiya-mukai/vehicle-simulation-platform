#pragma once

#include "ecu.hpp"
#include "logger.hpp"
#include "performance_monitor.hpp"
#include "packet_loss_detector.hpp"

#include <chrono>

class CANBus
{
private:

    ECU* receiver;

    Logger logger;

    PerformanceMonitor monitor;

    PacketLossDetector detector;


public:

    explicit CANBus(ECU* recv)
        : receiver(recv)
    {
    }

    void send(const Message& msg)
    {
        auto start =
            std::chrono::high_resolution_clock::now();

        logger.log(msg);

        receiver->recv(msg);

        auto end =
            std::chrono::high_resolution_clock::now();

        double latency =
            std::chrono::duration<double, std::milli>(
                end - start).count();

        monitor.record(latency);

        // Check packet loss
        detector.check(msg.sequence);

    }

    void printPerformanceReport()
    {
        monitor.printReport();
    }

    void printPacketLossReport()
    {
        detector.printReport();
    }

};