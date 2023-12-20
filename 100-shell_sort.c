#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j;
	int temp, i, x = 0;

	while (gap < size)
	{
		gap = (gap * 3) + 1;
	}
	for (; gap >= 1 ; gap = (gap - 1) / 3)
	{
		for (j = gap ; j < size ; j++)
		{
			for (i = j - gap ; i >= 0 ; i = i - gap)
			{
				if (array[i + gap] < array[i])
				{
					temp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = temp;
				}
				else
				{
					break;
				}
			}
		}
		if (x == 1)
			print_array(array, size);
		x = 1;
	}

}
