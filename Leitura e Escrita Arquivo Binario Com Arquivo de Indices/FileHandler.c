#include "FileHandler.h"
#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Util.h"
#include "Index.h"

void rewriteIndexesToIndexFile(INDEX *indexes, int quantityOfIndexes, int offsetToSkip);

//escrevendo chave e offset no arquivo de indice
void insertStudentToIndexFile(int byteOffset, int key) {
    FILE *indexFile = fopen(INDEX_FILE, "a");

    if (indexFile == NULL) {
        fopen(INDEX_FILE, "w");
    }
    fseek(indexFile, 0L, SEEK_END);

    INDEX *index = allocateIndex(byteOffset, key);
    fwrite(index, indexSize(), 1, indexFile);
    fclose(indexFile);
}

//escreve student no arquivo de dados e a chave e offset no arquivo de índice
void writeStudentToFile(STUDENT **students, int index) {
    FILE *filePointer = fopen(FILENAME, "a");
    if (filePointer == NULL) {
        filePointer = fopen(FILENAME, "w");
    }

    fseek(filePointer, 0L, SEEK_END);
    int byteOffsetOfStudent = ftell(filePointer);
    if (filePointer != NULL) {
        int key = getNuspByIndex((*students), index);

        insertStudentToIndexFile(byteOffsetOfStudent, key);
        fwrite(getStudent(students, index), studentSize(), 1, filePointer);
    }
    fclose(filePointer);
}

//pegando todos os indexes do arquivo de indice. usamos essa função quando formos reescrver o arquivo de indice
INDEX *getAllIndexesFromFile() {
    FILE *indexFile = fopen(INDEX_FILE, "r+");
    INDEX *indexes;

    if (indexFile == NULL)
        fopen(INDEX_FILE, "w");

    fseek(indexFile, 0L, SEEK_END);
    int indexesFileSize = ftell(indexFile);
    int quantityOfIndexes = indexesFileSize / indexSize();
    fseek(indexFile, 0L, SEEK_SET);

    indexes = calloc(quantityOfIndexes, indexSize());
    for (int i = 0; i < quantityOfIndexes; ++i) {
        fread(getIndex(indexes, i), indexSize(), 1, indexFile);
    }
    fclose(indexFile);
    return indexes;
}

//imprime student baseado no offset encontrado no arquivo de  indice
void searchStudentFromFile(int offset) {
    FILE *dataFile = fopen(FILENAME, "rb+");
    STUDENT *studentFromFile = NULL;
    if (dataFile != NULL) {
        studentFromFile = calloc(1, studentSize());
        fseek(dataFile, offset, SEEK_SET);
        fread(studentFromFile, studentSize(), 1, dataFile);
    }
    if(getNusp(studentFromFile) != NOT_FOUND_KEY)
        print(studentFromFile);
    else
        printf("Registro nao encontrado!\n");

    fclose(dataFile);
}

//remove chave/offset do student do arquivo de índice e reescreve student no arquivo de dados com chave nula
void logicallyDeleteStudent(int offset) {
    FILE *dataFile = fopen(FILENAME, "rb+");
    FILE *indexFile = fopen(INDEX_FILE, "r+");
    STUDENT *studentFromFile;
    if (dataFile != NULL) {
        studentFromFile = calloc(1, studentSize());
        fseek(dataFile, offset, SEEK_SET);
        fread(studentFromFile, studentSize(), 1, dataFile);
        setNullKey(&studentFromFile);
        fseek(dataFile, offset, SEEK_SET);
        fwrite(studentFromFile, studentSize(), 1, dataFile);
    }

    if (indexFile != NULL) {
        INDEX *allIndexes = getAllIndexesFromFile();

        fseek(indexFile, 0L, SEEK_END);
        int indexesFileSize = ftell(indexFile);
        int quantityOfIndexes = indexesFileSize / indexSize();
        fclose(indexFile);
        remove(INDEX_FILE);
        rewriteIndexesToIndexFile(allIndexes, quantityOfIndexes, offset);
    }
    fclose(dataFile);
}

//após reescrever student no arquivo de dados com chave nula, reescreve o arquivo de índice sem a chave/offset do deletado
void rewriteIndexesToIndexFile(INDEX *indexes, int quantityOfIndexes, int offsetToSkip) {
    FILE *indexFile = fopen(INDEX_FILE, "w");
    for (int i = 0; i < quantityOfIndexes; ++i) {
        if (getIndexOffset(indexes, i) != offsetToSkip) {
            fwrite(getIndex(indexes, i), indexSize(), 1, indexFile);
        }
    }
    fclose(indexFile);
}

//procura offset do aluno no arquivo de indice dada uma chave. busca comum O(n)
int searchStudentIndexInIndexFile(char *buffer) {
    printf("meu buffer é: %s\n", buffer);
    int keyToSearch = atoi(strrchr(ditchComma(buffer, 1), ' ') + 1);
    printf("keyToSearch -> %d\n", keyToSearch);
    FILE *indexFile = fopen(INDEX_FILE, "r+");
    INDEX *indexes;

    if (indexFile == NULL) {
        return NOT_FOUND_KEY;
    }

    fseek(indexFile, 0L, SEEK_END);
    int indexesFileSize = ftell(indexFile);
    int quantityOfIndexes = indexesFileSize / indexSize();
    fseek(indexFile, 0L, SEEK_SET);

    indexes = calloc(quantityOfIndexes, indexSize());
    for (int i = 0; i < quantityOfIndexes; ++i) {
        fread(getIndex(indexes, i), indexSize(), 1, indexFile);
        if (getIndexKey(indexes, i) == keyToSearch) {
            fclose(indexFile);
            return getIndexOffset(indexes, i);
        }
    }
    fclose(indexFile);
    return NOT_FOUND_KEY;
}