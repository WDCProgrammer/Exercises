#ifndef STOCKTYPE_H
#define STOCKTYPE_H
#include <string>
#include <fstream>

class StockType
{
    public:
        StockType()= default;
        StockType(const StockType& stock) = default;
        StockType(StockType&& stock) = default;
        StockType& operator=(const StockType& stock) = default;
        StockType& operator=(StockType&& stock) = default;
        ~StockType() = default;

        bool                            operator<(const StockType& rhs);
        bool                            operator>(const StockType& rhs);
        bool                            operator==(const StockType& rhs);


        friend std::ostream&          operator<<(std::ostream& os, const StockType& stock);
        friend std::istream&          operator>>(std::istream& is, StockType& stock);

        std::string                   ShowPrices();
        double                        GainAndLossPercentage() const;

    private:
    
        std::string                   m_symbolName{};
        double                        m_stockPrice{};
        unsigned int                  m_numberOfShares{};
        double                        m_openingPrice{};
        double                        m_closingPrice{};
        double                        m_highPrice{};
        double                        m_lowPrice{};
        double                        m_prevPrice{};
        double                        m_percentGainAndLoss{};
};

#endif