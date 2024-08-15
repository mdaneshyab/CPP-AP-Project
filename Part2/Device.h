#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
constexpr double PI = 3.14159265358979323846;


#include <vector>
#include <string>

// ANSI escape codes for colors
constexpr const char* RESET = "\033[0m";
constexpr const char* RED = "\033[31m";
constexpr const char* GREEN = "\033[32m";
constexpr const char* YELLOW = "\033[33m";
constexpr const char* BLUE = "\033[34m";
constexpr const char* MAGENTA = "\033[35m";
constexpr const char* CYAN = "\033[36m";

class Shape
{
public:
    Shape(double density = 1.0) : density(density) {}
    virtual ~Shape() {}

    virtual double GetVolume() const = 0;
    virtual double GetSurfaceArea() const = 0;
    double GetMass() const { return density * GetVolume(); }

    virtual void Print(std::ostream& out) const = 0;  
    virtual Shape* Clone() const = 0;

protected:
    double density;
};


inline std::ostream& operator<<(std::ostream& out, const Shape& shape)
{
    shape.Print(out);  
    return out;
}


class Cube : public Shape
{
public:
    Cube(double A = 0, double B = 0, double C = 0, double density = 1.0)
        : Shape(density), m_A(A), m_B(B), m_C(C)
    {
        EvalVolume();
        EvalSurfaceArea();
    }

    // Copy constructor
    Cube(const Cube& other) : Shape(other), m_A(other.m_A), m_B(other.m_B), m_C(other.m_C)
    {
        m_Volume = other.m_Volume;
        m_SurfaceArea = other.m_SurfaceArea;
    }

    Cube* Clone() const override { return new Cube(*this); }

    double GetVolume() const override { return m_Volume; }
    double GetSurfaceArea() const override { return m_SurfaceArea; }

    void SetAll(double A, double B, double C)
    {
        m_A = A;
        m_B = B;
        m_C = C;
        EvalVolume();
        EvalSurfaceArea();
    }
    void SetA(double x) { m_A = x; EvalVolume(); EvalSurfaceArea(); }
    void SetB(double x) { m_B = x; EvalVolume(); EvalSurfaceArea(); }
    void SetC(double x) { m_C = x; EvalVolume(); EvalSurfaceArea(); }
    void Print(std::ostream& out) const override
    {
        out << "Cube(" << m_A << ", " << m_B << ", " << m_C << ", Density: " << density << ')';
    }
    friend std::ostream& operator<<(std::ostream& out, const Cube& a)
    {
        out << "Cube(" << a.m_A << ", " << a.m_B << ", " << a.m_C << ", Density: " << a.density << ')';
        return out;
    }

private:
    void EvalVolume() { m_Volume = m_A * m_B * m_C; }
    void EvalSurfaceArea() { m_SurfaceArea = 2 * (m_A * m_B + m_B * m_C + m_C * m_A); }

    double m_A, m_B, m_C, m_Volume, m_SurfaceArea;
};


class Sphere : public Shape
{
public:
    Sphere(double radius = 0, double density = 1.0)
        : Shape(density), m_Radius(radius)
    {
        EvalVolume();
        EvalSurfaceArea();
    }

    // Copy constructor
    Sphere(const Sphere& other) : Shape(other), m_Radius(other.m_Radius)
    {
        m_Volume = other.m_Volume;
        m_SurfaceArea = other.m_SurfaceArea;
    }

    Sphere* Clone() const override { return new Sphere(*this); }

    double GetVolume() const override { return m_Volume; }
    double GetSurfaceArea() const override { return m_SurfaceArea; }

    void SetRadius(double radius)
    {
        m_Radius = radius;
        EvalVolume();
        EvalSurfaceArea();
    }
    void Print(std::ostream& out) const override
    {
        out << "Sphere(" << m_Radius << ", Density: " << density << ')';
    }
    friend std::ostream& operator<<(std::ostream& out, const Sphere& a)
    {
        out << "Sphere(" << a.m_Radius << ", Density: " << a.density << ')';
        return out;
    }

private:
    void EvalVolume() { m_Volume = (4.0 / 3.0) * PI * std::pow(m_Radius, 3); }
    void EvalSurfaceArea() { m_SurfaceArea = 4 * PI * std::pow(m_Radius, 2); }

    double m_Radius, m_Volume, m_SurfaceArea;
};


class Cylinder : public Shape
{
public:
    Cylinder(double height = 0, double radius = 0, double density = 1.0)
        : Shape(density), m_Height(height), m_Radius(radius)
    {
        EvalVolume();
        EvalSurfaceArea();
    }

    // Copy constructor
    Cylinder(const Cylinder& other) : Shape(other), m_Height(other.m_Height), m_Radius(other.m_Radius)
    {
        m_Volume = other.m_Volume;
        m_SurfaceArea = other.m_SurfaceArea;
    }

    Cylinder* Clone() const override { return new Cylinder(*this); }

    double GetVolume() const override { return m_Volume; }
    double GetSurfaceArea() const override { return m_SurfaceArea; }

    void SetHeight(double height)
    {
        m_Height = height;
        EvalVolume();
        EvalSurfaceArea();
    }

    void SetRadius(double radius)
    {
        m_Radius = radius;
        EvalVolume();
        EvalSurfaceArea();
    }
    void Print(std::ostream& out) const override
    {
        out << "Cylinder(" << m_Height << ", " << m_Radius << ", Density: " << density << ')';
    }
    friend std::ostream& operator<<(std::ostream& out, const Cylinder& a)
    {
        out << "Cylinder(" << a.m_Height << ", " << a.m_Radius << ", Density: " << a.density << ')';
        return out;
    }

private:
    void EvalVolume() { m_Volume = PI * std::pow(m_Radius, 2) * m_Height; }
    void EvalSurfaceArea() { m_SurfaceArea = 2 * PI * m_Radius * (m_Radius + m_Height); }

    double m_Height, m_Radius, m_Volume, m_SurfaceArea;
};


class Pyramid : public Shape
{
public:
    Pyramid(double height = 0, double width = 0, double density = 1.0)
        : Shape(density), m_Height(height), m_Width(width)
    {
        EvalVolume();
        EvalSurfaceArea();
    }

    // Copy constructor
    Pyramid(const Pyramid& other) : Shape(other), m_Height(other.m_Height), m_Width(other.m_Width)
    {
        m_Volume = other.m_Volume;
        m_SurfaceArea = other.m_SurfaceArea;
    }

    Pyramid* Clone() const override { return new Pyramid(*this); }

    double GetVolume() const override { return m_Volume; }
    double GetSurfaceArea() const override { return m_SurfaceArea; }

    void SetHeight(double height)
    {
        m_Height = height;
        EvalVolume();
        EvalSurfaceArea();
    }

    void SetWidth(double width)
    {
        m_Width = width;
        EvalVolume();
        EvalSurfaceArea();
    }
    void Print(std::ostream& out) const override
    {
        out << "Pyramid(" << m_Height << ", " << m_Width << ", Density: " << density << ')';
    }
    friend std::ostream& operator<<(std::ostream& out, const Pyramid& a)
    {
        out << "Pyramid(" << a.m_Height << ", " << a.m_Width << ", Density: " << a.density << ')';
        return out;
    }

private:
    void EvalVolume() { m_Volume = (m_Width * m_Width * m_Height) / 3; }
    void EvalSurfaceArea()
    {
        double slantHeight = std::sqrt((m_Width / 2) * (m_Width / 2) + m_Height * m_Height);
        m_SurfaceArea = m_Width * m_Width + 2 * m_Width * slantHeight;
    }

    double m_Height, m_Width, m_Volume, m_SurfaceArea;
};


class Device
{
public:
    Device(const std::string& name = "no name") : m_Name(name) {}


    void AddShape(const Shape& shape)
    {
        m_Shapes.push_back(shape.Clone());
    }


    void AddSubDevice(const Device& subDevice)
    {
        m_Devices.push_back(subDevice.Clone());
    }

    double GetVolume() const
    {
        double volume = 0.0;
        for (const auto& shape : m_Shapes)
            volume += shape->GetVolume();
        for (const auto& subDevice : m_Devices)
            volume += subDevice->GetVolume();
        return volume;
    }

    double GetSurfaceArea() const
    {
        double surfaceArea = 0.0;
        for (const auto& shape : m_Shapes)
            surfaceArea += shape->GetSurfaceArea();
        for (const auto& subDevice : m_Devices)
            surfaceArea += subDevice->GetSurfaceArea();
        return surfaceArea;
    }

    double GetMass() const
    {
        double mass = 0.0;
        for (const auto& shape : m_Shapes)
            mass += shape->GetMass();
        for (const auto& subDevice : m_Devices)
            mass += subDevice->GetMass();
        return mass;
    }

    friend std::ostream& operator<<(std::ostream& out, const Device& a)
    {
        out << GREEN << "Device: " << a.m_Name << RESET << "\n";
        // Print totals
        out << std::fixed << std::setprecision(2);  // Set decimal precision
        out << BLUE << "  Total Volume: " << a.GetVolume() << RESET << "\n";
        out << BLUE << "  Total Surface Area: " << a.GetSurfaceArea() << RESET << "\n";
        out << BLUE << "  Total Mass: " << a.GetMass() << RESET << "\n";
        out << MAGENTA << "-------------------" << RESET << "\n";

        if (!a.m_Shapes.empty())
        {
            out << YELLOW << "Shapes of " << a.m_Name << ":" << RESET << "\n";
            for (const auto& shape : a.m_Shapes)
            {
                out << "  - " << *shape << ":\n";
                out << "      Volume: " << shape->GetVolume() << "\n";
                out << "      Surface Area: " << shape->GetSurfaceArea() << "\n";
                out << "      Mass: " << shape->GetMass() << "\n";
            }
        }
        else
        {
            out << YELLOW << "Shapes of " << a.m_Name << ": empty!" << RESET << "\n";
        }

        // Print separator between shapes and sub-devices
        out << MAGENTA << "-------------------" << RESET << "\n";

        // Print sub-devices with separator
        if (!a.m_Devices.empty())
        {
            out << CYAN << "SubDevices of " << a.m_Name << ":" << RESET << "\n";
            for (const auto& subDevice : a.m_Devices)
            {
                out << "  " << *subDevice;
            }
        }
        else
        {
            out << CYAN << "SubDevices of " << a.m_Name << ": empty!" << RESET << "\n";
        }
        out << MAGENTA << "-----------------------------------" << RESET << "\n";
        return out;
    }

    // Destructor to clean up allocated shapes and sub-devices
    ~Device()
    {
        for (auto shape : m_Shapes)
            delete shape;
        for (auto subDevice : m_Devices)
            delete subDevice;
    }

private:
    std::string m_Name;
    std::vector<Shape*> m_Shapes;
    std::vector<Device*> m_Devices;

    
    Device* Clone() const
    {
        Device* clone = new Device(m_Name);
        for (const auto& shape : m_Shapes)
            clone->m_Shapes.push_back(shape->Clone());
        for (const auto& subDevice : m_Devices)
            clone->m_Devices.push_back(subDevice->Clone());
        return clone;
    }
};
