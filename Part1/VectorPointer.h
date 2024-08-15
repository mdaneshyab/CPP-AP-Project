#pragma once
#include <iostream>
#include <stdexcept>  // For std::out_of_range

template <typename T>
class VectorPointer {
private:
    unsigned int m_size; // Array size
    T** m_data; // Array pointer

public:
    // Constructor
    VectorPointer(unsigned int size = 0, T init = T())
        : m_size(size) 
    {
        m_data = new T * [m_size];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = new T(init);
        }
    }

    // Copy constructor
    VectorPointer(const VectorPointer& other)
        : m_size(other.m_size) {
        m_data = new T * [m_size];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = new T(*other.m_data[i]);
        }
    }

    // Move constructor
    VectorPointer(VectorPointer&& other) noexcept
        : m_size(other.m_size), m_data(other.m_data) {
        other.m_size = 0;
        other.m_data = nullptr;
    }

    // Copy assignment operator
    VectorPointer& operator=(const VectorPointer& other) {
        if (this != &other) {
            // Clean up old resources
            for (size_t i = 0; i < m_size; ++i) {
                delete m_data[i];
            }
            delete[] m_data;

            // Allocate new resources
            m_size = other.m_size;
            m_data = new T * [m_size];
            for (size_t i = 0; i < m_size; ++i) {
                m_data[i] = new T(*other.m_data[i]);
            }
        }
        return *this;
    }

    // Move assignment operator
    VectorPointer& operator=(VectorPointer&& other) noexcept {
        if (this != &other) {
            // Clean up old resources
            for (size_t i = 0; i < m_size; ++i) {
                delete m_data[i];
            }
            delete[] m_data;

            // Transfer resources from other
            m_size = other.m_size;
            m_data = other.m_data;
            other.m_size = 0;
            other.m_data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~VectorPointer() {
        for (size_t i = 0; i < m_size; ++i) {
            delete m_data[i];
        }
        delete[] m_data;
    }

    // Get size
    unsigned int GetSize() const {
        return m_size;
    }

    // Resize the vector
    void  Resize(unsigned int newSize, T init = T()) {
        T** temp = new T * [newSize];
        for (size_t i = 0; i < newSize; ++i) {
            if (i < m_size) {
                temp[i] = m_data[i];
            }
            else {
                temp[i] = new T(init);
            }
        }
        // Clean up old resources
        for (size_t i = newSize; i < m_size; ++i) {
            delete m_data[i];
        }
        delete[] m_data;
        m_data = temp;
        m_size = newSize;
    }

    // Add an element at the end
    void PushBack(T& value) {
        Resize(m_size + 1);
        m_data[m_size - 1] = new T(value);
    }

    // Insert an element at a specific position
    void Insert(unsigned int index,const T& value = T()) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of bounds");
        }
        Resize(m_size + 1);
        delete m_data[m_size - 1];
        for (size_t i = m_size - 1; i > index; --i) {
            m_data[i] = m_data[i - 1];
        }
        
        m_data[index] =  new T(value);
    }

    // Remove an element at a specific position
    void Remove(unsigned int index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of bounds");
        }
        delete m_data[index];
        for (size_t i = index; i < m_size - 1; ++i) {
            m_data[i] = m_data[i + 1];
        }
        m_size--;
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
        return *m_data[index];
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
