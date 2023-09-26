#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array
 * @array: The array of integers
 * @idx1: Index of the first integer to swap
 * @idx2: Index of the second integer to swap
 * @size: Size of the array
 */

void swap(int *array, int idx1, int idx2, size_t size)
{
	int temp;

	if (array[idx1] != array[idx2])
	{
		temp = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partitions array using Lomuto partition scheme
 * @array: The array of integers to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Size of the array
 * Return: The index of the pivot element
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	swap(array, i + 1, high, size);
	return (i + 1);
}

/**
 * quicksort - Recursive function to perform quick sort
 * @array: The array of integers to be sorted
 * @low: The starting index of the subarray
 * @high: The ending index of the subarray
 * @size: Size of the array
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array of integers to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

