#pragma once

#include <chrono>
#include <iostream>

class PerformanceMonitor
{
private:

    int count = 0;

    double total_latency = 0.0;

    double min_latency = 999999.0;

    double max_latency = 0.0;

public:

    void record(double latency_ms)
    {
        count++;

        total_latency += latency_ms;

        if (latency_ms < min_latency)
        {
            min_latency = latency_ms;
        }

        if (latency_ms > max_latency)
        {
            max_latency = latency_ms;
        }
    }

    void printReport() const
    {
        std::cout << "\n=== Performance Report ===\n";

        std::cout << "Message Count : "
                  << count
                  << "\n";

        std::cout << "Average Latency : "
                  << total_latency / count
                  << " ms\n";

        std::cout << "Min Latency : "
                  << min_latency
                  << " ms\n";

        std::cout << "Max Latency : "
                  << max_latency
                  << " ms\n";
    }
};
