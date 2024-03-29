#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void _quick(int *array, size_t size, int left, int right);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void move_right(listint_t **list, listint_t **right, listint_t **current);
void move_left(listint_t **list, listint_t **left, listint_t **current);
void swap(listint_t **p1, listint_t **p2, int flag);
void counting_sort(int *array, size_t size);

#endif /* SORT_H */
