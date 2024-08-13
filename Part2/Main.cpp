#include <iostream>
#include "Device.h"

int main()
{
    // Create shapes with specific dimensions and densities
    Cube cube(2.0, 3.0, 4.0, 0.5);
    Sphere sphere(3.0, 0.8);
    Cylinder cylinder(5.0, 2.0, 1.2);
    Pyramid pyramid(6.0, 4.0, 0.9);

    // Display properties of individual shapes
    std::cout << cube << ":\n";
    std::cout << "  Volume: " << cube.GetVolume() << "\n";
    std::cout << "  Surface Area: " << cube.GetSurfaceArea() << "\n";
    std::cout << "  Mass: " << cube.GetMass() << "\n\n";

    std::cout << sphere << ":\n";
    std::cout << "  Volume: " << sphere.GetVolume() << "\n";
    std::cout << "  Surface Area: " << sphere.GetSurfaceArea() << "\n";
    std::cout << "  Mass: " << sphere.GetMass() << "\n\n";

    std::cout << cylinder << ":\n";
    std::cout << "  Volume: " << cylinder.GetVolume() << "\n";
    std::cout << "  Surface Area: " << cylinder.GetSurfaceArea() << "\n";
    std::cout << "  Mass: " << cylinder.GetMass() << "\n\n";

    std::cout << pyramid << ":\n";
    std::cout << "  Volume: " << pyramid.GetVolume() << "\n";
    std::cout << "  Surface Area: " << pyramid.GetSurfaceArea() << "\n";
    std::cout << "  Mass: " << pyramid.GetMass() << "\n\n";

    // Create a device and add shapes to it
    Device device("MyDevice");
    device.AddShape(&cube);
    device.AddShape(&sphere);
    device.AddShape(&cylinder);
    device.AddShape(&pyramid);

    // Display properties of the entire device
    std::cout << "Device Volume: " << device.GetVolume() << "\n";
    std::cout << "Total Surface Area: " << device.GetSurfaceArea() << "\n";
    std::cout << "Total Mass: " << device.GetMass() << "\n\n";

    // Create a sub-device with additional shapes
    Cube smallCube(1.0, 1.0, 1.0, 0.7);
    Sphere smallSphere(2.0, 0.9);
    Device subDevice("SubDevice");
    subDevice.AddShape(&smallCube);
    subDevice.AddShape(&smallSphere);

    // Add the sub-device to the main device
    device.AddSubDevice(&subDevice);

    // Display updated properties of the entire device with the sub-device included
    std::cout << "Updated Device with SubDevice: \n";
    std::cout << "Total Volume: " << device.GetVolume() << "\n";
    std::cout << "Total Surface Area: " << device.GetSurfaceArea() << "\n";
    std::cout << "Total Mass: " << device.GetMass() << "\n";

    return 0;
}
