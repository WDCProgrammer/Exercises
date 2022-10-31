#include <iostream>
#include <string>
#include <exception>
#include "Polynomial.h"

int main(int argc, char* argv[])
{

    Polynomial ph;

    Polynomial poly{1,3,2};

    ph.Show();
    std::cout << std::endl;
    poly.Show();

    std::cout << std::endl;
    Polynomial p = ph + poly;

    p.Show();
    return 0;
}