#include "sort.h"

/**
 * *swap_node - swap a node
 * @node: node
 * @list: node list
 * Return: pointer
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *new = node->prev;
	listint_t *current = node;

	new->next = current->next;
	if (current->next)
		current->next->prev = new;
	current->next = new;
	current->prev = new->prev;
	new->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}

/**
 * insertion_sort_list - that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Doubly linked list to sort.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
