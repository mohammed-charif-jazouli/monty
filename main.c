#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point
 * @argc: num of args
 * @argv: list of args
 *
 * Return: 0
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openf(argv[1]);
	freeN();
	return (0);
}

/**
 * add2Q - Adds a nd 2 d q
 * @n_nd: Ptr 2 d new nd
 * @len: line num of d opcode
*/

void add2Q(stack_t **n_nd, __attribute__((unused))unsigned int len)
{
	stack_t *t;

	if (n_nd == NULL || *n_nd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_nd;
		return;
	}
	t = head;
	while (t->next != NULL)
		t = t->next;

	t->next = *n_nd;
	(*n_nd)->prev = t;

}

/**
 * createN - Node creation
 * @nmt: Number to go inside the node
 *
 * Return: ptr to d node (Succes), NULL otherwise
*/
stack_t *createN(int nmt)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		eR(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = nmt;
	return (nd);
}

/**
 * freeN - Frees all nds
*/

void freeN(void)
{
	stack_t *t;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}
