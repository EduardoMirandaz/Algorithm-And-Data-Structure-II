#include <stdio.h>
#include "student.h"
#include "fileHandler.h"
#include "operations.h"
#include "util.h"



int main(){
    char archiveName[TAM];
    if(!scanf("%s", archiveName)) exit(1);
    int operation = 0;
    if(!scanf("%d", &operation)) exit(1);
    FILE *archivePointer = NULL;
    // Opening file
    archivePointer = openArchive(archivePointer,archiveName);
    STUDENT *studentsVector;
    //                    Function that returns how many stunts are in File
    int howManyStudents = getHowManyStudentsInFile(archivePointer);
    studentsVector = readStudentsFromFile(archivePointer, howManyStudents);
    //                    Function that makes the selected operation
    makeSelectedOperation(studentsVector, operation, howManyStudents);
    fclose(archivePointer);
}
