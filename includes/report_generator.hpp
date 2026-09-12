#pragma once

#include <fstream>
#include <string>

class ReportGenerator
{
public:

    void generate(
        int message_count,
        double avg_latency,
        double min_latency,
        double max_latency,
        double elapsed_time,
        double throughput,
        int packet_loss_count)
    {
        std::ofstream report(
            "reports/report.txt");
        
        report
            << "== Vehicle Communication Report ==\n\n";

        report
            << "Message Count : "
            << message_count
            << "\n";
            
        report
            << "Average Latency : "
            << avg_latency
            << " ms\n";

        report
            << "Min Latency : "
            << min_latency
            << " ms\n";

        report
            << "Max Latency : "
            << max_latency
            << " ms\n";

        report
            << "Elased Time : "
            << elapsed_time
            << " sec\n";

        report
            << "Throughput : "
            << throughput
            << " msg/sec\n";

        report
            << "Packet Loss Count : "
            << packet_loss_count
            << "\n";
    }
};
