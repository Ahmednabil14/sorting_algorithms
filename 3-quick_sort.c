#include "sort.h"
/**
 * partitioning - function that partitioning an array
 * @arr: the array
 * Return: the pivot position
*/
size_t partitioning(int *array, size_t start, size_t end)
{
    int pivot = array[end - 1], temp;
    size_t p_index = start, i;

    if (end <= start)
    {
        return (0);
    }
    for (i = start ; i <= end - 2 ; i++)
    {
        if (array[i] <= pivot)
        {
            temp = array[i];
            array[i] = array[p_index];
            array[p_index] = temp;
            p_index++;
        }
    }
    array[end - 1] = array[p_index];
    array[p_index] = pivot;
    print_array(array, end);
    return p_index;
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array of integrs
 * @size: the size of array
*/
void quick_sort(int *array, size_t size)
{
    size_t low = 0;
    size_t high = size - 1;
    size_t p_index;

    while (high > low)
    {
        p_index = partitioning(array, low, high);
        quick_sort(array, p_index + 1);
        high = p_index - 1;
    }
    
}