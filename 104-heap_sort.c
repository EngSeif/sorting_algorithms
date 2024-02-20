#include "sort.h"

/**
 * heapify - Make Heap Max
 *
 * @array: The array to Operated
 * @size: Number of elements in @array
 * @i: Largest Index
 * @m: original size (Used In Printing)
 */

void heapify(int *array, size_t size, size_t i, size_t m)
{
	size_t big = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int tmp;

	if (left < size && array[left] > array[big])
		big = left;

	if (right < size && array[right] > array[big])
		big = right;

	if (big != i)
	{
		tmp = array[i];
		array[i] = array[big];
		array[big] = tmp;
		print_array(array, m);
		heapify(array, size, big, m);
	}
}

/**
 * heap_sort - Arrange Array (Heap Sort Algorthim)
 *
 * @array: The array to Operated
 * @size: Number of elements in @array
 */

void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (!array || !size || size == 1)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
