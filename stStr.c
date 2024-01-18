#include "monty.h"

/**
 * printSt - Prints an str
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @lnnm: Int rprsntng the lne num of d op
 *
 * Return: Nothing
*/

void printSt(stack_t **sf, __attribute__((unused))unsigned int lnnm)
{
	int asc;
	stack_t *tp;

	if (sf == NULL || *sf == NULL)
	{
		printf("\n");
		return;
	}

	tp = *sf;
	while (tp != NULL)
	{
		asc = tp->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		tp = tp->next;
	}
	printf("\n");
}

/**
 * rTr - Rotates d last nd of d stck 2 d top
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @ln: Int rprsntng the lne num of d op
 *
 * Return: Nothing
*/

void rTr(stack_t **sf, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (sf == NULL || *sf == NULL || (*sf)->next == NULL)
		return;

	tp = *sf;

	while (tp->next != NULL)
		tp = tp->next;

	tp->next = *sf;
	tp->prev->next = NULL;
	tp->prev = NULL;
	(*sf)->prev = tp;
	(*sf) = tp;
}

/**
 * rT - Rotates d 1st nd of d stack 2 d bottom
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @ln: Int rprsntng the lne num of d op
 *
 * Return: Nothing
*/

void rT(stack_t **sf, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (sf == NULL || *sf == NULL || (*sf)->next == NULL)
		return;

	tp = *sf;
	while (tp->next != NULL)
		tp = tp->next;

	tp->next = *sf;
	(*sf)->prev = tp;
	*sf = (*sf)->next;
	(*sf)->prev->next = NULL;
	(*sf)->prev = NULL;
}

/**
 * printCh - Prints d Ascii val
 * @sf: Ptr 2 a ptr ptg 2 1st nd
 * @l_num: Int rprsntng the lne num of d op
 *
 * Return: Nothing
*/

void printCh(stack_t **sf, unsigned int l_num)
{
	int asc;

	if (sf == NULL || *sf == NULL)
		stringR(11, l_num);
	asc = (*sf)->n;
	if (asc < 0 || asc > 127)
		stringR(10, l_num);
	printf("%c\n", asc);
}
