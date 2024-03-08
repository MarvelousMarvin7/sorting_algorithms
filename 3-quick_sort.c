#include "sort.h"
#include <stdio.h>

/**
 * swap - swap numbers in an array
 * @array: array to be swapped
 * @left: left number
 * @right: right number
 * @size: size of array
 * Return: Nothing
 */
void swap(int *array, size_t left, size_t right, size_t size)
{
	int temp;

	if (array != NULL)
	{
		temp = array[left];
		array[left] = array[right];
		array[right] = temp;

		print_array(array, size);
	}
}

/**
 * lomuto_partition - partition numbers
 * @array: array to partition
 * @low: low sub array to partion
 * @high: high sub array to partition
 * @size: size of array
 * Return: Nothing
 */
void lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(array, i, j, size);
			}
			i++;
		}
	}
	if (i != high)
		swap(array, i, high, size);
	if (i - low > 1)
		lomuto_partition(array, low, i - 1, size);
	if (high - i > 1)
		lomuto_partition(array, i + 1, high, size);
}
/**
 * quick_sort - quick sort implementatio
 * @array: to sort
 * @size: size of array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		lomuto_partition(array, 0, size - 1, size);
	}
}
