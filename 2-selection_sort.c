#include "sort.h"

/**
 * selection_sort - Sorts using the Selection sort algorithm
 * @array: Out array to sort
 * @size: The size of the array
 * Return: No return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	for (i = 0; i < size; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		if (k != i)
		{
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
			print_array(array, size);
		}
	}
}
