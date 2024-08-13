#pragma once

#include <iostream>
#include <vector>
#include <cmath> // For M_PI and std::sqrt

// Abstract base class for shapes
class Shape
{
public:
    Shape(double density = 1.0) : density(density) {}
    virtual ~Shape() {}

    virtual double GetVolume() const = 0;
    virtual double GetSurfaceArea() const = 0;
    double GetMass() const { return density * GetVolume(); }

protected:
    double density; // Density of the shape
};

// Cube class
class Cube : public Shape
{
public:
    Cube(double A = 0, double B = 0, double C = 0, double density = 1.0)
        : Shape(density), m_A(A), m_B(B), m_C(C)
    {
        EvalVolume();
        EvalSurfaceArea();
    }

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

    friend std::ostream& operator<<(std::ostream& out, const Cube& a)
    {
        out << "Cube(" << a.m_A << ',' << a.m_B << ',' << a.m_C << ')';
        return out;
    }

private:
    void EvalVolume() { m_Volume = m_A * m_B * m_C; }
    void EvalSurfaceArea() { m_SurfaceArea = 2 * (m_A * m_B + m_B * m_C + m_C * m_A); }

    double m_A, m_B, m_C, m_Volume, m_SurfaceArea;
};

// Sphere class
class Sphere : public Shape
{
public:
    Sphere(double radius = 0, double density = 1.0)
        : Shape(density), m_Radius(radius)
    {
        EvalVolume();
        EvalSurfaceArea();
    }

    double GetVolume() const override { return m_Volume; }
    double GetSurfaceArea() const override { return m_SurfaceArea; }

    void SetRadius(double radius)
    {
        m_Radius = radius;
        EvalVolume();
        EvalSurfaceArea();
    }

    friend std::ostream& operator<<(std::ostream& out, const Sphere& a)
    {
        out << "Sphere(" << a.m_Radius << ')';
        return out;
    }

private:
    void EvalVolume() { m_Volume = (4.0 / 3.0) * M_PI * std::pow(m_Radius, 3); }
    void EvalSurfaceArea() { m_SurfaceArea = 4 * M_PI * std::pow(m_Radius, 2); }

    double m_Radius, m_Volume, m_SurfaceArea;
};

// Cylinder class
class Cylinder : public Shape
{
public:
    Cylinder(double height = 0, double radius = 0, double density = 1.0)
        : Shape(density), m_Height(height), m_Radius(radius)
    {
        EvalVolume();
        EvalSurfaceArea();
    }

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

    friend std::ostream& operator<<(std::ostream& out, const Cylinder& a)
    {
        out << "Cylinder(" << a.m_Height << ',' << a.m_Radius << ')';
        return out;
    }

private:
    void EvalVolume() { m_Volume = M_PI * std::pow(m_Radius, 2) * m_Height; }
    void EvalSurfaceArea() { m_SurfaceArea = 2 * M_PI * m_Radius * (m_Radius + m_Height); }

    double m_Height, m_Radius, m_Volume, m_SurfaceArea;
};

// Pyramid class
class Pyramid : public Shape
{
public:
    Pyramid(double height = 0, double width = 0, double density = 1.0)
        : Shape(density), m_Height(height), m_Width(width)
    {
        EvalVolume();
        EvalSurfaceArea();
    }

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

    friend std::ostream& operator<<(std::ostream& out, const Pyramid& a)
    {
        out << "Pyramid(" << a.m_Height << ',' << a.m_Width << ')';
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

// Device class
class Device
{
public:
    Device(const std::string& name = "no name") : m_Name(name) {}

    void AddShape(Shape* shape) { m_Shapes.push_back(shape); }
    void AddSubDevice(Device* subDevice) { m_SubDevices.push_back(subDevice); }

    double GetVolume() const
    {
        double volume = 0.0;
        for (const auto& shape : m_Shapes)
            volume += shape->GetVolume();
        for (const auto& subDevice : m_SubDevices)
            volume += subDevice->GetVolume();
        return volume;
    }

    double GetSurfaceArea() const
    {
        double surfaceArea = 0.0;
        for (const auto& shape : m_Shapes)
            surfaceArea += shape->GetSurfaceArea();
        for (const auto& subDevice : m_SubDevices)
            surfaceArea += subDevice->GetSurfaceArea();
        return surfaceArea;
    }

    double GetMass() const
    {
        double mass = 0.0;
        for (const auto& shape : m_Shapes)
            mass += shape->GetMass();
        for (const auto& subDevice : m_SubDevices)
            mass += subDevice->GetMass();
        return mass;
    }

private:
    std::string m_Name;
    std::vector<Shape*> m_Shapes;
    std::vector<Device*> m_SubDevices;
};
