#include "sort.h"

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
				array[j] = array[j - gap];
				j = j - gap;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
