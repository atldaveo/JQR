/**
 * @file issue-24.c
 * @author David Chung (david.chung1719@outlook.com)
 * @brief Fulfills requirements for JQR-Basic Issue 24
 * @version 1
 * @date 08Jan25
 * 
 */


#include <stdio.h>

/**
 * @brief Function that takes all elements of a 4x4 array and finds the sum
 * 
 * @param array 4x4 array
 * @return int Sum of the elements in the array
 */
int array_sum(int array[4][4])
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += array[i][j];
        }
    }

    return sum;
}

int main()
{
    int sum_total = 0;
    int my_array[4][4] = 
    {
        {
            1, 1, 1, 1
        },
        {
            1, 1, 1, 1
        },
        {
            1, 1, 1, 1
        },
        {
            1, 1, 1, 1
        }       
    };

    sum_total = array_sum(my_array);
    printf("The sum of all the elements in the array is %d\n", sum_total);

    return 0;

}