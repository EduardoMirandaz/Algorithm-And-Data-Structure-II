#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

typedef struct student STUDENT;

    void showRange(STUDENT *, int);
    STUDENT * addStudent(STUDENT *, int, char *, char *, char *, char *);
    STUDENT * reallocate(STUDENT **, int *);
    void writeStudentsToFile(STUDENT *, int);
    int readStudentsFromFile(STUDENT ** );
#endif