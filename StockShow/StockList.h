#ifndef STOCKLIST_H
#define STOCKLIST_H
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include "StockType.h"

class StockList
{
    public:
        void                            OpenStocks(std::string fileName);
        void                            Print()const;
        
        friend std::ostream&            operator<<(std::ostream& os, const StockList& stockList);

    private:

        void                            SortIndices(const std::vector<StockType>& stocks, std::vector<int>& indices);
        //member variables
        std::vector<StockType>          m_stocks;
        std::vector<int>                m_sortIndicesGainLoss;
        size_t                          m_capacity{};
        size_t                          m_size{};

};

struct StockIndice{
    double          m_GainAndLoss{};
    int             m_indice{};

    friend bool operator<(const StockIndice& lhs, const StockIndice& rhs)
    {
        return lhs.m_GainAndLoss < rhs.m_GainAndLoss;
    }
};


class FileError: std::exception
{

    public:
        FileError(std::string error): m_error(error){}

        const char* what() noexcept
        {
            return m_error.c_str();
        }
    private:
        std::string m_error{};
};

#endif