#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: The size of the array
 */

void shell_sort(int *array, size_t size)
{
    size_t interval = 1;
    size_t i, j;
    int temp;

    if (array == NULL || size < 2)
        return;
}