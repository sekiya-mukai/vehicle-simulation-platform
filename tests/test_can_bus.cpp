#include "can_bus.hpp"

#include <gtest/gtest.h>

class MockECU : public ECU
{
public:

    bool received = false;

    Message received_msg;

    void recv(
        const Message& msg)
        override
    {
        received = true;

        received_msg = msg;
    }
};

TEST(CANBusTest, MessageTransfer)
{
    MockECU mock;

    CANBus bus(&mock);

    Message msg;

    msg.id = 100;
    msg.sequence = 1;
    msg.data = "speed=60";

    bus.send(msg);

    EXPECT_TRUE(
        mock.received);

    EXPECT_EQ(
        mock.received_msg.id,
        100);

    EXPECT_EQ(
        mock.received_msg.sequence,
        1);

    EXPECT_EQ(
        mock.received_msg.data,
        "speed=60");
}