#ifndef ORACLECONNECTION_H
#define ORACLECONNECTION_H

#include "DbConnection.h"


class OracleConnection: public DbConnection
{

    public:
        explicit OracleConnection(const std::string& connection);
        ~OracleConnection() = default;

        void OpenConnection() override;
        void CloseConnection() override;

    private:

};

#endif