/**
 * @file hasht.h
 * @author David Chung (david.t.chung2.mil@army.mil)
 * @brief Prototypes and describes the functions in associated helper file hasht.c 
 * @version 3 (10APR25)
 * @date 15JAN25
 *  
*/

#ifndef HASHT_H
#define HASHT_H

#include <stdio.h>
#include <stdlib.h>

#define     HASH_MAP_SIZE       100

/** @brief Define a key-value pair node */
typedef struct HashNode
{
    char* p_key;
    void* p_value;          // Data
    struct HashNode* next;  // For handling collisions

} HashNode;

/** @brief Define the hash map structure */ 
typedef struct HashMap
{
  HashNode* buckets[HASH_MAP_SIZE];  // Array of pointers to HashNodes
} HashMap; 

/** @brief Made my own strdup function because I was having issues 
 * with the string.h library  
 * 
 * @param str String to be duplicated
 * @return char* Duplicated string
 */
char*
strdup(const char* str); 

/** @brief Create a Hash Map object
 * 
 * @return HashMap* 
 */
HashMap*
create_hash_map(void);

/** @brief Hash function to generate an index for a given key
 * 
 * @param p_key 
 * @return unsigned int 
 */
unsigned int
hash_func(const char* p_key);

/** @brief Create a new hash node
 * 
 * @param p_key 
 * @param p_value 
 * @return HashNode* 
 */
HashNode*
create_hash_node(const char* p_key, void* p_value);

/** @brief Insert a key-value pair into the hash map
 * 
 * @param p_map 
 * @param p_key 
 * @param p_value 
 */
void
insert(HashMap* map, const char* key, void* value);

/** @brief Search for a key in the hash map
 * 
 * @param p_map 
 * @param p_key 
 * @return void* 
 */
void*
search(HashMap* p_map, const char* p_key);

/** @brief Delete a key-value pair from the hash map
 * 
 * @param p_map 
 * @param p_key 
 */
void
delete_key(HashMap* p_map, const char* p_key);

/** @brief Print all key-value pairs in the hash map
 * 
 * @param p_map 
 */
void
print_hash_map(HashMap* map);

/** @brief Free the hash map. deallocates memory burdem
 * 
 * @param p_map 
 */
void
free_hash_map(HashMap* p_map);

#endif

/*******************  END OF FILE *******************************/