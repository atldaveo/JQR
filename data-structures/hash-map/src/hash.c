#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

char *strdup(const char *src) 
{
    char *dst = malloc(strlen (src) + 1);  // Space for length plus nul
    if (NULL == dst) 
    {
        return NULL;                       // No memory
    }
    strcpy(dst, src);                      // Copy the characters
    return dst;                            // Return the new string
}

unsigned int hashFunction(const char* key)
{
    unsigned int hash = 0;
    while (0 != *key)                          
    {
        hash = (hash * 31) + *key;                      // Hash function. Change as needed.
        key++;
    }
    return hash % HASH_MAP_SIZE;                
}

HashMap* createHashMap()
{
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));   // Dynamic memory allocation
    for (int i = 0; i < HASH_MAP_SIZE; i++) 
    {
        map->buckets[i] = NULL;                         // All buckets in hash map are initialized to NULL
    }
    return map;
}

HashNode* createHashNode(const char* key, void* data) 
{
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));   
    node->key = strdup(key);                            // Duplicate the key string
    node->data = data;                                  // Assign data to the node 
    node->next = NULL;                                  
    return node;
}

void insert(HashMap* map, const char* key, void* data)
{
    unsigned int index = hashFunction(key);
    HashNode* newNode = createHashNode(key, data);

    if (NULL == map->buckets[index])
    {
        map->buckets[index] = newNode;                  // Insert directly if no collision
    } 
    else 
    {
        // Handle collision using chaining
        HashNode* current = map->buckets[index];
        while (NULL != (current->next)) 
        {
            // If the key already exists, update its data
            if (0 == strncmp(current->key, key, strlen(key))) 
            {
                current->data = data;
                free(newNode->key);
                free(newNode);
                return;
            }
            current = current->next;
        }
        // Add new node to the end of the chain
        current->next = newNode;
    }
}

void* search(HashMap* map, const char* key) 
{
    unsigned int index = hashFunction(key);
    HashNode* current = map->buckets[index];

    //TODO: Explicit comparison for while-loop
    while (NULL != current) 
    {
        if (0 == strncmp(current->key, key, strlen(key))) 
        {
            return current->data;  // Return the value if key is found
        }
        current = current->next;
    }

    // If the key isn't in the map...
    fprintf(stderr, "Key not found");
    return NULL;  
}

void deleteKey(HashMap* map, const char* key) 
{
    unsigned int index = hashFunction(key);
    HashNode* current = map->buckets[index];
    HashNode* prev = NULL;

    while (NULL != current) 
    {
        if (0 == strncmp(current->key, key, strlen(key))) 
        {
            // Remove the node
            if (NULL == prev) 
            {
                map->buckets[index] = current->next;
            } 
            else 
            {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    fprintf(stderr,"Key '%s' not found.\n", key);
}

void freeHashMap(HashMap* map) 
{
    for (int i = 0; i < HASH_MAP_SIZE; i++) 
    {
        HashNode* current = map->buckets[i];
        while (NULL != current) 
        {
            HashNode* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map);
}

void printHashMap(HashMap* map) 
{
    for (int i = 0; i < HASH_MAP_SIZE; i++) 
    {
        HashNode* current = map->buckets[i];
        while (NULL != current) 
        {
            printf("Key: %s, value: %s\n", current->key, (char*)current->data);
            current = current->next;
        }
    }
}
