#include <iostream>
#include <exception>
#include "Polynomial.h"


Polynomial::Polynomial(int a, int b, int c)
{
    coefficient[0] = a;
    coefficient[1] = b;
    coefficient[2] = c;
}


void Polynomial::Show()const
{

    std::cout << coefficient[0] 
              << "x^2 + " 
              << coefficient[1] 
              << "x + "
              << coefficient[2];
}


int Polynomial::Calculate(int x)
{
    int result = x * x * coefficient[0];
        result += coefficient[1] * x;
        result += coefficient[2];

    return result;
}
        
        
Polynomial Polynomial::operator+(int x)
{

   return {coefficient[0] + x, coefficient[1] + x, coefficient[2] + x};
}
        
Polynomial Polynomial::operator+(const Polynomial& poly)
{

    return {coefficient[0] + poly.coefficient[0],
            coefficient[1] + poly.coefficient[1],
            coefficient[2] + poly.coefficient[2]};
}

bool Polynomial::operator==(const Polynomial& poly)
{
    if(coefficient[0] != poly.coefficient[0] ||
       coefficient[1] != poly.coefficient[1] ||
       coefficient[2] != poly.coefficient[2])
       return false;
    return true;
}
    
const int Polynomial::operator[](int index) const
{
    if(index < 0 || index > 2)
    throw std::out_of_range("Index " + std::to_string(index));

    return coefficient[index];
}
        
int& Polynomial::operator[](int index)
{
    if(index < 0 || index > 2)
    throw std::out_of_range("Index " + std::to_string(index));

    return coefficient[index];
}