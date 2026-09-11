#include <linux/can.h>
#include <linux/can/raw.h>

#include <net/if.h>

#include <sys/ioctl.h>
#include <sys/socket.h>

#include <unistd.h>

#include <chrono>
#include <cstring>
#include <iostream>

int main()
{
    int socket_fd =
        socket(PF_CAN, SOCK_RAW, CAN_RAW);

    struct ifreq ifr {};

    std::strcpy(ifr.ifr_name, "vcan0");

    ioctl(socket_fd, SIOCGIFINDEX, &ifr);

    struct sockaddr_can addr {};

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(
        socket_fd,
        reinterpret_cast<struct sockaddr*>(&addr),
        sizeof(addr));

    struct can_frame frame {};

    while(true)
    {
        read(
            socket_fd,
            &frame,
            sizeof(frame));

        uint32_t sequence {};

        uint32_t send_time {};

        std::memcpy(
            &sequence,
            frame.data,
            sizeof(sequence));

        std::memcpy(
            &send_time,
            frame.data + 4,
            sizeof(send_time));

        auto now =
            std::chrono::steady_clock::now();

        uint32_t recv_time =
            static_cast<uint32_t>(
                std::chrono::duration_cast<
                    std::chrono::milliseconds>(
                    now.time_since_epoch())
                .count());

        uint32_t latency =
            recv_time - send_time;

        std::cout
            << "SEQ="
            << sequence
            << " LATENCY="
            << latency
            << " ms"
            << std::endl;
    }

    close(socket_fd);

    return 0;
}