#ifndef LISTS_H
#define LISTS_H
#include <stddef.h>

int _putchar(char);

size_t print_dlistint(const stack_t *);

size_t dlistint_len(const stack_t *);

stack_t *add_dnodeint(stack_t **, const int);

stack_t *add_dnodeint_end(stack_t **, const int);

void free_dlistint(stack_t *);

void free_dlistint2(stack_t **);

int pop_dlistint(stack_t **);

void swap_dlistint(stack_t **);

void add_dlistint(stack_t **);

void sub_dlistint(stack_t **);

void div_dlistint(stack_t **);

void mul_dlistint(stack_t **);

stack_t *get_dnodeint_at_index(stack_t *, unsigned int);

int sum_dlistint(stack_t *);

stack_t *new_node(stack_t *, int);

stack_t *insert_dnodeint_at_index(stack_t **, unsigned int, int);

int delete_dnodeint_at_index(stack_t **, unsigned int);

stack_t *reverse_dlistint(stack_t **);

size_t print_dlistint_safe(const stack_t *);

size_t free_dlistint_safe(stack_t **);

size_t free_dlistint1_safe(stack_t *, stack_t *);

stack_t *find_dlistint_loop(stack_t *);


#endif /*LISTS_H*/
