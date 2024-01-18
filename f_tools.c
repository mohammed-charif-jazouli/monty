#include "monty.h"

/**
 * parsel - it separates each ln in2 tks
 * @buf: ln from d f
 * @l_num: ln num
 * @fo:  strg fo
 *
 * Return: 0 (stack), 1 (queue)
*/

int parsel(char *buf, int l_num, int fo)
{
	char *op, *val;
	const char *del = "\n ";

	if (buf == NULL)
		eR(4);

	op = strtok(buf, del);
	if (op == NULL)
		return (fo);
	val = strtok(NULL, del);

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	findFc(op, val, l_num, fo);
	return (fo);
}

/**
 * callF - Calls req funct
 * @fc: ptr 2 d that func
 * @op: opcode's str
 * @val: a num val's str
 * @lnnm: ln num
 * @fo: fo specif
 *
 * Return: Nothing
*/

void callF(op_func fc, char *op, char *val, int lnnm, int fo)
{
	stack_t *nd;
	int fg = 1;
	int x;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fg = -1;
		}
		if (val == NULL)
			eR(5, lnnm);
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
				eR(5, lnnm);
		}
		nd = createN(atoi(val) * fg);
		if (fo == 0)
			fc(&nd, lnnm);
		if (fo == 1)
			add2Q(&nd, lnnm);
	}
	else
		fc(&head, lnnm);
}

/**
 * findFc - fd d approp func
 * @opcode: op
 * @val: arg of op
 * @fo:  strg fo
 * @lnnm: ln num
 *
 * Return: Nothing
*/
void findFc(char *opcode, char *val, int lnnm, int fo)
{
	int x;
	int fg;

	instruction_t func_list[] = {
		{"push", add2S},
		{"pall", printS},
		{"pint", printT},
		{"pop", popT},
		{"nP", nP},
		{"swap", swapN},
		{"add", addNd},
		{"sub", subNd},
		{"div", divNd},
		{"mul", mulNd},
		{"mod", modNd},
		{"pchar", printCh},
		{"pstr", printSt},
		{"rT", rT},
		{"rTr", rTr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fg = 1, x = 0; func_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func_list[x].opcode) == 0)
		{
			callF(func_list[x].f, opcode, val, lnnm, fo);
			fg = 0;
		}
	}
	if (fg == 1)
		eR(3, lnnm, opcode);
}

/**
 * readf - reads a f
 * @fg: ptr 2 f desc
 *
 * Return: Nothing
*/

void readf(FILE *fg)
{
	int l_num = 1, fo = 0;
	char *buf = NULL;
	size_t l = 0;

	for (; getline(&buf, &l, fg) != -1; l_num++)
	{
		fo = parsel(buf, l_num, fo);
	}
	free(buf);
}

/**
 * openf - opens a f
 * @f_nm: f nmpath
 *
 * Return: Nothing
*/

void openf(char *f_nm)
{
	FILE *fg = fopen(f_nm, "r");

	if (f_nm == NULL || fg == NULL)
		eR(2, f_nm);

	readf(fg);
	fclose(fg);
}
