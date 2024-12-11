#ifndef linkedlist_H
#define linkedlist_H

Node* createNode(void* data);

void addNode(Node** head, void* data);

void deleteNode(Node** head, int index);

void modifyNode(Node* head, int index, void* newData);

void insertNode(Node** head, int index, void* data);

#endif