#include "sender_ecu.hpp"
#include "recv_ecu.hpp"
#include "can_bus.hpp"
#include "report_generator.hpp"

int main()
{
    SenderECU sender;

    RecvECU receiver;

    CANBus bus(&receiver);

    for(int i = 0; i < 10000; i++)
    {
        auto msg = sender.createMessage();

        if(i == 50)
        {
            continue;
        }

        bus.send(msg);
    }

    bus.printPerformanceReport();

    bus.printPacketLossReport();

    ReportGenerator generator;

    generator.generate(
        bus.getMessageCount(),
        bus.getAverageLatency(),
        bus.getMinLatency(),
        bus.getMaxLatency(),
        bus.getElapsedTime(),
        bus.getThroughput(),
        bus.getPacketLossCount());
    
        /*
        上の実装で、以下の出力を得ることができる

        === Performance Report ===
        Message Count : 9999
        Average Latency : 0.10342 ms
        Min Latency : 0.017533 ms
        Max Latency : 5.08759 ms
        Elapsed Time : 1.04022sec
        Throughput : 9612.38msg/sec

        Packet Loss Count = 1

        */

    return 0;
}