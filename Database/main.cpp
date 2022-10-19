
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <memory>

#include "SqlConnection.h"
#include "DbConnection.h"
#include "OracleConnection.h"
#include "DbCommand.h"
#include "PlayerPoolCommand.h"


int main(int argc, char* argv[])
{

    std::shared_ptr<DbConnection> connect = std::make_shared<OracleConnection>("Player Database");
    

    std::unique_ptr<DbCommand> cmd;
    cmd = std::make_unique<PlayerPoolCommand>(connect, "Clear the Pool");
    cmd->Execute();

    
    return 0;
}