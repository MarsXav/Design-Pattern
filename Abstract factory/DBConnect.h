//
// Created by Dell on 2023/1/19.
//

#ifndef ABSTRACT_FACTORY_DBCONNECT_H
#define ABSTRACT_FACTORY_DBCONNECT_H
#include <bits/stdc++.h>
using namespace std;

class DBConnect{ // database related base classes
public:
    virtual void Connect() = 0;
};

class DBCommand{
public:
    virtual void Command() = 0;
};

//sql connection
class sqlConnection : public DBConnect{
    virtual void Connect(){}
};
class sqlCommand : public DBCommand{
    virtual void Command(){}
};

//Oracle connection
class OracleConnection : public DBConnect{
    virtual void Connect(){}
};
class OracleCommand : public DBCommand{
    virtual void Command(){}
};



#endif //ABSTRACT_FACTORY_DBCONNECT_H
