#include "sort.h"

/**
 * partition - Make partition (Quick Sort Algorthim)
 *
 * @array: The array to Operated
 * @low: low index
 * @high: high index
 * @size: Number of elements in @array
 * Return: Index
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i += 1;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
	i += 1;
	tmp = array[high];
	array[high] = array[i];
	array[i] = tmp;
	print_array(array, size);

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
		int Pv_indx;

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
	QS_Recursive(array, 0, size - 1, size);
}
