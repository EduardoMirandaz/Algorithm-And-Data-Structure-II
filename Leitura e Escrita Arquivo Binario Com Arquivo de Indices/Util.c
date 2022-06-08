#include "Util.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* ditchComma(char* line, int column)
{
    char* tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ","))
    {
        if (!--column)
            return tok;
    }
    return NULL;
}

char *copyString(const char *origin) {
    char *destiny = malloc(strlen (origin) + 1);
    if (destiny != NULL){
      strcpy(destiny, origin);     
      return destiny;     
    }
    return NULL;
}

char ** copyBufferToFieldsArray(const char *buffer) {
    char** fields = calloc(FIELDS_QUANTITY, sizeof (char**));
    for(int fieldPosition=0; fieldPosition < FIELDS_QUANTITY; fieldPosition++)
    {
        fields[fieldPosition] = (char *) calloc(1, BUFFER_MIN_SIZE);
        fields[fieldPosition] = copyString(buffer);
        if (fieldPosition == ID)
            strcpy(fields[fieldPosition],
                   strrchr(ditchComma(fields[fieldPosition], fieldPosition + 1), ' ') + 1);
        else
            strcpy(fields[fieldPosition],
                   ditchComma(fields[fieldPosition], fieldPosition + 1));
    }
    return fields;
}