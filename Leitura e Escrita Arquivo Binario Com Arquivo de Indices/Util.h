#ifndef UTIL_H
#define UTIL_H

#define COLUMN_1 1
#define COLUMN_2 2
#define COLUMN_3 3
#define COLUMN_4 4
#define COLUMN_5 5

#define BUFFER_MIN_SIZE 114 //name,max nusp,commas,max grade


#define END_OF_LINE '\n'
#define END_OF_STRING '\0'

#define SEARCH "search"
#define INSERT "insert"
#define DELETE "delete"
#define EXIT "exit"
#define READ "read"
#define FIELDS_QUANTITY 5
#define ID 0

#define FILENAME "file.csv"


char ** copyBufferToFieldsArray(const char *buffer);
char *ditchComma(char* line, int column);
char *copyString(const char *origin);

 
 
#endif
