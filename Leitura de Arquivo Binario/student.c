#include "student.h"
#include "util.h"

struct student {
    int numero_usp;
    char nome_completo[TAM];
    char curso[TAM];
    float nota;
};

int getHowManyStudentsInFile(FILE *archivePointer){
    if(archivePointer != NULL){
        fseek(archivePointer, 0L, SEEK_END); 
        int archiveSize = ftell(archivePointer);
        fseek(archivePointer, 0L, SEEK_SET);
        return (archiveSize / sizeof(STUDENT));
    }
    return ERRO;
}

STUDENT* readStudentsFromFile(FILE *archivePointer,int howManyStudents){
    STUDENT *studentsVector = NULL;
    if(archivePointer != NULL && howManyStudents != ERRO){
        studentsVector = calloc(howManyStudents, sizeof(STUDENT));
        if(!fread(studentsVector, sizeof(STUDENT), howManyStudents, archivePointer)){
            exit(1);
        };
    }
    return studentsVector;
}

void printStudents (STUDENT *students, int start, int end, int limit){
    if (end > limit) end = limit;
    for(int i = start; i <= end; i++){
        printf("nUSP: %d\n", students[i].numero_usp); 
        printf("Nome: %s\n", students[i].nome_completo); 
        printf("Curso: %s\n", students[i].curso); 
        printf("Nota: %.2f\n", students[i].nota);
        if(i != end)
            printf("\n");
    }
}


