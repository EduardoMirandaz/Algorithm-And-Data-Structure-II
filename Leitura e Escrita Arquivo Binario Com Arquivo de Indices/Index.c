#include "Index.h"
#include <stdlib.h>
#include <stdio.h>

struct index {
    int key; //nusp
    int offset;
};

INDEX * allocateIndex(int byteOffset, int key){
        INDEX * index = calloc(1, sizeof(INDEX));
        index->key = key;
        index->offset = byteOffset;
    return index;
}

unsigned long long indexSize(){
    return sizeof(INDEX);
}

INDEX *getIndex(INDEX *indexes, int i) {
    return &indexes[i];
}
int getIndexKey(INDEX *indexes, int i) {
    return indexes[i].key;
}
int getIndexOffset(INDEX *indexes, int i) {
    return indexes[i].offset;
}
