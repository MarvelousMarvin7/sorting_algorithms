#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sort linked list in ascending order
 * using isertion sort
 * @list: pointer to doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (*list == NULL)
		return;

	current = *list;

	while (current)
	{
		while (current->next && (current->n > current->next->n))
		{
			temp = current->next;
			current->next = temp->next;
			temp->prev = current->prev;

			if (current->prev)
				current->prev->next = temp;
			if (temp->next)
				temp->next->prev = current;

			current->prev = temp;
			temp->next = current;

			if (temp->prev)
				current = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
