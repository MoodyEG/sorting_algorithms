#include "sort.h"

/**
 * bubble_sort - Sorts using the Bubble sort algorithm
 * @array: Out array to sort
 * @size: The size of the array
 * Return: No return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, n;
	int temp, best = 1;

	n = size;
	while (n && best)
	{
		best = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				best = 1;
			}
		}
	n--;
	}
}
