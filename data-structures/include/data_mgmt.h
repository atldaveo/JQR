#ifndef DATA_MGMT_H
#define DATA_MGMT_H

// Function Declarations
Array* createArray();

void addElement(Array* arr, int value);

void deleteElement(Array* arr, int index);

void modifyElement(Array* arr, int index, int newValue); 

void insertElement(Array* arr, int index, int value);

#endif