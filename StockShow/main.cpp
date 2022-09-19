#include <iostream>

#include "StockList.h"

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

   StockRun();

    return 0;
}