#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "Student.h"

struct student
{
    int nusp;
    char name[SIZE];
    char surname[SIZE];
    char course[SIZE];
    float grade;
};

void printStudent(STUDENT student){
    printf("-------------------------------\n");
    printf("nUSP: %d\n", student.nusp);
    printf("Nome: %s\n", student.name);
    printf("Sobrenome: %s\n", student.surname);
    printf("Curso: %s\n", student.course);
    printf("Nota: %.2f\n", student.grade);
    printf("-------------------------------\n");
}

STUDENT *createStudent(STUDENT *students, char **fields) {
    STUDENT *student = calloc(1, sizeof (STUDENT));
    if(students != NULL){
        student->nusp = atoi(fields[ID]);
        strcpy(student->name, fields[NAME]);
        strcpy(student->surname, fields[SURNAME]);
        strcpy(student->course, fields[COURSE]);
        student->grade = atof(fields[GRADE]);
    }
    return student;
}

STUDENT *addStudent(STUDENT *students, int index, char **fields) {
    if(students != NULL){
        students[index].nusp = atoi(fields[ID]);
        strcpy(students[index].name, fields[NAME]);
        strcpy(students[index].surname, fields[SURNAME]);
        strcpy(students[index].course, fields[COURSE]);
        students[index].grade = atof(fields[GRADE]);
    }
    return students;
}

int getNuspByIndex(const STUDENT *students, int i) {
    return students[i].nusp;
}
int getNusp(STUDENT *pStudent) {
    return pStudent->nusp;
}

char * getName(STUDENT *pStudent) {
    return pStudent->name;
}

char * getSurname(STUDENT *pStudent) {
    return pStudent->name;
}

char * getCourse(STUDENT *pStudent) {
    return pStudent->course;
}

float getGrade(STUDENT *pStudent) {
    return pStudent->grade;
}

STUDENT * reallocate(STUDENT **students, int *tam){
    (*tam)++;

    if((*students) == NULL) {
        (*students) = calloc((*tam), sizeof(STUDENT));
    } else {
        STUDENT *temp =  realloc((*students), ((*tam)* sizeof(STUDENT)));
        if (temp == NULL){
            printf("Error allocating.\n");
            return 0;
        } else
            (*students) = temp;
    }
    return (*students);
}

void setNullKey(STUDENT **student){
    (*student)->nusp = -1;
}
void searchStudent(STUDENT * students, int size, char *nuspKey){
    char * id = strchr(nuspKey, ' ') + 1;

    for(int i = 0; i < size; i++){
        if(atoi(id) == students[i].nusp){
            printStudent(students[i]);
        }
    }
}

//aspas tratadas com loop.
void print(STUDENT * student){
    printf("-------------------------------\n");
    printf("nUSP: %d\n", student->nusp);
    printf("Nome: ");
        for (int i = 1; i < (int)strlen(student->name) - 1; i++){
        printf("%c", student->name[i]);
    }
    printf("\n");
    printf("Sobrenome: ");
    for (int i = 1; i < (int)strlen(student->surname) - 1; i++){
        printf("%c", student->surname[i]);
    }
    printf("\n");
    printf("Curso: ");
        for (int i = 1; i < (int)strlen(student->course) - 1; i++){
        printf("%c", student->course[i]);
    }
    printf("\n");
    printf("Nota: %.2f\n", student->grade);
    printf("-------------------------------\n");
}

STUDENT *create(char * buffer) {
    STUDENT * student = calloc(1,sizeof (STUDENT));
//    char **fields = copyBufferToFieldsArray(buffer);
    char *id, *name, *course, *surname, *grade;
    id = copyString(buffer);
    name = copyString(buffer);
    surname = copyString(buffer);
    course = copyString(buffer);
    grade = copyString(buffer);

    if(student != NULL){
        student->nusp = atoi(strrchr(ditchComma(id, COLUMN_1), ' ') + 1);
        strcpy(student->name, ditchComma(name, COLUMN_2));
        strcpy(student->surname, ditchComma(surname, COLUMN_3));
        strcpy(student->course, ditchComma(course, COLUMN_4));
        student->grade = atof(ditchComma(grade, COLUMN_5));
    }
    free(id);
    free(name);
    free(surname);
    free(course);
    free(grade);
    return student;
}
STUDENT* getStudent(STUDENT **students, int i) {
    return &(*students)[i];
}

unsigned long long studentSize(){
    return sizeof(STUDENT);
}
