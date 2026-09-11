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

    uint32_t sequence = 0;

    while(true)
    {
        struct can_frame frame {};

        frame.can_id = 0x100;

        frame.can_dlc = 8;

        sequence++;

        auto now =
            std::chrono::steady_clock::now();

        auto timestamp =
            std::chrono::duration_cast<
                std::chrono::microseconds>(
                    now.time_since_epoch())
                .count();

        std::memcpy(
            frame.data,
            &sequence,
            sizeof(sequence));

        write(
            socket_fd,
            &frame,
            sizeof(frame));

        std::cout
            << "SEND seq="
            << sequence
            << std::endl;

        usleep(100000);
    }

    close(socket_fd);

    return 0;
}