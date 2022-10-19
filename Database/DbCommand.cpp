#include "DbCommand.h"
#include <exception>


DbCommand::DbCommand(std::shared_ptr<DbConnection>  connection, const std::string& cmd): connection(connection),
                                                                        command(cmd)
{
    if(cmd == "" || connection == nullptr)
    {
        throw std::invalid_argument("Invalid connection or command given");
    }
}