#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H
#include "DbConnection.h"

class SqlConnection: public DbConnection
{
    public:
        explicit SqlConnection(const std::string& connection);
        ~SqlConnection() = default;

        void OpenConnection() override;
        void CloseConnection() override;

    private:


};

#endif