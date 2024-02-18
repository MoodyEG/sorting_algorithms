#include "sort.h"

/**
 * quick_sort - Sorts using the Quick sort algorithm
 * @array: Out array to sort
 * @size: The size of the array
 * Return: No return
 */
void quick_sort(int *array, size_t size)
{
	_quick(array, size, 0, size - 1);
}
/**
 * _quick - Sorts using the Quick sort algorithm
 * @array: Out array to sort
 * @size: The size of the array
 * @left: the left side
 * @right: the right side
 * Return: No return
 */
void _quick(int *array, size_t size, int left, int right)
{
	int i, j, temp;

	if (left < right)
	{
		i = left;
		for (j = left; j < right; j++)
		{
			if (array[j] < array[right])
			{
				if (j != i)
				{
					temp = array[j];
					array[j] = array[i];
					array[i] = temp;
					print_array(array, size);
				}
				i++;
			}
		}
		if (array[i] != array[right])
		{
			temp = array[right];
			array[right] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		_quick(array, size, left, i - 1);
		_quick(array, size, i + 1, right);
	}
}
