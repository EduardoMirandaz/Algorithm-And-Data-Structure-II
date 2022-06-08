#ifndef STUDENT_H
#define STUDENT_H

#include<stdio.h>

typedef struct student STUDENT;
int getHowManyStudentsInFile(FILE *archivePointer);
STUDENT* readStudentsFromFile(FILE *archivePointer,int howManyStudents);
void printStudents (STUDENT *students, int start, int end, int limit);
#endif //STUDENT_H