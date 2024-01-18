#include "monty.h"

/**
 * modNd - Adds d 1st 2 elts
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @l_num: Int rprsntng d ln num of d op
 *
 * Return: Nothing
*/

void modNd(stack_t **sf, unsigned int l_num)
{
	int s;

	if (sf == NULL || *sf == NULL || (*sf)->next == NULL)
		moreR(8, l_num, "mod");
	if ((*sf)->n == 0)
		moreR(9, l_num);
	(*sf) = (*sf)->next;
	s = (*sf)->n % (*sf)->prev->n;
	(*sf)->n = s;
	free((*sf)->prev);
	(*sf)->prev = NULL;
}

/**
 * mulNd - Adds d 1st 2 elts
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @l_num: Int rprsntng d ln num of d op
 *
 * Return: Nothing
*/

void mulNd(stack_t **sf, unsigned int l_num)
{
	int s;

	if (sf == NULL || *sf == NULL || (*sf)->next == NULL)
		moreR(8, l_num, "mul");

	(*sf) = (*sf)->next;
	s = (*sf)->n * (*sf)->prev->n;
	(*sf)->n = s;
	free((*sf)->prev);
	(*sf)->prev = NULL;
}
