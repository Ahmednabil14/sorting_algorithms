#include "sort.h"
/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list;
	listint_t *end;
	listint_t *i = *list;
	listint_t *temp;

	if (!list || !*list)
	{
		return;
	}
	while (i)
	{
		if (i->n > i->next->n)
		{
			temp = i;
			i->prev = i->next;
			i->next = i->next->next;
			i->next->prev = temp->prev;
			i->next->next = temp->prev;
		}
		i = i->next;
	}
	print_list(*list);
}
