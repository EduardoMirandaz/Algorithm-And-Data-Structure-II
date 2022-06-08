#ifndef ATV3_FILEHANDLER_H
#define ATV3_FILEHANDLER_H

#include "Student.h"

#define NOT_FOUND_KEY -1

void insertStudentToIndexFile(int byteOffset, int key);
int searchStudentIndexInIndexFile(char *fields);
void logicallyDeleteStudent(int offset);
void searchStudentFromFile(int offset);
void writeStudentToFile(STUDENT **students, int index);
#endif //ATV3_FILEHANDLER_H
