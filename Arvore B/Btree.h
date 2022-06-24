#ifndef BTREE
#define BTREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Util.h"

#define MAXKEYS 204
#define CHILDSIZE 205
#define AUXFIELDSSIZEONPAGE (2 + 1) // number of keys and ”is leaf” bool
#define PAGELENGTH ((MAXKEYS * 4) + (MAXKEYS * 8) + ((MAXKEYS + 1) * 8) + 3)
#define PAGESIZE 4096
#define FREESPACEONPAGE (PAGESIZE - PAGELENGTH)
#define RECORDLENGTH ((MAXKEYS * 4) + (MAXKEYS * 8))
#define HEADER_SIZE (PAGESIZE - 8)

#define FREESPACE "any"
#define boolean int

#define NO_PROMOTION NULL

#define LEFT 0
#define RIGHT 1

#define KEY_ALREADY_EXISTS -1
#define DUMMY_VALUE -1
#define log printf

typedef struct index
{
    int key;
    long recordRRN;
} INDEX;

//só serve pra formalizar a inserção de espaço livre na página.
typedef struct header
{
    long rrn;
    char *freeSpace;
} BT_HEADER; 

typedef struct promotedKey
{
    INDEX *recordKey;
    long childs[2];
} BT_PROMOTED_KEY;

typedef struct page
{
    INDEX **records;
    long *childs;
    short numberOfKeys;
    bool isLeaf;
} BT_PAGE;

// Funções que se relacionam com o database (externas)
long bTreeSelect(BT_PAGE *, int, FILE *);
void bTreeInsert(INDEX *, BT_PAGE *, FILE *);
BT_PAGE *getOrCreateRoot(FILE *);


Errors writePageIntoFile(long rrn, BT_PAGE *, FILE *);
INDEX *createIndex(int, long);
long getTreeHeader(FILE *);
void writeTreeHeader(FILE *, long);
void freePage(BT_PAGE **page);

BT_PROMOTED_KEY * split(BT_PAGE *, BT_PROMOTED_KEY *, FILE *);
BT_PROMOTED_KEY * _insertBtree(BT_PROMOTED_KEY *, BT_PAGE *, FILE *);
BT_PROMOTED_KEY * insertInPage(BT_PROMOTED_KEY *, BT_PAGE *);


boolean checkIfGrowth(BT_PAGE * page);
#endif