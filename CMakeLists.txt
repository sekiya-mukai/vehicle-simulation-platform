cmake_minimum_required(VERSION 3.16)

project(
    VehicleSimulationPlatform
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    includes)

enable_testing()

#
# Main Application
#

add_executable(
    simulator
    src/main.cpp)

#
# GoogleTest
#

find_package(
    GTest REQUIRED)

#
# Packet Loss Test
#

add_executable(
    test_packet_loss
    tests/test_packet_loss.cpp)

target_link_libraries(
    test_packet_loss
    GTest::gtest
    GTest::gtest_main)

add_test(
    NAME PacketLossTest
    COMMAND test_packet_loss)

#
# Sender Test
#

add_executable(
    test_sender
    tests/test_sender.cpp)

target_link_libraries(
    test_sender
    GTest::gtest
    GTest::gtest_main)

add_test(
    NAME SenderTest
    COMMAND test_sender)

#
# CANBus Test
#

add_executable(
    test_can_bus
    tests/test_can_bus.cpp)

target_link_libraries(
    test_can_bus
    GTest::gtest
    GTest::gtest_main)

add_test(
    NAME CANBusTest
    COMMAND test_can_bus)