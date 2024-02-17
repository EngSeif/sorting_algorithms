#include "sort.h"

/**
 * Swap - Swap Two Elements
 *
 * @a: 1st Element
 * @b: 2nd Element
 * @array: The array to Operated
 * @size: Number of elements in @array
 * Return: None
 */
void Swap(int *a, int *b, int *array, size_t size)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array(array, size);
	}
}
/**
 * partition - Make partition (Quick Sort Algorthim)
 *
 * @array: The array to Operated
 * @low: low index
 * @high: high index
 * @size: Number of elements in @array
 * Return: Index
 */

size_t partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			Swap(&array[i], &array[j], array, size);
			i++;
		}
	}
	Swap(&array[i], &array[high], array, size);
	return (i);
}

/**
 * QS_Recursive - Make Recursion (Quick Sort Algorthim)
 *
 * @array: The array to Operated
 * @low: low index
 * @high: high index
 * @size: Number of elements in @array
 */

void QS_Recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		size_t Pv_indx;

		Pv_indx = partition(array, low, high, size);
		QS_Recursive(array, low, Pv_indx - 1, size);
		QS_Recursive(array, Pv_indx + 1, high, size);
	}
}

/**
 * quick_sort - Arrange Array (Quick Sort Algorthim)
 *
 * @array: The array to Operated
 * @size: Number of elements in @array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	QS_Recursive(array, 0, size - 1, size);
}
