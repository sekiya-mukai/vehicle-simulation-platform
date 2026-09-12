#include "sender_ecu.hpp"

#include <gtest/gtest.h>


TEST(SenderECUTest, CreateMessage)
{
    SenderECU sender;
    
    auto msg = sender.createMessage();

    EXPECT_EQ(msg.id, 100);

    EXPECT_EQ(
        msg.data,
        "speed=60");
}


TEST(SenderECUTest, SequenceIncrement)
{
    SenderECU sender;

    auto msg1 =
        sender.createMessage();

    auto msg2 =
        sender.createMessage();

    EXPECT_EQ(
        msg2.sequence,
        msg1.sequence + 1);
}












