#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include <string>
#include <chrono>
class DbConnection
{

    public:
        explicit DbConnection(const std::string& connection);
        virtual ~DbConnection() = default;

        virtual void        OpenConnection() = 0;
        virtual void        CloseConnection() = 0;

    protected:
        std::string                                           connectionString{};
        std::chrono::duration<double, std::ratio<1,60>>       timeout{};

};




#endif