
#ifndef ATV3_INDEX_H
#define ATV3_INDEX_H

typedef struct index INDEX;

INDEX * allocateIndex(int byteOffset, int key);
unsigned long long indexSize();
INDEX *getIndex(INDEX *indexes, int i);
int getIndexKey(INDEX *indexes, int i);
int getIndexOffset(INDEX *indexes, int i);

#endif //ATV3_INDEX_H
