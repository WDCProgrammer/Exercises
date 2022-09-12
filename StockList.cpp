#include "StockList.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>


void StockList::Print() const
{
    for(auto stck: m_stocks)
        std::cout << stck << "\n";
}

std::ostream& operator<<(std::ostream& os, const StockList& stockList)
{
        std::cout   << std::setw(12)  << std::setfill('*') << "  "
                    << std::setw(23)  << std::left
                    << "First Investor's Heaven" 
                    << std::setw(12)  << std::setfill('*')
                    << "  "
                    << '\n';
                   
        std::cout   << std::right 
                    << std::setw(12)  << std::setfill('*') << "  "
                    << std::setw(19)  << std::setfill(' ')
                    << "Financial Report"
                    << std::left
                    << std::setw(16)  << std::setfill('*')
                    << "      "
                    << std::endl;
                    

    for(size_t i = 0; i < stockList.m_sortIndicesGainLoss.size(); i++)
    {
        os << stockList.m_stocks[stockList.m_sortIndicesGainLoss[i]];
    }

    return os;
}
void StockList::SortIndices(const std::vector<StockType>& stocks, std::vector<int>& indices)
{
    std::priority_queue<StockIndice> que;

    //sort stocks by indices by pushing stockindices
    //into a priority que.
    for(int i{0}; i < stocks.size(); i++)
    {
        StockIndice indice{stocks[i].GainAndLossPercentage(), i};
        que.push(indice);
    }


    while(!que.empty())
    {
        indices.push_back(que.top().m_indice);
        que.pop();
    }
}

void StockList::OpenStocks(std::string fileName)
{
    std::ifstream file(fileName);
    if(!file.is_open())
    {
        throw FileError("Failed to open the file " + fileName + ".\n");
    }

    StockType stock;
    while(file >> stock)
    {
        m_stocks.push_back(stock);
        m_size++;
    }

    file.close();

    SortIndices(m_stocks, m_sortIndicesGainLoss);
}