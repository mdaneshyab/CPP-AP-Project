#include <iostream>
#include "Device.h"

int main()
{
    // Create a device and add shapes to it
    Device device("Mian Device");
    // Create shapes with dimensions and densities
    {
        Cube cube(2.0, 3.5, 4.0, 1.2);
        Sphere sphere(3.3, 0.8);
        Cylinder cylinder(5.1, 2.0, 1.4);
        Pyramid pyramid(6.0, 4.0, 0.7);

        device.AddShape(cube);
        device.AddShape(sphere);
        device.AddShape(cylinder);
        device.AddShape(pyramid);
    }
    // Create a sub-device and add to device
    {
        Device subDevice("SubDevice1");
        Cube smallCube(1.0, 1.0, 1.0, 0.7);
        Sphere smallSphere(2.0, 0.9);

        subDevice.AddShape(smallCube);
        subDevice.AddShape(smallSphere);
        device.AddSubDevice(subDevice);
    }
    // Create a sub-device and add to device
    {
        Device subDevice("SubDevice2");

        device.AddSubDevice(subDevice);
    }

    // Display updated properties of the entire device with the sub-device included
    std::cout << device << std::endl;
    
    std::getchar();
    return 0;
}
