#include "sort.h"

/**
 * swap - Swap the values of two integers.
 *
 * @xp: Pointer to the first integer to be swapped.
 * @ap: Pointer to the second integer to be swapped.
 */
void swap(int *xp, int *ap)
{
	int tmp;

	tmp  = *xp;
	*xp = *ap;
	*ap = tmp;
}

/**
 * selection_sort - Sort an integer array using the Selection Sort algorithm.
 * @array: Pointer to the integer array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: void (No return value).
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			temp = array[min_idx];
			array[min_idx] = array[i];
			array[i] = temp;
		}

		print_array(array, size);
	}
}
