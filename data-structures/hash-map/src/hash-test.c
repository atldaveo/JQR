#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

// Methods validation
int main() 
{    
    HashMap* map = createHashMap();

    // Insert key-data pairs
    insert(map, "name", "Alice");
    insert(map, "age", "25");
    insert(map, "city", "New York");

    // Search for a key
    char* data = (char*)search(map, "age");
    if (NULL != data) 
    {
        printf("Found: %s\n", data);
    } 
    else 
    {
        printf("Key not found.\n");
    }

    // Print all key-data pairs
    printf("\nHashMap Contents:\n");
    printHashMap(map);

    // Delete a key
    deleteKey(map, "city");

    // Print all key-data pairs after deletion
    printf("\nHashMap After Deletion:\n");
    printHashMap(map);

    // Free the hash map
    freeHashMap(map);

    return 0;
}