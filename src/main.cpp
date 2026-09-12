#include "sender_ecu.hpp"
#include "recv_ecu.hpp"
#include "can_bus.hpp"

int main()
{
    SenderECU sender;

    RecvECU receiver;

    CANBus bus(&receiver);

    auto msg = sender.createMessage();

    // bus.send(msg);

    for(int i = 0; i < 10000; i++)
    {
        auto msg = sender.createMessage();

        // Cause packet loss Intentionally
        if(i==50)
        {
            continue;
        }

        bus.send(msg);
    }

    bus.printPerformanceReport();
    bus.printPacketLossReport();

    return 0;
}