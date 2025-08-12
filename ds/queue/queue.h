#include <stdio.h>
#include <stdlib.h>

typedef struct s_node Node;
struct s_node {
  int val;
  Node *next;
};

struct s_queue {
  int size;
  Node *top;
};
typedef struct s_queue Queue;

/* create */
Queue *create_queue(Node*);
Node *create_node(int);

/* insert */
void enqueue(Queue*,Node*);

/* delete */
Node *dequeue(Queue*);


/* other */
void display(Queue*);
void peek(Queue*);
int is_empty(Queue*);
void clear(Queue*);
void reverse(Queue*);

int main(int,char**);
