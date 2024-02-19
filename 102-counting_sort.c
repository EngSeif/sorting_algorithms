#include "sort.h"

/**
 * counting_sort - Arrange Array (Counting Sort Algorthim)
 *
 * @array: The array to Operated
 * @size: Number of elements in @array
 */

void counting_sort(int *array, size_t size)
{
	int max = 0;
	size_t i, C_size;
	int *counting_array, *output;

	if (!array || !size)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	C_size = max + 1;
	counting_array = (int *)malloc((C_size) * sizeof(int));
	output = (int *)malloc((size) * sizeof(int));
	if (counting_array == NULL || output == NULL)
		return;
	for (i = 0; i < C_size; i++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		output[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]] += 1;
	for (i = 0; i < C_size - 1; i++)
		counting_array[i + 1] = counting_array[i + 1] +  counting_array[i];
	print_array(counting_array, C_size);
	for (i = size - 1; i > 0 ; i--)
	{
		output[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	output[counting_array[array[i]] - 1] = array[i];
	counting_array[array[i]]--;
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(counting_array);
}
