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
			current->prev = back->prev;
			if (back->prev != NULL)
				back->prev->next = current;

			back->prev = current;
			back->next = current->next;
			if (current->next != NULL)
				current->next->prev = back;

			current->next = back;

			if (current->prev == NULL)
				*list = current;
			print_list(*list);
			back = current->prev;
		}

		current = current->next;
	}
}
