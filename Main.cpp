#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include "Vector.h"
#include "VectorPointer.h"
#include "Timer.h"
#define Samplecount 20
// Helper function to generate a large object
struct LargeObject {
    std::vector<char> data;
    LargeObject(size_t size_in_mb = 1) : data(size_in_mb * 1024 *1024) {}
};

// Struct to hold object size and count pairs
struct vec2 {
    int x; // Object size in MB
    int y; // Number of objects
};

void ShowBar(int length, double percent)
{
    std::cout << '\r' << '|';
    for (size_t i = 0; i < length; i++)
    {

        if (i < percent / 100 * length) std::cout << '*';
        else std::cout << '_';
    }
    std::cout  << '|' << percent << '%';
}

// Function to run the tests
template <typename VectorType>
void run_test( std::vector<double>& insert_times, std::vector<double>& remove_times,
                                unsigned int object_size_in_mb, unsigned int num_objects,
                                unsigned int sample_count) 
{

    VectorType vec(num_objects, LargeObject(object_size_in_mb));
    Timer timer;

    
    for (unsigned int i = 1; i <= sample_count; ++i) {
        ShowBar(50, ((double)i / sample_count) * 100 ) ;
        // Measure insert times
        timer.start();
        vec.Insert(0, LargeObject(object_size_in_mb));
        timer.stop();
        insert_times.push_back(timer.milliseconds());
        // Measure remove times
        timer.start();
        vec.Remove(0);
        timer.stop();
        remove_times.push_back(timer.milliseconds());
    }

    
    
}

int main() {
    //Test 01
    {
    // Generate test cases
    std::vector<vec2> sizes_and_counts;
    for (int j = 1; j <= 50; j++)
    {
        
        vec2 th = { j, 100 / j };
        sizes_and_counts.push_back(th);
        
    }

    // Vectors to store average times
    std::vector<std::vector<double>> vector_insert_averages;
    std::vector<std::vector<double>> vector_remove_averages;
    std::vector<std::vector<double>> vector_pointer_insert_averages;
    std::vector<std::vector<double>> vector_pointer_remove_averages;

    for (const auto& size_count : sizes_and_counts) {
        std::vector<double> vector_insert_times;
        std::vector<double> vector_remove_times;
        std::vector<double> vector_pointer_insert_times;
        std::vector<double> vector_pointer_remove_times;
        
        std::cout << "Running test for Vector with object size " << size_count.x << "MB and " << size_count.y << " objects..." << std::endl;
        run_test<Vector<LargeObject>>( vector_insert_times, vector_remove_times, size_count.x, size_count.y, Samplecount);
        std::cout << std::endl;

        std::cout << "Running test for VectorPointer with object size " << size_count.x << "MB and " << size_count.y << " objects..." << std::endl;
        run_test<VectorPointer<LargeObject>>( vector_pointer_insert_times, vector_pointer_remove_times, size_count.x, size_count.y, Samplecount);
        std::cout << std::endl << std::endl;

        vector_insert_averages.push_back(vector_insert_times);
        vector_remove_averages.push_back(vector_remove_times);
        vector_pointer_insert_averages.push_back(vector_pointer_insert_times);
        vector_pointer_remove_averages.push_back(vector_pointer_remove_times);
    }

    // Write results to CSV file
    std::ofstream csv_file("PerformanceResults1.csv");
    csv_file << "ObjectSizeMB,Vector Count,Vector Insert,Vector Remove,VectorPointer Insert,VectorPointer Remove\n";

    for (size_t i = 0; i < sizes_and_counts.size(); ++i) {
        double vector_insert_avg = std::accumulate(vector_insert_averages[i].begin(), vector_insert_averages[i].end(), 0.0) / vector_insert_averages[i].size();
        double vector_remove_avg = std::accumulate(vector_remove_averages[i].begin(), vector_remove_averages[i].end(), 0.0) / vector_remove_averages[i].size();
        double vector_pointer_insert_avg = std::accumulate(vector_pointer_insert_averages[i].begin(), vector_pointer_insert_averages[i].end(), 0.0) / vector_pointer_insert_averages[i].size();
        double vector_pointer_remove_avg = std::accumulate(vector_pointer_remove_averages[i].begin(), vector_pointer_remove_averages[i].end(), 0.0) / vector_pointer_remove_averages[i].size();

        csv_file << sizes_and_counts[i].x << "," 
            << sizes_and_counts[i].y << ","
            << vector_insert_avg << ","
            << vector_remove_avg << ","
            << vector_pointer_insert_avg << ","
            << vector_pointer_remove_avg << "\n";
    }

    csv_file.close();
    std::cout << "Performance results written to PerformanceResults1.csv\n";
    }

    //Test 02
    {
        // Generate test cases
        std::vector<vec2> sizes_and_counts;
        for (int j = 1; j <= 50; j++)
        {

            vec2 th = { j, 50 };
            sizes_and_counts.push_back(th);

        }

        // Vectors to store average times
        std::vector<std::vector<double>> vector_insert_averages;
        std::vector<std::vector<double>> vector_remove_averages;
        std::vector<std::vector<double>> vector_pointer_insert_averages;
        std::vector<std::vector<double>> vector_pointer_remove_averages;

        for (const auto& size_count : sizes_and_counts) {
            std::vector<double> vector_insert_times;
            std::vector<double> vector_remove_times;
            std::vector<double> vector_pointer_insert_times;
            std::vector<double> vector_pointer_remove_times;

            std::cout << "Running test for Vector with object size " << size_count.x << "MB and " << size_count.y << " objects..." << std::endl;
            run_test<Vector<LargeObject>>(vector_insert_times, vector_remove_times, size_count.x, size_count.y, Samplecount);
            std::cout << std::endl;

            std::cout << "Running test for VectorPointer with object size " << size_count.x << "MB and " << size_count.y << " objects..." << std::endl;
            run_test<VectorPointer<LargeObject>>(vector_pointer_insert_times, vector_pointer_remove_times, size_count.x, size_count.y, Samplecount);
            std::cout << std::endl << std::endl;

            vector_insert_averages.push_back(vector_insert_times);
            vector_remove_averages.push_back(vector_remove_times);
            vector_pointer_insert_averages.push_back(vector_pointer_insert_times);
            vector_pointer_remove_averages.push_back(vector_pointer_remove_times);
        }

        // Write results to CSV file
        std::ofstream csv_file("PerformanceResults2.csv");
        csv_file << "ObjectSizeMB,Vector Count,Vector Insert,Vector Remove,VectorPointer Insert,VectorPointer Remove\n";

        for (size_t i = 0; i < sizes_and_counts.size(); ++i) {
            double vector_insert_avg = std::accumulate(vector_insert_averages[i].begin(), vector_insert_averages[i].end(), 0.0) / vector_insert_averages[i].size();
            double vector_remove_avg = std::accumulate(vector_remove_averages[i].begin(), vector_remove_averages[i].end(), 0.0) / vector_remove_averages[i].size();
            double vector_pointer_insert_avg = std::accumulate(vector_pointer_insert_averages[i].begin(), vector_pointer_insert_averages[i].end(), 0.0) / vector_pointer_insert_averages[i].size();
            double vector_pointer_remove_avg = std::accumulate(vector_pointer_remove_averages[i].begin(), vector_pointer_remove_averages[i].end(), 0.0) / vector_pointer_remove_averages[i].size();

            csv_file << sizes_and_counts[i].x << ","
                << sizes_and_counts[i].y << ","
                << vector_insert_avg << ","
                << vector_remove_avg << ","
                << vector_pointer_insert_avg << ","
                << vector_pointer_remove_avg << "\n";
        }

        csv_file.close();
        std::cout << "Performance results written to PerformanceResults2.csv\n";
    }
    return 0;
}
