#include <iostream>

#include "StockList.h"
#include "SmartPointer.h"

void StockRun()
{
    StockList list;
    try
    {
        list.OpenStocks("stocks.txt");
        std::cout << list << std::endl;
    }
    catch (FileError &exception)
    {
        std::cout << exception.what();
    }
}



int main(int argc, char *argv[])
{

   
    return 0;
}