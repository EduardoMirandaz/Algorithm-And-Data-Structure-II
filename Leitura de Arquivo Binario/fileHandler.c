#include "fileHandler.h"

FILE *openArchive(FILE *archivePointer, char* arcName){
    if( (archivePointer = fopen(arcName, "rb+")) == NULL){
        printf("erro ao abrir o arquivo!");
        return NULL;
    }
    return archivePointer;
}
