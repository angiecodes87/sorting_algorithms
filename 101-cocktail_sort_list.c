#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers using Cocktail
 * shaker sort
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL)
	return;

	while (swapped)
	{
	swapped = 0;
	for (current = *list; current->next != NULL; current = current->next)
	{
	if (current->n > current->next->n)
	{
	swap_nodes(list, &current, &(current->next));
	swapped = 1;
	print_list(*list);
	}
	}

	if (!swapped)
	break;

	swapped = 0;
	for (; current->prev != NULL; current = current->prev)
	{
	if (current->n < current->prev->n)
	{
	swap_nodes(list, &(current->prev), &current);
	swapped = 1;
	print_list(*list);
	}
	}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to a pointer to the head of the list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *temp;

	if (*node1 == NULL || *node2 == NULL)
	return;

	if (*node1 == *node2)
	return;

	if ((*node1)->prev != NULL)
	(*node1)->prev->next = *node2;
	else
	*list = *node2;

	if ((*node2)->next != NULL)
	(*node2)->next->prev = *node1;

	temp = (*node2)->next;
	(*node2)->next = *node1;
	(*node1)->next = temp;

	temp = (*node2)->prev;
	(*node2)->prev = (*node1)->prev;
	(*node1)->prev = temp;
}

