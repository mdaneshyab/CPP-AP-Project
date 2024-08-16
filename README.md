# CPP AP Project

---

## Overview

This repository contains a C++ project structured in two main parts, each focusing on different aspects of custom data structures and object-oriented design. The first part explores the implementation and performance comparison of custom vector classes against the standard C++ `std::vector`. The second part involves the creation of a complex `Device` class, which models real-world objects by aggregating various shapes and sub-devices, each with their own geometric and physical properties.

The project emphasizes efficient memory management, performance benchmarking, and the practical application of object-oriented principles in C++.

---

## Part 1: Vector Class Comparison

In this part, two custom vector implementations are compared:

1. **Single Pointer Vector (T\*)**: This implementation uses a single pointer for managing the underlying array.
2. **Double Pointer Vector (T\*\*)**: This implementation uses a double pointer for managing the underlying array.

Both custom implementations are benchmarked against `std::vector` from the C++ Standard Library.

### Benchmark Details

The benchmarks were conducted using objects of varying sizes, from 100 \* 1MB objects to 2 \* 50MB objects, keeping the total vector size at 100MB.

- **Results Overview**: The `std::vector` consistently outperformed both custom implementations. The double pointer vector (`T**`) was close in performance to `std::vector`, while the single pointer vector (`T*`) lagged significantly behind.

![Main Results](Results/MainResults.png)

- **Performance Analysis**:
    - The single pointer vector (`T*`) performance is more sensitive to the number of elements.
    - The double pointer vector (`T**`) performance is more sensitive to the size of individual objects.

![Vector Vs Vector Pointer](Results/VectorVsVectorPointer.png)

- **Detailed Comparison with std::vector**:
    - In some cases, the double pointer vector (`T**`) even outperformed `std::vector`, but overall, `std::vector` was the faster choice. This might be due to `std::vector`’s capacity management, where additional memory is pre-allocated. However, when the allocated capacity is filled, `std::vector` can become slower.

![Vector Pointer Vs STD Results](Results/VectorPointerVsSTD_results.png)


---

## Part 2: Device Class with Custom Vectors

In the second part, a `Device` class is implemented. This class models a realistic device, consisting of several shape objects as well as other sub-devices. The `Device` class and its components are designed to represent the complex structure of real-world objects, like an automobile with various parts, both simple and complex.

### Functionalities

The `Device` class includes the following key functionalities:

- **AddShape**: Adds a shape to the device.
- **AddSubDevice**: Adds a sub-device to the device.
- **GetVolume**: Returns the total volume of the device, including all shapes and sub-devices. The volume is calculated by invoking the `EvalVolume` function whenever any shape's dimensions are modified using the `Set` functions.
- **GetSurfaceArea**: Returns the total surface area of the device, including all shapes and sub-devices. The surface area is calculated by invoking the `EvalSurfaceArea` function whenever any shape's dimensions are modified.
- **GetMass**: Returns the total mass of the device, including all shapes and sub-devices. The mass is calculated by invoking the `EvalMass` function whenever any shape's density or volume is modified.

### Shape Classes

The `Shape` class and its derived classes (`Cube`, `Sphere`, `Cylinder`, `Pyramid`) include methods to calculate volume, surface area, and mass based on the shape's dimensions and density. These calculations are done via `Eval` functions, which are triggered whenever relevant properties are set or changed.

Additionally, a custom `operator<<` function is implemented to provide detailed output about the device and its components.

You can experiment with this implementation by running the sample code provided in the `Part2` folder.

---

## Compilation

The code can be compiled using `g++` or `MSVC`.

For convenience, precompiled binaries are available:

- [Download Part1.exe](https://github.com/mdaneshyab/CPP-AP-Project/releases/download/v1.0.0/Part1.exe)
- [Download Part2.exe](https://github.com/mdaneshyab/CPP-AP-Project/releases/download/v1.0.0/Part2.exe)
