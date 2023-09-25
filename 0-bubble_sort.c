#include "sort.h"

/**
 * swap - Swap the values of two integers.
 *
 * @xp: Pointer to the first integer to be swapped.
 * @ap: Pointer to the second integer to be swapped.
 */
void swap(int *xp, int *ap)
{
	int temp;

	temp  = *xp;
	*xp = *ap;
	*ap = temp;
}

/**
 * bubble_sort - Sort an integer array using the Bubble Sort algorithm.
 *
 * @array: Pointer to the integer array to be sorted.
 * @size: The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (size <= 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}

}
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
