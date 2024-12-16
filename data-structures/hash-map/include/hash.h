#ifndef HASH_H
#define HASH_H

#define HASH_MAP_SIZE 100

/**< Define key-data pair */
typedef struct HashNode 
{
    char* key;
    void* data;
    struct HashNode* next;                              
} HashNode;                                             // Global variable declaration 

/**< Define hash map structure */
typedef struct HashMap
{
    HashNode* buckets[HASH_MAP_SIZE];                   // Array of pointers to hash nodes
} HashMap;                                              // Global variable declaration

/** @brief Generate index for a key using a hash function 
 * 
 * @param key Allows an index to be generated in reference to hash map 
 * @return unsigned int Cannot be negative
 */
unsigned int hashFunction(const char* key);

/** @brief Create a new hash map
 * 
 * @return HashMap* Pointer to a new hash map
 */
HashMap* createHashMap();

/** @brief Create a new hash node
 * 
 * @param key 
 * @param data Data to be stored in the node
 * @return HashNode* Pointer to a new node
 */
HashNode* createHashNode(const char* key, void* data);

/** @brief Insert a key-data pair into hash map 
 * 
 * @param map Hash map to be used
 * @param key Key to be inserted
 * @param data Data to be associated with the key 
 */
void insert(HashMap* map, const char* key, void* data);

/** @brief Search for a key in the hash map
 * 
 * @param map Reference hash map
 * @param key Key in question
 * @return void* 
 */
void* search(HashMap* map, const char* key);

/** @brief Delete Key-data pair from map
 * 
 * @param map Reference map
 * @param key Desired key to be deleted 
 */
void deleteKey(HashMap* map, const char* key);

/** @brief Delete / sterilize hash map
 * 
 * @param map Map to be sterilized
 */
void freeHashMap(HashMap* map);

/** @brief Print all key-data pairs in the hash map
 * 
 * @param map Map to be printed
 */
void printHashMap(HashMap* map);

/** @brief Duplicates a string into another variable
 * 
 * @param src Pointer to location of string to be duplicated
 * @return char* Pointer to location of duplicated string
 */
char *strdup(const char *src);

#endif