#include "StockType.h"
#include <iostream>
#include <sstream>
#include <iomanip>



double StockType::GainAndLossPercentage() const
{
    double percent{};

    percent = (m_highPrice - m_lowPrice) / m_closingPrice;

    return percent;
}

std::string StockType::ShowPrices()
{
    std::ostringstream ss{""};

    ss << m_symbolName         << " "
       << m_openingPrice       << " "
       << m_closingPrice       << " "
       << m_highPrice          << " "
       << m_lowPrice           << " "
       << m_prevPrice          << "\n";
    
    return ss.str();
}

bool StockType::operator<(const StockType& rhs)
{
    return m_symbolName < rhs.m_symbolName;
}

bool StockType::operator>(const StockType& rhs)
{
    return m_symbolName > rhs.m_symbolName;
}

bool StockType::operator==(const StockType& rhs)
{
    return m_symbolName == rhs.m_symbolName;
}

std::istream& operator>>(std::istream& is, StockType& stock)
{
    is >> stock.m_symbolName
       >> stock.m_openingPrice
       >> stock.m_closingPrice
       >> stock.m_highPrice
       >> stock.m_lowPrice
       >> stock.m_prevPrice
       >> stock.m_numberOfShares;

    return is;
}
std::ostream& operator<<(std::ostream& os, const StockType& stock)
{
    const int       COLUMNSIZE{7};
    const int       PRECISIONSIZE{2};

    os 
       << std::setprecision(PRECISIONSIZE)
       << std::fixed
       << std::setw(COLUMNSIZE)
       << std::left
       << stock.m_symbolName            << " "
       << std::right
       << std::setw(COLUMNSIZE)
       << stock.m_openingPrice          << " "
       << std::setw(COLUMNSIZE)
       << stock.m_closingPrice          << " "
       << std::setw(COLUMNSIZE)
       << stock.m_highPrice             << " "
       << std::setw(COLUMNSIZE)
       << stock.m_lowPrice              << " "
       << std::setw(COLUMNSIZE)
       << stock.m_prevPrice                    
       << std::setw(COLUMNSIZE)
       << stock.GainAndLossPercentage() << " "   
       << std::setw(COLUMNSIZE+ 1)    
       << stock.m_numberOfShares        << "\n";
    
    return os;
}