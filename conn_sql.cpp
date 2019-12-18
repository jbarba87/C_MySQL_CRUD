#include "conn_sql.h"

Conn_sql::Conn_sql(char *_server, char *_user, char *_password, char *_database ){

    server = _server;
    user = _user;
    password = _password;
    database = _database;
    res = NULL;
}

void Conn_sql::connect(void){

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        std::cout << mysql_error(conn) << std::endl;
        //return NULL;
        exit(0);
    }

    //return conn;

}

void Conn_sql::query(std::string command){

    /* send SQL query */
    if (mysql_query(conn,  command.c_str() )) {
        std::cout << mysql_error(conn) << std::endl;
        exit(1);
    }

    res = mysql_use_result(conn);

    // Retrieve data fields
    while((field = mysql_fetch_field(res))){
        field_name.push_back(field->name);
    }

    int num_fields, i;
    unsigned long *lengths;
    int num_rows = 0;

    // Retrieve data table
    while ((row = mysql_fetch_row(res)) != NULL)
        if (row){

                num_fields = mysql_num_fields(res);
                lengths = mysql_fetch_lengths(res);

                // Creating and adding new vector row to store this new data
                vector<string> data_row;
                retrieve_data.push_back( data_row );

                for(i = 0; i < num_fields; i++){
                    retrieve_data[num_rows].push_back(row[i]);
                }
                num_rows++;
            }

    cout << "Retrieve " << num_rows << " rows." << endl;
}

void Conn_sql::disconnect(void){

    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);

}

int Conn_sql::order(std::string commando){
    /* send SQL order */
    if (mysql_query(conn,  commando.c_str() )) {
        std::cout << mysql_error(conn) << std::endl;
        exit(1);
    }

    return 1;
}


std::vector<std::string> Conn_sql::getfield_name(void){
    return field_name;
}
std::vector< std::vector <std::string> > Conn_sql::getretrieve_data(void){
    return retrieve_data;
}
