#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to a pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = *list;
	current = sorted->next;

	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		sorted = current;
		current = next;
	}
}

