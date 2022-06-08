#include "Util.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* ditchComma(char* line, int num)
{
    char* tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ","))
    {
        if (!--num)
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