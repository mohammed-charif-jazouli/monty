#include "monty.h"

/**
 * subNd - Adds d 1st 2 elts
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @l_num: Int rprsntng d ln num of d op
 *
 * Return: Nothing
*/

void subNd(stack_t **sf, unsigned int l_num)
{
	int s;

	if (sf == NULL || *sf == NULL || (*sf)->next == NULL)

		moreR(8, l_num, "sub");


	(*sf) = (*sf)->next;
	s = (*sf)->n - (*sf)->prev->n;
	(*sf)->n = s;
	free((*sf)->prev);
	(*sf)->prev = NULL;
}

/**
 * swapN - Swaps 1st 2 elmts
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @l_num: Int rprstg d lne num of d op
 *
 * Return: Nothing
*/

void swapN(stack_t **sf, unsigned int l_num)
{
	stack_t *tp;

	if (sf == NULL || *sf == NULL || (*sf)->next == NULL)
		moreR(8, l_num, "swap");
	tp = (*sf)->next;
	(*sf)->next = tp->next;
	if (tp->next != NULL)
		tp->next->prev = *sf;
	tp->next = *sf;
	(*sf)->prev = tp;
	tp->prev = NULL;
	*sf = tp;
}

/**
 * divNd - Adds d 1st 2 elts
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @l_num: Int rprsntng d ln num of d op
 *
 * Return: Nothing
*/

void divNd(stack_t **sf, unsigned int l_num)
{
	int s;

	if (sf == NULL || *sf == NULL || (*sf)->next == NULL)
		moreR(8, l_num, "div");

	if ((*sf)->n == 0)
		moreR(9, l_num);
	(*sf) = (*sf)->next;
	s = (*sf)->n / (*sf)->prev->n;
	(*sf)->n = s;
	free((*sf)->prev);
	(*sf)->prev = NULL;
}

/**
 * addNd - Adds d 1st 2 elts
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @l_num: Int rprsntng d ln num of d op
 *
 * Return: Nothing
*/

void addNd(stack_t **sf, unsigned int l_num)
{
	int s;

	if (sf == NULL || *sf == NULL || (*sf)->next == NULL)
		moreR(8, l_num, "add");

	(*sf) = (*sf)->next;
	s = (*sf)->n + (*sf)->prev->n;
	(*sf)->n = s;
	free((*sf)->prev);
	(*sf)->prev = NULL;
}

/**
 * nP - nothing
 * @sf: Ptr 2 a ptr ptg to 1st nd
 * @l_num: Int rprsntng d ln num of d op
 *
 * Return: Nothing
*/

void nP(stack_t **sf, unsigned int l_num)
{
	(void)sf;
	(void)l_num;
}
