#ifndef HASH_H
#define HASH_H

unsigned int hash(const char* key);

void insert(const char* key, const char* value);

char* search(const char* key);

void freeHashTable();



#endif