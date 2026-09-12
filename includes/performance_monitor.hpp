#pragma once

#include <chrono>
#include <iostream>

// 役割　通信性能を計測
class PerformanceMonitor
{
private:
    // 総通信数
    int count = 0;
    // 平均遅延
    double total_latency = 0.0;
    // 最小遅延
    double min_latency = 999999.0;
    // 最大遅延
    double max_latency = 0.0;

    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;

public:

    PerformanceMonitor()
    {
        start_time =
            std::chrono::high_resolution_clock::now();
    }

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

        end_time =
            std::chrono::high_resolution_clock::now();
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

        double elapsed_sec =
            std::chrono::duration<double>(
                end_time - start_time).count();

        std::cout
                << "Elapsed Time : "
                << elapsed_sec
                << "sec\n";
        
        // スループット(処理件数/秒)
        std::cout
                << "Throughput : "
                << calculateThroughput()
                << "msg/sec\n";

    }

    double calculateThroughput() const
    {
        double elapsed_sec =
            std::chrono::duration<double>(
                end_time - start_time).count();
        
        if(elapsed_sec <= 0.0)
        {
            return 0.0;
        }

        return count / elapsed_sec;
    }

    int getCount() const
    {
        return count;
    }

    double getAverageLatency() const
    {
        return total_latency / count;

    }

    double getMaxLatency() const
    {
        return max_latency;
    }

    double getMinLatency() const
    {
        return max_latency;
    }

    double getElapsedTime() const
    {
        return std::chrono::duration<double>(
            end_time - start_time).count();
    }

    double getThroughput() const
    {
        return calculateThroughput();
    }




};
