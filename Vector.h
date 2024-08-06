#pragma once
#include <iostream>
#include <stdexcept>  // For std::out_of_range

template <class T>
class Vector {
private:
    unsigned int m_size; // Array size
    T* m_data; // Array pointer

public:
    // Constructor
    Vector(unsigned int Size = 0, T init = T())
        : m_size(Size), m_data(new T[Size]) 
    {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = init;
        }
    }

    // Copy constructor
    Vector(const Vector& other)
        : m_size(other.m_size), m_data(new T[other.m_size]) 
    {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    // Move constructor
    Vector(Vector&& other) noexcept
        : m_size(other.m_size), m_data(other.m_data) 
    {
        other.m_size = 0;
        other.m_data = nullptr;
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other) 
    {
        if (this != &other) {
            T* newData = new T[other.m_size];
            for (size_t i = 0; i < other.m_size; ++i) {
                newData[i] = other.m_data[i];
            }
            delete[] m_data;
            m_data = newData;
            m_size = other.m_size;
        }
        return *this;
    }

    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept 
    {
        if (this != &other) {
            delete[] m_data;
            m_data = other.m_data;
            m_size = other.m_size;
            other.m_data = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    // Destructor
    ~Vector() {
        delete[] m_data;
    }

    // Get size
    unsigned int GetSize() const {
        return m_size;
    }

    // Resize the vector
    void Resize(unsigned int newSize, T init = T()) {
        if (newSize == m_size) return;

        T* temp = new T[newSize];
        for (size_t i = 0; i < newSize; ++i) {
            if (i < m_size) temp[i] = m_data[i];
            else temp[i] = init;
        }
        delete[] m_data;
        m_data = temp;
        m_size = newSize;
    }

    // Add an element at the end
    void PushBack(T value) {
        Resize(m_size + 1);
        m_data[m_size - 1] = value;
    }

    // Insert an element at a specific position
    void Insert(unsigned int index, T value = T()) {
        if (index > m_size) {
            throw std::out_of_range("Index out of bounds");
        }
        Resize(m_size + 1);
        for (size_t i = m_size - 1; i > index; --i) {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = value;
    }

    // Remove an element at a specific position
    void Remove(unsigned int index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of bounds");
        }
        for (size_t i = index; i < m_size - 1; ++i) {
            m_data[i] = m_data[i + 1];
        }
        Resize(m_size - 1);
    }

    // Clear the vector
    void Clear() {
        Resize(0);
    }

    // Access element by index
    T& operator[](int index) {
        if (index >= static_cast<int>(m_size) || index < 0) {
            throw std::out_of_range("Array index out of bounds");
        }
        return m_data[index];
    }

    // Access element by index (const version)
    const T& operator[](int index) const {
        if (index >= static_cast<int>(m_size) || index < 0) {
            throw std::out_of_range("Array index out of bounds");
        }
        return m_data[index];
    }
    // return the size of whole array in mage bytes
    double GetSizeOfAllEements()
    {
        double result = sizeof(T) * m_size;// in bytes
        result /= 1024; // in kilo bytes
        result /= 1024; // in mega Bytes
        return result;
    }
};
