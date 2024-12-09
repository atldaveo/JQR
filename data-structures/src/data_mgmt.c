#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <stdbool.h>
//#include <errno.h>
#include "debug.h"
#include "data_mgmt.h"


#define MAX_SIZE 100

// Declare a new struct
typedef struct 
{
    int data[MAX_SIZE];
    int size;
} Array;

// Initialize data struct and create a new array
Array* createArray() 
{
    Array* arr = (Array*)malloc(sizeof(Array));         // Allocate memory for the array
    arr->size = 0;
    return arr;
}

// Add element to the end of the array
void addElement(Array* arr, int value) 
{
    if (arr->size < MAX_SIZE) 
    {
        arr->data[arr->size++] = value;
    } 
    else 
    {
        printf("Array is full, cannot add more elements.\n");
    }
}

// Delete element (at a specific index)
void deleteElement(Array* arr, int index) 
{
    if (index < 0 || index >= arr->size) 
    {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < arr->size - 1; i++) 
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

// Modify an element at a specific index
void modifyElement(Array* arr, int index, int newValue) 
{

    if (index < 0 || index >= arr->size) 
    {
        printf("Invalid index.\n");
        return;
    }
    arr->data[index] = newValue;
}

// Insert an element at a specific position in the array
void insertElement(Array* arr, int index, int value) 
{
    if (index < 0 || index > arr->size || arr->size >= MAX_SIZE) 
    {
        printf("Invalid index or array is full.\n");
        return;
    }
    for (int i = arr->size; i > index; i--) 
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->size++;
}