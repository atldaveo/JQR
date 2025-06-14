/**
 * @file cll-test.c
 * @author David Chung
 * @brief 
 * @version 0.1 (12APR25)
 * @date 13Feb25
 * 
 * @brief Tests funcionality of the circularly linked list 
 * and its functions as per "cll.c"
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cll.h"

#define     DATA1   10
#define     DATA2   20
#define     DATA3   30
#define     DATA4   40
#define     PASS    0

// CLL Testing
int
main(void)
{
    Node* p_tail = NULL;
    int data1 = 0;
    int data2 = 0;
    int data3 = 0;
    int data4 = 0;

    data1 = DATA1;
    data2 = DATA2;
    data3 = DATA3;
    data4 = DATA4;

    // Insert elements
    insert_at_end(&p_tail, &data1);
    insert_at_end(&p_tail, &data2);
    insert_at_end(&p_tail, &data3);
    insert_at_end(&p_tail, &data4);

    printf("Circular Linked List after insertion:\n");
    traverse(p_tail, print_int_data);

    // Delete an element
    printf("\nDeleting 20 from the list:\n");
    delete_node(&p_tail, &data2, compare_int_data);
    traverse(p_tail, print_int_data);

    // Delete another element
    printf("\nDeleting 40 from the list:\n");
    delete_node(&p_tail, &data4, compare_int_data);
    traverse(p_tail, print_int_data);

    return PASS;
}

/*******************  END OF FILE *******************************/