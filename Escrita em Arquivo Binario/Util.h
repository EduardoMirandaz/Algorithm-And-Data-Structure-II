#ifndef UTIL_H
#define UTIL_H

#define COLUMN_1 1
#define COLUMN_2 2
#define COLUMN_3 3
#define COLUMN_4 4


#define BUFFER_MIN_SIZE 114 //name,max nusp,commas,max grade

#define END_OF_LINE '\n'
#define END_OF_STRING '\0'

char *ditchComma(char* line, int num);
char *copyString(const char *origin);

 
 
#endif
