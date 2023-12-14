#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (temp1 = (*list)->next; temp1 && temp1->prev; temp1 = temp1->next)
	{
		while (temp1 && temp1->prev && temp1->n < temp1->prev->n)
		{
			temp2 = temp1->prev;
			swap(list, temp2, temp1);
			print_list(*list);
			temp1 = temp1->next;
			temp1 = temp1->prev;
		}
	}
}
/**
 * swap - function that swap two node
 * @list: doubly linked list
 * @node1: pointer to node
 * @node2: pointer to node
 * Return: void
*/
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
	{
		prev->next = node2;
	}
	else
	{
		*list = node2;
	}
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
	{
		next->prev = node1;
	}
}
