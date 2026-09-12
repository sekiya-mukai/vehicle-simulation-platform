#include "packet_loss_detector.hpp"

#include <gtest/gtest.h>

TEST(PacketLossDetectorTest, NoLoss)
{
    PacketLossDetector detector;

    detector.check(1);
    detector.check(2);
    detector.check(3);
    detector.check(4);

    EXPECT_EQ(
        detector.getLossCount(),
        0);
}

TEST(PacketLossDetectorTest, DetectLoss)
{
    PacketLossDetector detector;

    detector.check(1);
    detector.check(2);
    // detector.check(3);
    detector.check(4);

    EXPECT_EQ(
        detector.getLossCount(),
        1);
}






