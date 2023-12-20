#include "sort.h"
/**
 * counting_sort - function that sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the array size
*/
void counting_sort(int *array, size_t size)
{
	size_t i, k = 0;
	int *count, *temp;

	if (!array || size <= 0)
		return;
	for (i = 0 ; i < size ; i++)
	{
		if (array[i] > (int)k)
		{
			k = array[i];
		}
	}
	count = malloc(sizeof(int) * k + 1);
	for (i = 0 ; i <= k ; i++)
	{
		count[i] = 0;
	}
	for (i = 0 ; i < size ; i++)
	{
		count[array[i]]++;
	}
	for (i = 1 ; i <= k ; i++)
	{
		count[i] += count[i - 1];
	}
	temp = malloc(sizeof(int) * size);
	for (i = size - 1 ; (int)i >= 0 ; i--)
	{
		temp[--count[array[i]]] = array[i];
	}
	for (i = 0 ; i < size ; i++)
	{
		array[i] = temp[i];
	}
	print_array(count, k + 1);
	free(count);
	free(temp);
}
