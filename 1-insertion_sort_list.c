#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: Pointer to the first node
 * @right: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (!left || !right || left == right)
		return;

	left->next = right->next;
	if (right->next)
		right->next->prev = left;

	right->prev = left->prev;
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	right->next = left;
	left->prev = right;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using the insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
		}
		current = current->next;
	}
}
