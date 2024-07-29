#pragma once
#include <iostream>
#include <array>
#include <memory>
#include <vector>
#define M_PI 3.14159265358979323846

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    virtual double GetVolume() const
    {
        return -1;
    }

    

};



class Cube : public Shape
{
public:
    Cube(double A = 0, double B = 0, double C = 0)
        : m_A(A), m_B(B), m_C(C)
    {
        EvalVolume();
    }
    ~Cube() {}

    double GetVolume() const override
    {
        return m_Volume;
    }
    std::array<double, 3> GetAll() const
    {
        return { m_A, m_B, m_C };
    }
    void SetAll(double A, double B, double C)
    {
        m_A = A;
        m_B = B;
        m_C = C;
        EvalVolume();
    }
    void SetA(double x)
    {
        m_A = x;
        EvalVolume();
    }
    void SetB(double x)
    {
        m_B = x;
        EvalVolume();
    }
    void SetC(double x)
    {
        m_C = x;
        EvalVolume();
    }
    const double& GetA() const
    {
        return m_A;
    }
    const double& GetB() const
    {
        return m_B;
    }
    const double& GetC() const
    {
        return m_C;
    }
    friend std::ostream& operator<<(std::ostream& out, const Cube& a)
    {
        out << "Cube(" << a.m_A <<','<< a.m_B<<','<< a.m_C << ')';
        return out;
    }

private:
    void EvalVolume()
    {
        m_Volume = m_A * m_B * m_C;
    }

    double m_A, m_B, m_C, m_Volume;
};

class Sphere : public Shape
{
public:
    Sphere(double radius = 0)
        : m_Radius(radius)
    {
        EvalVolume();
    }
    ~Sphere() {}

    double GetVolume() const override
    {
        return m_Volume;
    }
    double GetRadius() const
    {
        return m_Radius;
    }
    void SetRadius(double radius)
    {
        m_Radius = radius;
        EvalVolume();
    }
    friend std::ostream& operator<<(std::ostream& out, const Sphere& a)
    {
         out << "Sphere(" << a.m_Radius << ')';
         return out;
    }


private:
    void EvalVolume()
    {
        m_Volume = (4 * M_PI / 3) * m_Radius * m_Radius * m_Radius;
    }

    double m_Radius, m_Volume;
};

class Cylinder : public Shape
{
public:
    Cylinder(double height = 0, double radius = 0)
        : m_Height(height), m_Radius(radius)
    {
        EvalVolume();
    }
    ~Cylinder() {}

    double GetVolume() const override
    {
        return m_Volume;
    }
    double GetHeight() const
    {
        return m_Height;
    }
    double GetRadius() const
    {
        return m_Radius;
    }
    void SetHeight(double height)
    {
        m_Height = height;
        EvalVolume();
    }
    void SetRadius(double radius)
    {
        m_Radius = radius;
        EvalVolume();
    }
    friend std::ostream& operator<<(std::ostream& out, const Cylinder& a)
    {
        out << "Cylinder(" << a.m_Height << ',' << a.m_Radius << ')';
        return out;
    }


private:
    void EvalVolume()
    {
        m_Volume = M_PI * m_Radius * m_Radius * m_Height;
    }

    double m_Height, m_Radius, m_Volume;
};

class Pyramid : public Shape
{
public:
    Pyramid(double height = 0, double width = 0)
        : m_Height(height), m_Width(width)
    {
        EvalVolume();
    }
    ~Pyramid() {}

    double GetVolume() const override
    {
        return m_Volume;
    }
    double GetHeight() const
    {
        return m_Height;
    }
    double GetWidth() const
    {
        return m_Width;
    }
    void SetHeight(double height)
    {
        m_Height = height;
        EvalVolume();
    }
    void SetWidth(double width)
    {
        m_Width = width;
        EvalVolume();
    }
    friend std::ostream& operator<<(std::ostream& out, const Pyramid& a)
    {
        out << "Pyramid(" << a.m_Height << ',' << a.m_Width << ')';
        return out;
    }


private:
    void EvalVolume()
    {
        m_Volume = (m_Width * m_Width * m_Height) / 3;
    }

    double m_Height, m_Width, m_Volume;
};
