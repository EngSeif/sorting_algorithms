#include "sort.h"

/**
 * Swap - Swap Two Elements
 *
 * @a: 1st Element
 * @b: 2nd Element
 * Return: None
 */
void Swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}

/**
 * shell_sort - Arrange Array (Shell Sort Algorthim)
 *
 * @array: The array to Operated
 * @size: Number of elements in @array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int key;


	while (gap * 3 + 1 < size)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			key = array[i];
			j = i;

			while (j >= gap && array[j - gap] > key)
			{
				Swap(&array[j - 1], &array[j]);
				j = j - gap;
			}
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
