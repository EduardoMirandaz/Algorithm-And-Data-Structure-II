#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Util.h"

struct student
{
    int nusp;
    char name[50];
    char surname[50];
    char course[50];
    float grade;
};

void printStudent(STUDENT student){
    printf("-------------------------------\n");
    printf("USP number: %d\n", student.nusp); 
    printf("Name: %s\n", student.name);
    printf("Surname: %s\n", student.surname);
    printf("Course: %s\n", student.course); 
    printf("Test grade: %.2f\n", student.grade); 
    printf("-------------------------------\n");
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
int getNusp(const STUDENT *pStudent) {
    return pStudent->nusp;
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

void print(STUDENT * student){
    printf("-------------------------------\n");
    printf("USP number: %d\n", student->nusp);
    printf("Name: %s\n", student->name);
    printf("Surname: %s\n", student->surname);
    printf("Course: %s\n", student->course);
    printf("Test grade: %.2f\n", student->grade);
    printf("-------------------------------\n");
}

void insert(STUDENT ** students, int *size, char * buffer){
    char **fields = copyBufferToFieldsArray(buffer);
    (*students) = reallocate(students, size);
    addStudent((*students), (*size) - 1, fields);
}

STUDENT* getStudent(STUDENT **students, int i) {
    return &(*students)[i];
}

unsigned long long studentSize(){
    return sizeof(STUDENT);
}
