#include <stdio.h>
#include <stdlib.h>

struct s_stack {
  int *array;
  int size;
  int cap;
};
typedef struct s_stack Stack;

Stack *create_stack(int);

/* insert */
void push(Stack*,int);

/* delete */
int pop(Stack*);

/* other */
void peek(Stack*);
void display(Stack*);
int is_empty(Stack*);
int is_full(Stack*);
int is_half_full(Stack*);
int size(Stack*);
void reverse(Stack*);

/* util */
void expand_array(Stack*);
void narrow_array(Stack*);

int main(int,char**);
