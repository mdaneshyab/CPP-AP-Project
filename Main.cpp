#include <iostream>
#include "Vector.h"   
#include "Shapes.h"  
#include "Timer.h"    
#include "VectorPointer.h"

#define SampleCount 10
void showBar(int length, double percent)
{
    std::cout << "\r";
    std::cout << '|';
    for (int j = 0; j <= length; j++)
    {
        if (j <= percent * length + (0.1 *length) ) std::cout << '*';
        else std::cout << '_';

    }
    std::cout << '|';
}
int main() {
    for (size_t i = 1; i <= 100; i++)
    {


        Vector<Shape> a(1024 *1024 * i /8);
        std::cout << "The size of array is :" << a.GetSizeOfAllEements() << " MB\n";
        Timer t;
        double sumOfInsertSamples = 0;
        double sumOfRemoveSamples = 0;
        Cube testElemnt(2, 2, 2);
        for (size_t i = 0; i < SampleCount; i++)
        {
            t.start();
            a.Insert(0, testElemnt);
            t.stop();
            sumOfInsertSamples += t.milliseconds();

            t.start();
            a.Remove(0);
            t.stop();
            sumOfRemoveSamples += t.milliseconds();
            showBar(50, (double)i / SampleCount);


        }
        std::cout << "\nThe insertion time is: " << sumOfInsertSamples / SampleCount << " ms\n";
        std::cout << "The removation time is: " << sumOfRemoveSamples / SampleCount << " ms\n\n";
    }
    return 0;
}