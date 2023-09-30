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
 * partition - Partition the array and return the pivot index.
 *
 * @array: Pointer to the integer array to be partitioned.
 * @low: Index of the lowest element in the partition.
 * @high: Index of the highest element in the partition.
 *
 * Return: The pivot index.
 */
int partition(int arr[], int low, int high)
{
	int pivot, i, j;

	pivot = arr[high];

	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * quick_sort_helper - Recursively sort an integer array using Quick Sort.
 *
 * @array: Pointer to the integer array to be sorted.
 * @low: Index of the lowest element in the current partition.
 * @high: Index of the highest element in the current partition.
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		print_array(array,size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}

}

/**
 * quick_sort - Sort an integer array using the Quick Sort algorithm.
 *
 * @array: Pointer to the integer array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

