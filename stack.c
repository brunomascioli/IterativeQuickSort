#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

t_stack* create_stack(int n) {
    t_stack *p = (t_stack *) malloc(sizeof(t_stack));
    p->max = n;
    p->items = (t_elem *) malloc(sizeof(t_elem) * n);
    p->index_top = -1;
    return p;
}

void destroy_stack(t_stack *p) {
    free(p->items);
    free(p);
}

int is_full(t_stack *p) {
    return p->index_top == p->max - 1;
}

int is_empty(t_stack *p) {
    return p->index_top == -1;
}

int push(t_stack *p, t_elem x) {
    if (is_full(p)) 
        return 0;
    p->items[++p->index_top] = x;
    return 1; 
}

int pop(t_stack *p) {
    if (is_empty(p)) 
        return 0;
    p->index_top--;
    return 1;
}

int top(t_stack *p, t_elem *x) {
    if (is_empty(p)) 
        return 0; 
    *x = p->items[p->index_top]; 
    return 1; 
}

void clear(t_stack *p) {
    p->index_top = -1; 
}

void print(t_stack *p) {
    if (is_empty(p)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= p->index_top; i++) {
        printf("%d ", p->items[i]);
    }
    printf("\n");
}