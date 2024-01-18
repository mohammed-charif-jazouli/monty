#include "monty.h"

/**
 * stringR - handles err
 * @errCd: error codes
 *
 * Return: Nothing
*/

void stringR(int errCd, ...)
{
	va_list arrg;
	int l_num;

	va_start(arrg, errCd);
	l_num = va_arg(arrg, int);
	switch (errCd)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	freeN();
	exit(EXIT_FAILURE);
}


/**
 * moreR - handles err
 * @errCd: error codes
 *
 * Return: Nothing
*/

void moreR(int errCd, ...)
{
	va_list arrg;
	char *op;
	int l_num;

	va_start(arrg, errCd);
	switch (errCd)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arrg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arrg, int));
			break;
		case 8:
			l_num = va_arg(arrg, unsigned int);
			op = va_arg(arrg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arrg, unsigned int));
			break;
		default:
			break;
	}
	freeN();
	exit(EXIT_FAILURE);
}

/**
 * eR - Prints approp err msg depending on the err code
 * @errCd: error codes
 *
 * Nothing
*/

void eR(int errCd, ...)
{
	va_list arrg;
	char *op;
	int l_num;

	va_start(arrg, errCd);
	switch (errCd)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arrg, char *));
			break;
		case 3:
			l_num = va_arg(arrg, int);
			op = va_arg(arrg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arrg, int));
			break;
		default:
			break;
	}
	freeN();
	exit(EXIT_FAILURE);
}
