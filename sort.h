#ifndef SORT_H
#define SORT_H


/* ========= Libraires Used ========= */


#include <stdlib.h>
#include <stdio.h>


/* ======== Data Structures ======== */


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


/* ======== Tools.c Functions ======== */


void print_list(const listint_t *list);
void print_array(const int *array, size_t size);


/* ======== Task Functions ======== */


void bubble_sort(int *array, size_t size);


#endif