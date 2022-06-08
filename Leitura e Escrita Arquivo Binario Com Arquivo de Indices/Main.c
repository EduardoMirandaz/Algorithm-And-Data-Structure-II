#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "FileHandler.h"
#include "Util.h"

int main(void) {
    int tam = 0;
    STUDENT * students = NULL;
    char buffer[BUFFER_MIN_SIZE];

    while (strcmp(fgets(buffer, sizeof(buffer), stdin), EXIT) != 0) {
        if(buffer[0] == END_OF_LINE)
            break;
        
        buffer[strcspn(buffer, "\n")] = END_OF_STRING;
        if(strstr(buffer, INSERT)){
            char *bufferCopy = copyString(buffer);
            int offset = searchStudentIndexInIndexFile(buffer);
            if(offset == NOT_FOUND_KEY) {
                insert(&students, &tam, bufferCopy);
                writeStudentToFile(&students, tam - 1);
            } else
                printf("O Registro ja existe!\n");

        } else if(strstr(buffer, SEARCH)){

            int offset = searchStudentIndexInIndexFile(buffer);
            if(offset != NOT_FOUND_KEY)
                searchStudentFromFile(offset);
            else
                printf("Registro nao encontrado!\n");
        } else if(strstr(buffer, DELETE)) {

            int offset = searchStudentIndexInIndexFile(buffer);
            if (offset != NOT_FOUND_KEY)
                logicallyDeleteStudent(offset);
        } else
            return 0;
    }
    return 0;
}

