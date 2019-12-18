CC = g++
LIBS = `mysql_config --cflags --libs`

TARGET = test_mysql_crud

make: conn_sql.cpp test_mysql_crud.cpp
	
	$(CC) $^ -o $(TARGET) $(LIBS) 
	
clean:
	rm -f $(TARGET) *.o
