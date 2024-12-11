#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

#define TABLE_SIZE 10

// Node structure for linked list
typedef struct Node 
{
    char* key;
    char* value;
    struct Node* next;
} Node;

// Hash table array
Node* hashTable[TABLE_SIZE];

// Hash function to compute the index
unsigned int hash(const char* key) 
{
    unsigned int hash = 0;
    while (*key) 
    {
        hash = (hash * 31) + *key++;
    }
    return hash % TABLE_SIZE;
}

// Insert a key-value pair into the hash table
void insert(const char* key, const char* value) 
{
    unsigned int index = hash(key);

    // Create a new node
    Node* newNode = malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = NULL;

    // Insert into the linked list at the index
    if (hashTable[index] == NULL) 
    {
        hashTable[index] = newNode;
    } 
    else 
    {
        Node* temp = hashTable[index];
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Search for a value by its key
char* search(const char* key) 
{
    unsigned int index = hash(key);
    Node* temp = hashTable[index];

    while (temp != NULL) 
    {
        if (strcmp(temp->key, key) == 0) 
        {
            return temp->value;
        }
        temp = temp->next;
    }

    return NULL; // Key not found
}

// Free memory used by the hash table
void freeHashTable() 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        Node* temp = hashTable[i];
        while (temp != NULL) 
        {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree->key);
            free(toFree->value);
            free(toFree);
        }
    }
}

/*
int main() 
{
    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        hashTable[i] = NULL;
    }

    // Insert some key-value pairs
    insert("name", "Alice");
    insert("age", "25");
    insert("city", "New York");

    // Search for values
    printf("Name: %s\n", search("name")); // Output: Alice
    printf("Age: %s\n", search("age"));   // Output: 25

    // Free memory
    freeHashTable();

    return 0;
}
*/