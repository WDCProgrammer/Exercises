#ifndef PLAYERPOOLCOMMAND_H
#define PLAYERPOOLCOMMAND_H

#include "DbCommand.h"

class PlayerPoolCommand: public DbCommand
{
    public:
        PlayerPoolCommand(std::shared_ptr<DbConnection> connect, const std::string& cmd);
       
       void                         Execute() override;

    private:

};


#endif