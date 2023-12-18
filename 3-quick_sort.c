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
	int pivot = array[end], temp;
	size_t p_index = start, i;

	for (i = start ; i < end ; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[p_index];
			array[p_index] = temp;
			p_index++;
		}
	}
	array[end] = array[p_index];
	array[p_index] = pivot;
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

	if (start < end)
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
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}