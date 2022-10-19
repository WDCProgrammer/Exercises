#include "SqlConnection.h"
#include <iostream>


SqlConnection::SqlConnection(const std::string& connection): DbConnection(connection){}


void SqlConnection::OpenConnection()
{
    std::cout << "SqlConnection opened with " << connectionString << "!\n";
}


void SqlConnection::CloseConnection()
{
    std::cout << "SqlConnection closed with " << connectionString << "!\n";
}