# CPP AP Project

---

## Overview

This repository contains two parts that explore and compare different implementations of a vector class in C++. The goal is to evaluate the performance of these custom implementations against the standard C++ `std::vector`.

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

In the second part, a `Device` class is implemented. This class holds two vectors of shapes, as well as the device itself.

- A custom `operator<<` function is implemented for the `Device` class and associated objects.
- You can experiment with this implementation by running the sample code provided in the `Part2` folder.

---

## Compilation

The code can be compiled using `g++` or `MSVC`.

For convenience, precompiled binaries are available:

- [Download Part1.exe](https://github.com/mdaneshyab/CPP-AP-Project/releases/download/v1.0.0/Part1.exe)
- [Download Part2.exe](https://github.com/mdaneshyab/CPP-AP-Project/releases/download/v1.0.0/Part2.exe)
