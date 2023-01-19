#include <iostream>
#include "DBFactory.h"

class EmployeeDAO{
        DBFactory* factory;
        public:
        explicit EmployeeDAO(DBFactory* dbFactory) : factory(dbFactory){}
        void GetEmployees(){
            DBConnect* dbConnect = factory->CreateDBConnect();
            dbConnect->Connect();
            DBCommand* dbCommand = factory->CreateDBCommand();
            dbCommand->Command();
        }
};
int main() {
    DBFactory* factory = new sqlDBFactory();
    EmployeeDAO* getDB = new EmployeeDAO(factory);
    getDB->GetEmployees();
    return 0;
}
