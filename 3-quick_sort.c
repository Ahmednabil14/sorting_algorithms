#include "sort.h"
/**
 * partitioning - function that partitioning an array
 * @array: the array
 * @size: the array size
 * @start: the start of partitioning
 * @end: end of partitioning
 * Return: the pivot position
*/
size_t partitioning(int *array, size_t size, size_t start, size_t end)
{
	int pivot, temp, falg = 0, flag = 0;
	size_t p_index, i;

	pivot = array[end];
	p_index = start;

	for (i = start ; i < end ; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[p_index];
			array[p_index] = temp;
			falg = 1;
			flag = 1;
			p_index++;
		}
		if (falg == 1)
			print_array(array, size);
		falg = 0;
	}
	array[end] = array[p_index];
	array[p_index] = pivot;
	if (flag == 1)
		print_array(array, size);
	return (p_index);
}

/**
 * quicksort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @arr: the array
 * @size: the array size
 * @start: the start of partitioning
 * @end: end of partitioning
*/
void quicksort(int arr[], size_t size, size_t start, size_t end)
{
	size_t p_index;

	if (start < end && end < size)
	{
		p_index = partitioning(arr, size, start, end);
		quicksort(arr, size, start, p_index - 1);
		quicksort(arr, size, p_index + 1, end);
	}
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array of integrs
 * @size: the size of array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
	print_array(array, size);
}
