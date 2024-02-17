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
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
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

	if (!array || !size)
		return;

	while (gap < size)
		gap = gap * 3 + 1;

	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			key = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] > key)
			{
				Swap(&array[j], &array[j - gap]);
				j = j - gap;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
