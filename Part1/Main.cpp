#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "Vector.h"
#include "VectorPointer.h"
#include "Timer.h"
#define Samplecount  10
#define ArrayTotalSize  100 // in MB


// Helper function to generate a large object
struct LargeObject {
    std::vector<char> data;
    LargeObject(size_t size_in_mb = 1) : data(size_in_mb * 1024 * 1024) {}
};

// Struct to hold object  pairs
struct vec2 {
    int x;
    int y;
};

void ShowBar(int length, double percent)
{
    std::cout << '\r' << '|';
    int filledLength = static_cast<int>(percent / 100 * length);
    for (int i = 0; i < length; i++) {
        if (i < filledLength) std::cout << '*';
        else std::cout << '_';
    }
    std::cout << '|' << percent << '%' << std::flush;
}

int main() {


    // Generate test cases
    std::vector<vec2> sizes_and_counts;
    for (int j = 1; j <= ArrayTotalSize / 2; j++) {
        vec2 th = { j, ArrayTotalSize / j };
        sizes_and_counts.push_back(th);
    }

    // Vectors to store average times
    std::vector<double> vector_insert_averages;
    std::vector<double> vector_remove_averages;
    std::vector<double> vector_pointer_insert_averages;
    std::vector<double> vector_pointer_remove_averages;
    std::vector<double> vector_std_insert_averages;
    std::vector<double> vector_std_remove_averages;

    for (const auto& size_count : sizes_and_counts) {

        double insert_times_vector = 0;
        double remove_times_vecotr = 0;
        double insert_times_vectorPointer = 0;
        double remove_times_vecotrPointer = 0;
        double insert_times_vector_std = 0;
        double remove_times_vecotr_std = 0;

        std::cout << "Running test case with object size " << size_count.x << "MB and " << size_count.y << " objects:" << std::endl;
        for (size_t i = 1; i <= Samplecount; i++)
        {
            ShowBar(50, (double)i / Samplecount * 100);
            Vector<LargeObject> t1(size_count.y, LargeObject(size_count.x));
            VectorPointer<LargeObject> t2(size_count.y, LargeObject(size_count.x));
            std::vector<LargeObject> t3(size_count.y, LargeObject(size_count.x));
            Timer timer;

            LargeObject th(size_count.x);
            timer.start();
            t1.Insert(0, th );
            timer.stop();
            insert_times_vector += timer.milliseconds();

            timer.start();
            t1.Remove(0);
            timer.stop();
            remove_times_vecotr += timer.milliseconds();


            timer.start();
            t2.Insert(0, th );
            timer.stop();
            insert_times_vectorPointer += timer.milliseconds();

            timer.start();
            t2.Remove(0);
            timer.stop();
            remove_times_vecotrPointer += timer.milliseconds();

            timer.start();
            t3.insert(t3.begin(), th);
            timer.stop();
            insert_times_vector_std += timer.milliseconds();

            timer.start();
            t2.Remove(0);
            timer.stop();
            remove_times_vecotr_std += timer.milliseconds();

        }

        

        



        vector_insert_averages.push_back(insert_times_vector / Samplecount);
        vector_remove_averages.push_back(remove_times_vecotr / Samplecount);
        vector_pointer_insert_averages.push_back(insert_times_vectorPointer / Samplecount);
        vector_pointer_remove_averages.push_back(remove_times_vecotrPointer / Samplecount);
        vector_std_insert_averages.push_back(insert_times_vector_std / Samplecount);
        vector_std_remove_averages.push_back(remove_times_vecotr_std / Samplecount);

        system("CLS");


    }

    
    // Write results to CSV file
    std::string fileName = "PerformanceResults";
    std::ofstream csv_file(fileName + ".csv");
    csv_file << "Object Size (MB),Vector Count,Vector Insert,Vector Remove,VectorPointer Insert,VectorPointer Remove,std::vector Insert,std::vector Remove\n";

    for (size_t i = 0; i < sizes_and_counts.size(); ++i) {


        csv_file << sizes_and_counts[i].x << ","
            << sizes_and_counts[i].y << ","
            << vector_insert_averages[i] << ","
            << vector_remove_averages[i] << ","
            << vector_pointer_insert_averages[i] << ","
            << vector_pointer_remove_averages[i] << ","
            << vector_std_insert_averages[i] << ","
            << vector_std_remove_averages[i] << "\n";
    }

    csv_file.close();
    std::cout << "Performance results written to PerformanceResults1" << fileName << ".csv\n";



    return 0;
}