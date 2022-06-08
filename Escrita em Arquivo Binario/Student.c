#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct student
{
    int nusp;
    char name[50];
    char course[50];
    float grade;
};
 
void showRange(STUDENT * students, int size){
    int start = size - 10;
    int end = size - 1;
    for(int i = start; i < end; i++){
      printf("nUSP: %d\n", students[i].nusp); 
      printf("Nome: %s\n", students[i].name); 
      printf("Curso: %s\n", students[i].course); 
      printf("Nota: %.2f\n\n", students[i].grade); 
    } 
    printf("nUSP: %d\n", students[end].nusp); 
    printf("Nome: %s\n", students[end].name); 
    printf("Curso: %s\n", students[end].course); 
    printf("Nota: %.2f\n", students[end].grade); 
}

STUDENT * addStudent(STUDENT *students, int index, char *id, char *name, char *course, char *grade) {
    students[index].nusp = atoi(id);
    strcpy(students[index].name, name);
    strcpy(students[index].course, course);
    students[index].grade = atof(grade);

    return students;
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
        }
        else
            (*students) = temp;
    }
    return (*students);
}

void writeStudentsToFile(STUDENT *students, int tam){
    FILE *filePointer = fopen("file.txt", "w");

    if(filePointer != NULL){
        for(int i = 0; i < tam; i ++){
            fwrite(&students[i], sizeof(STUDENT), 1, filePointer);
        }
    }
    fclose(filePointer);
}

int readStudentsFromFile(STUDENT ** students) {
    FILE *filePointer = fopen("file.txt", "rb");
    int bytesSize, quantity = 0;

    if(filePointer != NULL){
        fseek(filePointer, 0L, SEEK_END);
        bytesSize = ftell(filePointer);
        fseek(filePointer, 0L, SEEK_SET);
        quantity = bytesSize / sizeof(STUDENT);

        (*students) = calloc(quantity, sizeof (STUDENT));

        for (int i = 0; i < quantity; ++i) {
            fread(&(*students)[i], sizeof(STUDENT), 1, filePointer);
        }
    }
    fclose(filePointer);
    return quantity;
}
