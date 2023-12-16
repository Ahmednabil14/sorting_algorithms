#include "sort.h"

/**
 * selection_sort - function that sort an array using
 * the Selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t position = 0;
	int min = 0;
	int flag;

	if (!array)
	{
		return;
	}
	for (i = 0 ; i < size - 1 ; i++)
	{
		position = i;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[position])
			{
				position = j;
				flag = 1;
			}
		}
		min = array[position];
		array[position] = array[i];
		array[i] = min;
		if (flag == 1)
			print_array(array, size);
		flag = 0;
	}
}
