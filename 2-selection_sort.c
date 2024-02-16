#include "sort.h"

/**
 * bubble_sort - Arrange Array (Bubble Sort Algorthim)
 *
 * @array: The array to Operated
 * @size: Number of elements in @array
 */

void selection_sort(int *array, size_t size);
{
	size_t repeat, i;
	int is_Swaped, tmp;

	for (repeat = 0; repeat < size; repeat++)
	{
		is_Swaped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				is_Swaped = 1;
			}
		}
		if (is_Swaped == 0)
			break;
	}
}
