#include "monty.h"

/**
 * popT - Adds a nd
 * @st: Dbl ptr to 1st nd
 * @l_nm: int rprsntng d ln num of d op
 * Return: Nothing
*/

void popT(stack_t **st, unsigned int l_nm)
{
	stack_t *tp;

	if (st == NULL || *st == NULL)
		moreR(7, l_nm);

	tp = *st;
	*st = tp->next;
	if (*st != NULL)
		(*st)->prev = NULL;
	free(tp);
}

/**
 * printS - Adds a nd
 * @st: Dbl ptr to 1st nd
 * @l_nm: ln num of d op
 *
 * Return Nothing
*/

void printS(stack_t **st, unsigned int l_nm)
{
	stack_t *tp;

	(void) l_nm;
	if (st == NULL)
		exit(EXIT_FAILURE);
	tp = *st;
	while (tp != NULL)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
	}
}

/**
 * printT - Prints d 1st nd
 * @st: dble ptr to 1st nd
 * @l_nm: int rprstg d ln num of d op
 *
 * Return: Nothing
*/

void printT(stack_t **st, unsigned int l_nm)
{
	if (st == NULL || *st == NULL)
		moreR(6, l_nm);
	printf("%d\n", (*st)->n);
}

/**
 * add2S - Adds a nd
 * @n_nd: Ptr to d new nd
 * @l: Int rprsntng d ln num of d op
 *
 * Return: Nohing
*/

void add2S(stack_t **n_nd, __attribute__((unused))unsigned int l)
{
	stack_t *tp;

	if (n_nd == NULL || *n_nd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_nd;
		return;
	}
	tp = head;
	head = *n_nd;
	head->next = tp;
	tp->prev = head;
}
