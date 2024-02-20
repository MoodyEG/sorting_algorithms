#include "sort.h"

/**
 * shell_sort - Sorts using the Shell sort algorithm
 * @array: Out array to sort
 * @size: The size of the array
 * Return: No return
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;
	int temp;

	if (!array)
		return;
	while (gap * 3 + 1 < size)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j > gap - 1 ; j -= gap)
			{
				if (array[j] < array[j - gap])
				{
					temp = array[j];
					array[j] = array[j - gap];
					array[j - gap] = temp;
				}
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
