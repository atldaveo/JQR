/**
 * @file sort.c
 * @author David Chung (david.chung1719@outlook.com)
 * @brief This program serves as a demonstration of a simple sorting algorithm. 
 * The program itself defines a function that executes a bubble sort with a basic
 * array. 
 * 
 * This submission closes issue #32
 * @version 2.0 (17MAR25)
 * @date 11Jan25
 */

#include <stdio.h>
#include <stdbool.h>

/** @brief Iterates through an array and swaps elements based on a value test between an element
 * and the following element until all numbers are in order from smallest to largest. 
 * 
 * @param generic_array Array to be sorted
 * @param num_count Number of elements in the array
 */
void
bubble_sort(int generic_array[], int num_count)
{
    int pass = 0;
    int index = 0;
    int temp = 0;
    int swapped = true;

    for (pass = num_count - 1; pass >= 0 && swapped != false; pass--)
    {
        swapped = false;
        for (index = 0; index < pass; index++)
        {
            if (generic_array[index] > generic_array[index + 1])                /**< If generic_array[index] is larger than generic_array[index + 1] */
            {
                temp = generic_array[index];                                    /**< Store generic_array[i] into temporary variable */
                generic_array[index] = generic_array[index + 1];                /**< Move generic_array[index + 1] to where generic_array[index] was  */
                generic_array[index + 1] = temp;                                /**< Replace generic_array[index + 1] value with content of temp variable */
                swapped = true;                                                 /**< Flip status variable `swapped` to true and move to next set */
            }
        }
    }
}

/**  * @brief Demonstrates the use of bubble_sort function with a simple array
 * 
 * @return int 
 */
int main()
{
    int new_array[6] = {2, 7, 3, 5, 4, 0};
    int array_elements = sizeof(new_array) / (sizeof(new_array[0])); 
    
    bubble_sort(new_array, array_elements);

    for (int iteration = 0; iteration < array_elements; iteration++)
    {
        printf("%d  ", new_array[iteration]);
    }
    printf("\n");

    return 0;
}

/*
Works Cited

Karumanchi N. Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles, 5th ed. CareerMonk Publications; 2017.   
*/

/* END OF FILE */