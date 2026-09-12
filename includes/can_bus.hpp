#pragma once

#include "ecu.hpp"
#include "logger.hpp"
#include "performance_monitor.hpp"
#include "packet_loss_detector.hpp"

#include <chrono>

// CAN通信路を模擬（通信を中継する管理クラス）
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
        // Loggerへ通知
        logger.log(msg);
        // メッセージをRecvECUへ転送
        receiver->recv(msg);

        auto end =
            std::chrono::high_resolution_clock::now();

        double latency =
            std::chrono::duration<double, std::milli>(
                end - start).count();
        // PerformanceMonitorへ通知
        monitor.record(latency);

        // PacketLossDetectorへ通知(シーケンス番号を監視)
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

    // Getter
    int getMessageCount() const
    {
        return monitor.getCount();
    }

    double getAverageLatency() const
    {
        return monitor.getAverageLatency();
    }

    double getMinLatency() const
    {
        return monitor.getMinLatency();
    }

    double getMaxLatency() const
    {
        return monitor.getMaxLatency();
    }

    double getElapsedTime() const
    {
        return monitor.getElapsedTime();
    }

    double getThroughput() const
    {
        return monitor.getThroughput();
    }

    int getPacketLossCount() const
    {
        return detector.getLossCount();
    }

};