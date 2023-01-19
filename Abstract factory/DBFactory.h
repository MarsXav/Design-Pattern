//
// Created by Dell on 2023/1/19.
//

#ifndef ABSTRACT_FACTORY_DBFACTORY_H
#define ABSTRACT_FACTORY_DBFACTORY_H
#include "DBConnect.h"


class DBFactory{ //VIRTUAL FACTORY
public:
    virtual DBConnect* CreateDBConnect() = 0;
    virtual DBCommand* CreateDBCommand() = 0;
};

class sqlDBFactory : public DBFactory{
public:
    sqlDBFactory() : DBFactory(){}
    virtual DBConnect* CreateDBConnect() {
        return new sqlConnection();
    }
    virtual DBCommand* CreateDBCommand(){
        return new sqlCommand();
    }
};

class OracleFactory : public DBFactory{
    OracleFactory() : DBFactory(){}
    virtual DBConnect* CreateDBConnect(){
        return new OracleConnection();
    }
    virtual DBCommand* CreateDBCommand(){
        return new OracleCommand();
    }
};


#endif //ABSTRACT_FACTORY_DBFACTORY_H
