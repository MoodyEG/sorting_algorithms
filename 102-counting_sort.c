#include "sort.h"

/**
 * counting_sort - Sorts using the Counting sort algorithm
 * @array: Out array to sort
 * @size: The size of the array
 * Return: No return
 */
void counting_sort(int *array, size_t size)
{
	int s = 0, i, *count, *a;

	if (size < 2 || !array)
		return;
	for (i = 0; i < (int)size; i++)
		if (array[i] > s)
			s = array[i];
	count = malloc(sizeof(int) * (s + 1));
	if (!count)
		return;
	a = malloc(sizeof(int) * (size + 1));
	if (!a)
	{
		free(count);
		return;
	}
	for (i = 0; i <= s; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= s; i++)
		count[i] += count[i - 1];
	print_array(count, s + 1);
	for (i = 0; i < (int)size; i++)
	{
		a[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = a[i];
	free(a);
	free(count);
	/*free(mysoul);*/
}
