#ifndef STUDENT_H
#define STUDENT_H

#define boolean int
#define TRUE 1
#define FALSE 0

#include <stdio.h>

typedef struct student STUDENT;

#define ID 0

#define NAME 1

#define SURNAME 2

#define COURSE 3

#define GRADE 4

#define INDEX_FILE "indexes.csv"

    STUDENT *addStudent(STUDENT *students, int index, char **fields);
    STUDENT * reallocate(STUDENT **, int *);
    void printStudent(STUDENT student);
    void insert(STUDENT ** students, int *size, char * buffer);
    STUDENT* getStudent(STUDENT **students, int i);
    unsigned long long studentSize();
    void setNullKey(STUDENT **student);
    void print(STUDENT * student);
    int getNuspByIndex(const STUDENT *students, int i);
    int getNusp(const STUDENT *pStudent);
#endif