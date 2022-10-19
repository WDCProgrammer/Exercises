#include "OracleConnection.h"
#include <iostream>


OracleConnection::OracleConnection(const std::string& connection): DbConnection(connection){}

void OracleConnection::OpenConnection()
{
    std::cout << "Oracle connection opened with " << connectionString << "!\n";
}

void OracleConnection::CloseConnection()
{
    std::cout << "Oracle connection closed with " << connectionString << "!\n";
}