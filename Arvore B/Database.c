#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "Btree.h"
#include "Student.h"
#include "Database.h"

void createDatabase(FILE **indexFile, FILE **dataFile) {
  (*indexFile) = fopen(INDEX_FILE, ADMIN_PRIVILEGE);
  (*dataFile) = fopen(DATA_FILE, ADMIN_PRIVILEGE);
}

void closeDatabase(FILE *indexFile, FILE *dataFile) {
  if(!indexFile || !dataFile) {
    THROW_FILE_ERROR
  }
  
  fclose(indexFile);
  fclose(dataFile);
}

//escrevendo no arquivo de dados e retornando offset
long persistStudentToFile(STUDENT *student, FILE *dataFile, FILE *indexFile) {
    BT_PAGE *page = getOrCreateRoot(indexFile);

    fseek(dataFile, 0, SEEK_END);
    if (dataFile == NULL) {
        THROW_FILE_ERROR_AND_RETURN
    }
    if (page == NULL) {
      THROW_BTREE_ERROR_AND_RETURN
    }
    long byteOffsetOfStudent = ftell(dataFile);
    fwrite(student, studentSize(), 1, dataFile);

    INDEX *newRecord = createIndex(getNusp(student), byteOffsetOfStudent);
    bTreeInsert(newRecord, page, indexFile);

    for (int i = 0; i < MAXKEYS; i++){
      free(page->records[i]);
    }

    free(page->records);
    free(page->childs);
    free(page);
    free(newRecord);
    return byteOffsetOfStudent;
}

//sobrescrita no arquivo de dados
void updateStudentInDataFile(int offset, FILE *dataFile, STUDENT *student) {
    if(dataFile == NULL) {
      THROW_FILE_ERROR
    }
    fseek(dataFile, offset, SEEK_SET);
    fwrite(student, studentSize(), 1, dataFile);
    fflush(dataFile);
}

//imprime student baseado no offset encontrado no arquivo de  indice
void getStudentFromDataFile(int offset, FILE *dataFile) {
    STUDENT *studentFromFile = NULL;
    if(dataFile == NULL) {
      THROW_FILE_ERROR
    }
    studentFromFile = (STUDENT *) calloc(1, studentSize());

    fseek(dataFile, offset, SEEK_SET);
   if(!fread(studentFromFile, studentSize(), 1, dataFile))
     return;
    print(studentFromFile);
    free(studentFromFile);
}

//procura offset do aluno no arquivo de indice dada uma chave.
long searchStudentIndexInIndexFile(char *buffer, FILE * indexFile) {
    BT_PAGE *page = getOrCreateRoot(indexFile);
    int keyToSearch = atoi(strrchr(ditchComma(buffer, 1), ' ') + 1);
    if (indexFile == NULL) {
        return NOT_FOUND_KEY;
    }
    long offset = bTreeSelect(page, keyToSearch, indexFile);

    for (int i = 0; i < MAXKEYS; i++){
      free(page->records[i]);
    }
  
    free(page->childs);
    free(page->records);
    free(page);
    return offset;
}
