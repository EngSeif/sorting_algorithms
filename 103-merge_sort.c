#include "sort.h"

/**
 * Merge - Merge Small Arrays
 *
 * @array: The array to Operated
 * @l_size: Number of elements in left side
 * @r_size: Number of elements in right side
 */

void Merge(int *array, size_t l_size, size_t r_size)
{
	size_t size = l_size + r_size;
	size_t l = 0, r = l_size, k = 0;
	int *merge = malloc(size * sizeof(int));

	if (merge == NULL)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, l_size);
	printf("[right]: ");
	print_array(array + l_size, r_size);
	while (l < l_size && r < size)
	{
		if (array[l] <= array[r])
			merge[k++] = array[l++];
		else
			merge[k++] = array[r++];
	}

	while (l < l_size)
		merge[k++] = array[l++];

	while (r < size)
		merge[k++] = array[r++];

	for (k = 0; k < size; k++)
		array[k] = merge[k];

	printf("[Done]: ");
	print_array(array, size);
	free(merge);
}

/**
 * Merge_Alg - Split Arrays
 *
 * @array: The array to Operated
 * @size: Number of elements in @array
 */

void Merge_Alg(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		Merge_Alg(array, mid);
		Merge_Alg(array + mid, size - mid);
		Merge(array, mid, size - mid);
	}
}

/**
 * merge_sort - Arrange Array (Merge Sort Algorthim)
 *
 * @array: The array to Operated
 * @size: Number of elements in @array
 */

void merge_sort(int *array, size_t size)
{
	if (!array || !size || size == 1)
		return;

	Merge_Alg(array, size);
}
