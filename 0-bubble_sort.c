#include "sort.h"

/**
 * bubble_sort - sort function
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: 0 on success
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, swapped;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
