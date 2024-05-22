#ifndef STACK_H
#define STACK_H

typedef int t_elem;

typedef struct {
    int max;
    int index_top;
    t_elem *items;
} t_stack;

t_stack* create_stack(int n);
void destroy_stack(t_stack *p);
int is_full(t_stack *p);
int is_empty(t_stack *p);
int push(t_stack *p, t_elem x);
int pop(t_stack *p);
int top(t_stack *p, t_elem *x);
void clear(t_stack *p);
void print(t_stack *p);

#endif