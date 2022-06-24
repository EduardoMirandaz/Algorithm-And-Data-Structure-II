#ifndef STUDENT_H
#define STUDENT_H

#define boolean int
#define TRUE 1
#define FALSE 0

typedef struct student STUDENT;

#define ID 0

#define NAME 1

#define SURNAME 2

#define COURSE 3

#define GRADE 4
#define SIZE 50

//funcoes de banco de dados
    void insert(STUDENT ** students, int *size, char * buffer);
    void updateStudentInDataFile(int offset, FILE *dataFile, STUDENT *student);
    STUDENT* getStudent(STUDENT **students, int i);


    STUDENT *addStudent(STUDENT *students, int index, char **fields);
    STUDENT * reallocate(STUDENT **, int *);
    void printStudent(STUDENT student);
    unsigned long long studentSize();
    void setNullKey(STUDENT **student);

    void print(STUDENT * student);

    //getters. pode ser removido depois.
    int getNuspByIndex(const STUDENT *students, int i);
    int getNusp(STUDENT *pStudent);
    char * getSurname(STUDENT *pStudent);
    char * getName(STUDENT *pStudent);
    char * getCourse(STUDENT *pStudent);
    float getGrade(STUDENT *pStudent);

    //criar baseado em string de dados
    STUDENT *create(char * buffer);
#endif
