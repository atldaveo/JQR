/**
 * @file hasht.c
 * @author David Chung (david.t.chung2.mil@army.mil)
 * @brief Defines the functions for a basic hash table
 * @version 3 (10APR25)
 * @date 14JAN25
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hasht.h"

#define HASH_MAP_SIZE   100
#define HASH            69
#define EMPTY           0

char*
strdup(const char* str) 
{
    size_t len = 0;
    char* copy = NULL;
    
    len = strlen(str) + 1;  // +1 for the null terminator
    copy = (char*)malloc(len);  // Allocate memory
    
    if (NULL != copy) 
    {
        memcpy(copy, str, len);  // Copy the string into the allocated memory
    }
    
    return copy;  // Return the duplicated string
}

unsigned int
hash_func(const char* p_key)
{
    unsigned int hash = 0;

    while (0 != *p_key) 
    {
        hash = (HASH * 31) + *p_key;  // Polynomial hash function
        p_key++;
    }

    return hash % HASH_MAP_SIZE;
}

HashMap*
create_hash_map(void)
{
    int index = 0;
    HashMap* map = NULL; 

    map = (HashMap*)malloc(sizeof(HashMap));
    
    for (index = 0; index < HASH_MAP_SIZE; index++)
    {
        map->buckets[index] = NULL;
    }

    return map;
}

HashNode*
create_hash_node(const char* p_key, void* p_value)
{
    HashNode* node = NULL;
    
    node = (HashNode*)malloc(sizeof(HashNode));
    node->p_key = strdup(p_key);  // Duplicate the p_key string
    node->p_value = p_value;
    node->next = NULL;

    return node;
}

void
insert(HashMap* map, const char* p_key, void* p_value)
{
    int index = 0;
    HashNode* new_node = NULL;

    index = hash_func(p_key);
    new_node = create_hash_node(p_key, p_value);

    if (NULL == map->buckets[index])
    {
        map->buckets[index] = new_node;  // Insert directly if no collision
    }
    else
    {
        // Handle collision using chaining
        HashNode* current = map->buckets[index];

        while (NULL != current)
        {
            // If the key already exists, update its value
            if (EMPTY == strncmp(current->p_key, p_key, strlen(p_key)))
            {
                current->p_value = p_value;
                free(new_node->p_key);
                free(new_node);
                return;
            }

            // If the key-value doesn't yet exist
            if (NULL == current->next)
            {
                break; // Stop at the last node
            }

            current = current->next;
        }
        
        // Add the new node at the end of the chain
        current->next = new_node;
    }
}

void*
search(HashMap* map, const char* p_key)
{
    unsigned int index = 0;
    HashNode* current = NULL; 
    
    index = hash_func(p_key);
    current = map->buckets[index];
    
    while (NULL != current)
    {
        if (0 == strncmp(current->p_key, p_key, strlen(p_key)))
        {
            return current->p_value;  // Return value if key is found
        }

        current = current->next;
    }
    
    return NULL;  // Key not found
}

void
delete_key(HashMap* map, const char* p_key) 
{
    unsigned int index = 0;
    HashNode* current = NULL;
    HashNode* prev = NULL;

    index = hash_func(p_key);
    current = map->buckets[index];

    while (NULL != current) 
    {
        if (0 == strcmp(current->p_key, p_key)) 
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

            free(current->p_key);
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
    printf("Key '%s' not found.\n", p_key);
}

void
print_hash_map(HashMap* map)
{
    int iter = 0;
    
    for (iter = 0; iter < HASH_MAP_SIZE; iter++) 
    {
        HashNode* current = map->buckets[iter];

        while (NULL != current) 
        {
            printf("Key: %s, Value: %s\n", current->p_key, (char*)current->p_value);
            current = current->next;
        }
    }

}

void
free_hash_map(HashMap* map) 
{
    int iter = 0;
    HashNode* current = NULL;
    HashNode* temp = NULL;

    for (iter = 0; iter < HASH_MAP_SIZE; iter++) 
    {
        current = map->buckets[iter];

        while (NULL != current) 
        {
            temp = current;
            current = current->next;
            free(temp->p_key);
            free(temp);
        }
    }

    free(map);
}

/*******************  END OF FILE *******************************/