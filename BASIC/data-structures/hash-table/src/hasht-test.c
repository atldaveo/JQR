/**
 * @file hasht-test.c
 * @author David Chung (david.chung1719@outlook.com)
 * @brief 
 * @version 1.0 (10APR25)
 * @date 13Feb25
 * 
 * @brief Basic test for functionality for all 
 * the functions for a hash table from hasht.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hasht.h"

#define FAIL 1
#define PASS 0

// Hash Map Testing 
int main(void)
{
    char* result = NULL;
    const char* key4 = NULL;
    
    // Test data (key-value pairs)
    const char* p_key1 = "name";
    const char* p_value1 = "David";
    const char* p_key2 = "age";
    const char* p_value2 = "29";
    const char* p_key3 = "email";
    const char* p_value3 = "david@example.com";

    // Create a hash map
    HashMap* map = create_hash_map();

    if (NULL == map)
    {
        printf("Failed to create hash map.\n");
        return FAIL;
    }

    // Insert key-value pairs
    printf("Inserting key-value pairs into the hash map...\n");
    insert(map, p_key1, (void*)p_value1);
    insert(map, p_key2, (void*)p_value2);
    insert(map, p_key3, (void*)p_value3);

    // Print the hash map
    printf("\nHash map contents:\n");
    print_hash_map(map);

    // Search for a key
    printf("\nSearching for key '%s'...\n", p_key1);
    result = (char*)search(map, p_key1);

    if (NULL != result)
    {
        printf("Found value: %s\n", result);
    }
    else
    {
        printf("Key '%s' not found.\n", p_key1);
    } 

    // Attempt to search for a non-existent key
    key4 = "address";
    printf("\nSearching for non-existent key '%s'...\n", key4);
    result = (char*)search(map, key4);
    
    if (NULL != result)
    {
        printf("Found value: %s\n", result);
    }
    else
    {
        printf("Key '%s' not found.\n", key4);
    }

    // Delete a key
    printf("\nDeleting key '%s'...\n", p_key2);
    delete_key(map, p_key2);

    // Verify deletion
    printf("\nHash map contents after deletion:\n");
    print_hash_map(map);

    // Attempt to delete a non-existent key
    printf("\nAttempting to delete non-existent key '%s'...\n", key4);
    delete_key(map, key4);

    // Free the hash map
    printf("\nFreeing the hash map...\n");
    free_hash_map(map);

    printf("Test completed successfully.\n");
    return PASS;
}


/*******************  END OF FILE *******************************/