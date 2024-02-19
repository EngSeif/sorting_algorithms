#include "sort.h"

/**
 * Swap_Nodes - Swap Two Adjacent Nodes
 * @list: The list
 * @node1: first Node
 * @node2: second Node
 */

void Swap_Nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	print_list(*list);
}


/**
 * cocktail_sort_list - Arrange List (Cocktail Algorthim)
 *
 * @list: The list
 */
void cocktail_sort_list(listint_t **list)
{
	int is_swaped;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	if ((*list)->next == NULL)
		return;

	do {
		is_swaped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				Swap_Nodes(list, current, current->next);
				is_swaped = 1;
			}
			else
				current = current->next;
		}
		if (!is_swaped)
			break;
		is_swaped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				Swap_Nodes(list, current->prev, current);
				is_swaped = 1;
			}
			else
				current = current->prev;
		}
	} while (is_swaped);
}
