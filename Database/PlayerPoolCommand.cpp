#include "PlayerPoolCommand.h"
#include <iostream>

PlayerPoolCommand::PlayerPoolCommand(std::shared_ptr<DbConnection> connect, const std::string& cmd): DbCommand(connect,cmd)
{}


void PlayerPoolCommand::Execute()
{
    connection->OpenConnection();
    std::cout << command << "\n";
    connection->CloseConnection();
}