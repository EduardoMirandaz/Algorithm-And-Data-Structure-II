#ifndef ATV3_FILEHANDLER_H
#define ATV3_FILEHANDLER_H

#include "Btree.h"
#include "Student.h"

#define NOT_FOUND_KEY -1
#define ADMIN_PRIVILEGE "wb+"


void createDatabase(FILE **, FILE **);
void closeDatabase(FILE *, FILE *);

//escreve student no arquivo de dados e a chave e offset no arquivo de índice
long persistStudentToFile(STUDENT *, FILE *, FILE *);
void insertStudentToIndexFile(BT_PAGE *, int, int, FILE *);
long searchStudentIndexInIndexFile(char *, FILE *);
void logicallyDeleteStudent(int);
void getStudentFromDataFile(int, FILE *);

#endif //ATV3_FILEHANDLER_H
