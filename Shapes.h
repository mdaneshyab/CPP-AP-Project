#pragma once

#include <iostream>
#include <array>
#define M_PI 3.14159265358979323846
class  Shape
{
public:
     Shape() {}
     ~Shape() { }
     virtual double GetVolume()
     { 
         EvalVoulme();
         return m_Volume;
     }
     
private:
    double EvalVoulme() {return m_Volume = -1; }
    double m_Volume;
};


class Cube :public Shape{

public:
    
    Cube(double A=0, double B=0, double C=0) :
        m_A(A), m_B(B), m_C(C) 
    {
        
        EvalVolume();
    }
    ~Cube() {  }

    double GetVolume()override 
    { return m_Volume; }
    std::array<double, 3> GetAll() 
    {
        std::array<double, 3> tmp ;
        tmp[0] = m_A;
        tmp[1] = m_B;
        tmp[2] = m_C;
        return tmp;
    }
    void SetAll(double _A, double _B, double _C) {
        m_A = _A;
        m_B = _B;
        m_C = _C;
        EvalVolume();
    }
    void SetA(double x) {
        m_A = x;
        EvalVolume();
    }
    void SetB(double x) {
        m_B = x;
        EvalVolume();
    }
    void SetC(double x) {
        m_C = x;
        EvalVolume();
    }
    const double& GetA() {
        return m_A;
    }
    const double& GetB() {
        return m_B;
    }
    const double& GetC() {
        return m_C;
    }
private:
    void EvalVolume() {
        m_Volume = m_A * m_B * m_C;

    }
    double m_A, m_B, m_C, m_Volume;
};

std::ostream& operator<< (std::ostream& out, Cube& a)
{
 
    out << "Cube("<< a.GetA() ;
    out << ',' << a.GetB();
    out << ',' << a.GetC();
    out << ")";

    return out;
}

class Sphere :public Shape
{
public:
    
    Sphere(double Radious=0)
    {
        m_Radious = Radious;
        EvalVolume();
    }
    double GetRadious() { return m_Radious; }
    double GetVolume() override { return m_Volume; }
    void SetRaious(double Radious)
    {
        m_Radious = Radious;
        EvalVolume();
    }

    

private:
    void EvalVolume() {
        m_Volume = (4*M_PI/3) * m_Radious* m_Radious * m_Radious;

    }
    double m_Radious;
    double m_Volume;
};

std::ostream& operator<< (std::ostream& out, Sphere& a)
{

    out << "Sphere(" << a.GetRadious() << ')';
    return out;
}

class Cylinder : public Shape
{
public:
    Cylinder(double Height=0 , double Radious=0)
        :m_Height(Height),m_Radious(Radious)
    {
        EvalVolume();
    }
    double GetHeight() { return m_Height; }
    double GetRadious() { return m_Radious; }
    void SetRadious(double Radious) 
    { 
        m_Radious = Radious;
        EvalVolume();
    }
    void SetHeight(double Height)
    { 
        m_Height = Height; 
        EvalVolume();
    }
    double GetVolume() override { return m_Volume; }

private:
    void EvalVolume()
    {
        m_Volume = M_PI * m_Radious * m_Radious * m_Height;
    }
    double m_Height, m_Radious;
    double m_Volume;

};
std::ostream& operator<< (std::ostream& out, Cylinder& a)
{

    out << "Cylinder(" << a.GetHeight() << ',' << a.GetRadious() << ')';
    return out;
}
class Pyramid: public Shape
{
public:
    Pyramid(double Height=0, double Width=0)
    {
        m_Height = Height;
        m_Width = Width;
        EvalVolume();
    }
    double GetHeight() { return m_Height; }
    double GetWidth() { return m_Width; }
    void SetWidth(double Width)
    {
        m_Width = Width;
        EvalVolume();
    }
    void SetHeight(double Height)
    {
        m_Height = Height;
        EvalVolume();
    }
    double GetVolume() override { return m_Volume; }

private:
    void EvalVolume()
    {
        m_Volume = (m_Width * m_Width * m_Height) / 3;
    }
    double m_Width, m_Height;
    double m_Volume;
};

std::ostream& operator<< (std::ostream& out, Pyramid& a)
{

    out << "Cylinder(" << a.GetHeight()<<',' << a.GetWidth() << ')';
    return out;
}

