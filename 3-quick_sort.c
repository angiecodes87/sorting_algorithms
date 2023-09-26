#include "sort.h"

/**
 * swap_elements - Swaps the positions of two elements in an integer array
 *
 * @array: The integer array
 * @index1: Index of the first element to be swapped
 * @index2: Index of the second element to be swapped
 */
void swap_elements(int *array, ssize_t index1, ssize_t index2)
{
	int tmp = array[index1];

	array[index1] = array[index2];
	array[index2] = tmp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for quicksort
 *
 * @array: The integer array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the array
 *
 * Return: The position of the pivot element after partitioning
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
			swap_elements(array, i, j);
			print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap_elements(array, i + 1, high);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort_recursive - Recursive implementation of the Quick Sort algorithm
 *
 * @array: The integer array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the array
 */
void quicksort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
	int pivot_pos = lomuto_partition(array, low, high, size);

	quicksort_recursive(array, low, pivot_pos - 1, size);
	quicksort_recursive(array, pivot_pos + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an integer array in ascending order using the Quick Sort
 * algorithm
 *
 * @array: The integer array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	return;

	quicksort_recursive(array, 0, size - 1, size);
}

