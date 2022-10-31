#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{

    public:
        Polynomial()        = default;
        Polynomial(int a, int b, int c);


        void            Show()const;
        int             Calculate(int x);
        Polynomial      operator+(int x);
        Polynomial      operator+(const Polynomial& poly);
        bool            operator==(const Polynomial& poly);
        const int       operator[](int index) const;
        int&            operator[](int index);


    private:

        int coefficient[3]{1,1,1};


};


#endif