#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - dbly linkd list
 * @n: int input
 * @prev: ptr to prev elmt
 * @next: ptr to nxt elmt
 *
 * Description: dbly linkd list
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode's function
 * @opcode: opcode
 * @f: func that handles the opcode
 *
 * Description: opcode's func
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void openf(char *file_name);
int parsel(char *buffer, int l_num, int fo);
void readf(FILE *);
int lenCh(FILE *);
void findFc(char *, char *, int, int);

stack_t *createN(int n);
void freeN(void);
void printS(stack_t **, unsigned int);
void add2S(stack_t **, unsigned int);
void add2Q(stack_t **, unsigned int);

void callF(op_func, char *, char *, int, int);

void printT(stack_t **, unsigned int);
void popT(stack_t **, unsigned int);
void nP(stack_t **, unsigned int);
void swapN(stack_t **, unsigned int);

void addNd(stack_t **, unsigned int);
void subNd(stack_t **, unsigned int);
void divNd(stack_t **, unsigned int);
void mulNd(stack_t **, unsigned int);
void modNd(stack_t **, unsigned int);

void printCh(stack_t **, unsigned int);
void printSt(stack_t **, unsigned int);
void rT(stack_t **, unsigned int);

void eR(int errCd, ...);
void moreR(int errCd, ...);
void stringR(int errCd, ...);
void rTr(stack_t **, unsigned int);

#endif

