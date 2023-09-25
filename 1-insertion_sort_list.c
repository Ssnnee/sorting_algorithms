#include "sort.h"

/**
 * length - Calculate the length of a singly-linked list.
 * @head: Pointer to the head node of the linked list.
 *
 * Return: The length of the linked list, or 0 if the list is empty.
 */
int length(listint_t *head)
{
	if (head == NULL)
		return (0);

	return (1 + length(head->next));
}

/**
 * insertion_sort_list - Sort a doubly-linked
 * list of integers using Insertion Sort.
 * @list: A pointer to a pointer to the
 * head of the doubly-linked list to be sorted.
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crt, *next_node, *tmp;

	if (list == NULL || *list == NULL || length(*list) < 2)
		return;

	crt = (*list)->next;
	while (crt != NULL)
	{
		next_node = crt->next;
		tmp = crt->prev;

		while (tmp != NULL && crt->n < tmp->n)
			tmp = tmp->prev;

		if (tmp == NULL) /* crt is the smallest in the list*/
		{
			crt->prev->next = crt->next;
			if (crt->next != NULL)
				crt->next->prev = crt->prev;
			crt->next = *list;
			crt->prev = NULL;
			(*list)->prev = crt;
			*list = crt;
			print_list(*list);
		}
		else if (crt->n != tmp->n) /*crt most be btw tmp and tmp->n*/
		{
			crt->prev->next = crt->next;
			if (crt->next != NULL)
				crt->next->prev = crt->prev;
			crt->next = tmp->next;
			crt->prev = tmp;
			tmp->next->prev = crt;
			tmp->next = crt;
			print_list(*list);
		}
		crt = next_node;
	}
}
