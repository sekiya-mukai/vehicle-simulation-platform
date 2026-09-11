#include "sender_ecu.hpp"
#include "recv_ecu.hpp"
#include "can_bus.hpp"

int main()
{
    SenderECU sender;

    RecvECU receiver;

    CANBus bus(&receiver);

    auto msg = sender.createMessage();

    bus.send(msg);

    return 0;
}