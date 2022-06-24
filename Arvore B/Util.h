#ifndef UTIL_H
#define UTIL_H

#define COLUMN_1 1
#define COLUMN_2 2
#define COLUMN_3 3
#define COLUMN_4 4
#define COLUMN_5 5

#define BUFFER_MIN_SIZE 300 //name,max nusp,commas,max grade

#define END_OF_LINE '\n'
#define END_OF_STRING '\0'

#define SEARCH "search"
#define UPDATE "update"
#define INSERT "insert"
#define EXIT "exit"
#define FIELDS_QUANTITY 5
#define ID 0
#define Errors bool

#define DATA_FILE "file.bin"
#define INDEX_FILE "indexes.bin"

#define debug printf


#define TRUE 1
#define FALSE 0

#define THROW_FILE_ERROR printf("------------file error!\n");return;
#define THROW_BTREE_ERROR printf("------------btree error!\n");return;
#define THROW_BTREE_ERROR_AND_RETURN printf("------------btree error!\n");return 0;
#define THROW_BTREE_ERROR_AND_RETURN_KEY printf("------------btree error!\n");return -1;
#define THROW_FILE_ERROR_AND_RETURN printf("------------file error!\n");return 0;

#define DATA_NOT_FOUND "Registro nao encontrado!\n"
#define DATA_ALREADY_EXISTS "O Registro ja existe!\n"

char ** copyBufferToFieldsArray(const char *);
char *ditchComma(char* , int );
char *copyString(const char *);

void doNothingThen(unsigned long );
 
#endif