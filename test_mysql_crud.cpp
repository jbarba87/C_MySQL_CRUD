#include <mysql.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "conn_sql.h"

using namespace std;

int main(int argc, char **argv){

    if (argc != 6){
      cout << endl << "Usage ./test_mysql_crud <server> <user> <password> <database> <table_name>" << endl << endl;
      exit(0);
    }

    Conn_sql conexion = Conn_sql( argv[1], argv[2], argv[3], argv[4]);
    conexion.connect();
    
    // Constructing sql select instruction for the specified table
    ostringstream instruction;
    instruction << "select * from " << argv[5] << ";";
    conexion.query( instruction.str());

    //vector < vector <string>> data = conexion.query( "select * from atencion;");
    vector < vector <string>> data = conexion.getretrieve_data();
    vector <string> fields = conexion.getfield_name();

    int row, col;

    // Showing columns names
    for (col = 0; col < fields.size(); col++){
        cout << fields[col] <<  " ";
    }
    cout << endl;

    // Showing data
    for (row = 0;row < data.size(); row++){
        for (col = 0; col < data[row].size(); col++){
                cout << data[row][col] <<  " ";
        }
        cout << endl;
    }

    // use conexion.order(str query) to insert a row

    conexion.disconnect();

    return 0;
}

