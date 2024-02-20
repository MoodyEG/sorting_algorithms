#include "sort.h"

/**
 * swap - Swaps two linked lists nodes
 * @p1: pointer to the first node to swap
 * @p2: pointer to the second node to swap
 * @flag: flag for swapping direction (0 = right, 1 = left)
 * Return: No return
 */
void swap(listint_t **p1, listint_t **p2, int flag)
{
	listint_t *temp1, *temp2;

	temp1 = *p1;
	temp2 = *p2;
	temp1->next = temp2->next;
	temp2->prev = temp1->prev;
	if (temp2->next)
		temp2->next->prev = temp1;
	if (temp1->prev)
		temp1->prev->next = temp2;
	temp1->prev = temp2;
	temp2->next = temp1;
	if (flag)
		*p2 = temp1;
	else
		*p1 = temp2;
}
/**
 * move_right - Sorts using the Cocktail shaker sort algorithm
 * @list: Our list
 * @right: The rightmost position in the list that isn't sorted
 * @current: Current position
 * Return: No return
 */
void move_right(listint_t **list, listint_t **right, listint_t **current)
{
	listint_t *temp;

	temp = *current;
	while (temp != *right && temp->next != *right)
	{
		if (temp->n > temp->next->n)
		{
			swap(&temp, &(temp->next), 0);
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
		}
		temp = temp->next;
	}
	*right = temp;
	*current = temp;
}

/**
 * move_left - Sorts using the Cocktail shaker sort algorithm
 * @list: Our list
 * @left: The leftmost position in the list that isn't sorted
 * @current: Current position
 * Return: No return
 */
void move_left(listint_t **list, listint_t **left, listint_t **current)
{
	listint_t *temp;

	temp = *current;
	while (temp != *left && temp->prev != *left)
	{
		if (temp->n < temp->prev->n)
		{
			swap(&(temp->prev), &temp, 1);
			if (temp->prev->prev == NULL)
				*list = temp->prev;
			print_list(*list);
		}
		temp = temp->prev;
	}
	*left = temp;
	*current = temp;
}
/**
 * cocktail_sort_list - Sorts using the Cocktail shaker sort algorithm
 * @list: Our list
 * Return: No return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *right, *left;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	right = left = NULL;
	do {
		move_right(list, &right, &current);
		move_left(list, &left, &current);
	} while (right != left);
}
