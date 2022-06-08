#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Student.h"
#include "Util.h"

int main(void) {
    int tam = 0;
    STUDENT * students = NULL;
    char buffer[BUFFER_MIN_SIZE];
    char *id, *name, *course, *grade;

    while (fgets(buffer, sizeof(buffer), stdin)) {
        if(buffer[0] == END_OF_LINE)
            break;
        
        buffer[strcspn(buffer, "\n")] = END_OF_STRING;

        id = copyString(buffer);
        name = copyString(buffer);
        course = copyString(buffer);
        grade = copyString(buffer);
 
        students = reallocate(&students, &tam);
        addStudent(
            students, 
            (tam - 1),
            ditchComma(id, COLUMN_1), 
            ditchComma(name, COLUMN_2), 
            ditchComma(course, COLUMN_3), 
            ditchComma(grade, COLUMN_4)
        );
    }
    writeStudentsToFile(students, tam);

    STUDENT * studentsFromFile = NULL;
    int sizeOfStudentsArrayFromFile = readStudentsFromFile(&studentsFromFile);
    showRange(studentsFromFile, sizeOfStudentsArrayFromFile);
    return 0;   
}

