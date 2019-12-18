
#include <string>
#include <iostream>

#include <mysql.h>
#include <vector>
using namespace std;


class Conn_sql {

    private:
        // Library MySQL variables
        MYSQL *conn;
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL_FIELD *field;

        // Retrieve data 
        vector< vector <string> > retrieve_data;
        vector<string> field_name;

        // Connection data string 
        char *server;
        char *user;
        char *password;
        char *database;

    public:
        Conn_sql( char *, char *, char *, char * );
        void connect(void);
        //std::vector< std::vector <std::string> >  query(std::string);
        void query(std::string);

        std::vector<std::string> getfield_name(void);
        std::vector< std::vector <std::string> > getretrieve_data(void);
        int order(std::string);
        void disconnect(void);
};


