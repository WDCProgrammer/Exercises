#ifndef DBCOMMAND_H
#define DBCOMMAND_H

#include <memory>
#include "DbConnection.h"

class DbCommand
{
    public:

        DbCommand(std::shared_ptr<DbConnection>  connect, const std::string& command);
        virtual void Execute() = 0;

    protected:
        std::shared_ptr<DbConnection>               connection{nullptr};
        std::string                 command{};

};

#endif