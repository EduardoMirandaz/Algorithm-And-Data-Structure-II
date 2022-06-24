#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Student.h"
#include "Database.h"
#include "Util.h"
#include "Btree.h"

int main(void) {
    FILE *indexFile = NULL, *dataFile = NULL;
    STUDENT * student = NULL;
    char buffer[BUFFER_MIN_SIZE] = "";
  
    createDatabase(&indexFile, &dataFile);

    while (strcmp(fgets(buffer, sizeof(buffer), stdin), EXIT) != 0) {
        if(buffer[0] == END_OF_LINE)
            break;
        
        buffer[strcspn(buffer, "\n")] = END_OF_STRING; 
        if(strstr(buffer, INSERT)){
            char *bufferCopy = copyString(buffer);
            char *studentData = copyString(buffer);
            long offset = searchStudentIndexInIndexFile(bufferCopy, indexFile);
            free(bufferCopy);
  
            if(offset != NOT_FOUND_KEY) {
              printf(DATA_ALREADY_EXISTS);
              continue;
            }
            student = create(studentData);
            persistStudentToFile(student, dataFile, indexFile);
            free(student);
            free(studentData);

        } else if(strstr(buffer, SEARCH)){
            long offset = searchStudentIndexInIndexFile(buffer, indexFile);

            if(offset != NOT_FOUND_KEY)
                getStudentFromDataFile(offset, dataFile);
            else
                printf(DATA_NOT_FOUND);

        } else if(strstr(buffer, UPDATE)){
            char *studentData = copyString(buffer);
            STUDENT * student = create(studentData);
            long offset = searchStudentIndexInIndexFile(buffer, indexFile);
            free(studentData);

            if(offset != NOT_FOUND_KEY)
                updateStudentInDataFile(offset, dataFile, student);
            else
                printf(DATA_NOT_FOUND);
          free(student);
        } 
        else {
            closeDatabase(indexFile, dataFile);
            return 0;
        }
    }
    return 0;
}

