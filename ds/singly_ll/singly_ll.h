#include <stdio.h>
#include <stdlib.h>

typedef struct s_node Node;
struct s_node {
  int val;
  Node *next;
};

struct s_sll{
  int size;
  Node *head;
  Node *tail;
};
typedef struct s_sll SLL;

SLL *create_sll(Node*);
Node *create_node(int);

/* insertion */
void insert_at_head(SLL*,Node*);
void insert_at_tail(SLL*,Node*);
void insert_at_pos(SLL*,Node*,int);

/* remove */
Node *delete_at_head(SLL*);
Node *delete_at_tail(SLL*);
Node *delete_at_pos(SLL*,int);

/* search */
int search(SLL*,int);

/* update */
void update_at_pos(SLL*,int,int);

/* other */
void traverse(SLL*);
int size(SLL*);
int is_empty(SLL*);
void free_list(SLL*);
void reverse_list(SLL*);


int main(int,char**);
