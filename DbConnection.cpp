#include "DbConnection.h"
#include <exception>



DbConnection::DbConnection(const std::string& connection): connectionString(connection){

    if(connection == "")
        throw std::invalid_argument("Connection string can't be empty");


}