# 0x19. C - Stacks, Queues - LIFO, FIFO
**About:** Regarding this project, we developed a basic interpreter for Monty ByteCodes. The interpreter is designed to parse a bytecode file and execute its commands.

### The Monty language
Monty 0.98, akin to Python, is a scripting language initially compiled into Monty byte codes. It operates on a distinct stack structure, utilizing specialized instructions for manipulation.

### Monty byte code files
Files containing Monty byte codes generally utilize the .m extension, a widely adopted industry standard, though it's not mandated by the language specification. Each line typically consists of a single instruction. Spaces before or after the opcode and its argument are flexible, allowing any number of them within the code.

## Objectives:
* Understanding the definitions of LIFO and FIFO
* Understanding the concept of a stack and its applicable scenarios
* Understanding the concept of a queue and its appropriate applications
* Familiarity with prevalent implementations of stacks and queues
* Grasping the typical use cases for stacks and queues
* Learning the appropriate utilization of global variables

### Resource:
* [Difference between Stack and Queue Data Structures](https://www.geeksforgeeks.org/difference-between-stack-and-queue-data-structures/) || 

## General Requirements
* Allowed editors: **vi**, **vim**, **emacs**
* All files is compiled on **Ubuntu 20.04 LTS using gcc**, using the options **-Wall -Werror -Wextra -pedantic -std=gnu89**
* All files ends with a new line
* There is **README.md** file at the root of the **alx-low_level_programming**
* Maximum of one global variable is allowed
* no more than 5 functions per file
* The usage of the C standard library is permitted.
* All function prototypes were incorporated into the "monty.h" header file.
* All header files are equipped with include guards.

## Instruction given:
* Utilize the subsequent data structures for this project and ensure their inclusion in the header file as well.
```
/**
 * struct stack_sV2 - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prevV2: points to the prevV2ious element of the stack (or queue)
 * @nextV2: points to the nextV2 element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_sV2
{
        int n;
        struct stack_sV2 *prevV2;
        struct stack_sV2 *nextV2;
} stack_tV2;
```
```
/**
 * struct instruction_sV2 - opcodeV2 and its function
 * @opcodeV2: the opcodeV2
 * @f: function to handle the opcodeV2
 *
 * Description: opcodeV2 and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_sV2
{
        char *opcodeV2;
        void (*f)(stack_tV2 **stack, unsigned int line_numberV2);
} instruction_tV2;
```

## Compilation & Output
* These codes were compiled using: ```gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty```
* Any output must be printed on ```stdout```
* Any error message must be printed on ```stderr```
```

## Authors/Collaborators
[El Hakik Amina](https://github.com/ElHakikAmina) || [Belaazri El Mehdi](https://github.com/Mehdibe04)
