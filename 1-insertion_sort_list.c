#include "sort.h"

/**
 * insertion_sort_list - Arrange List (Insertion Algorthim)
 *
 * @list: The list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *back;

	if (list == NULL || *list == NULL || current == NULL)
		return;

	while (current != NULL)
	{
		back = current->prev;
		while (back != NULL && back->n > current->n)
		{
			if (current->next != NULL)
				current->next->prev = back;
			if (back->prev != NULL)
				back->prev->next = current;
			current->prev = back->prev;
			back->next = current->next;
			current->next = back;
			back->prev = current;

			if (current->prev == NULL)
				*list = current;
			print_list(*list);
			back = current->prev;
		}

		current = current->next;
	}
}
