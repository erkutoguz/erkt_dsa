#include "singly_ll.h"

int main(int argc, char **argv)
{
	Node *n = create_node(10);
	SLL *sll = create_sll(n);

	int pos;
	Node *n1 = create_node(20);
	Node *n2 = create_node(30);
	Node *n3 = create_node(40);
	Node *n4 = create_node(50);
	Node *n5 = create_node(60);
	Node *n6;
	Node *n7;
	Node *n8;

	insert_at_head(sll, n1);
	insert_at_tail(sll, n2);
	insert_at_head(sll, n3);
	insert_at_tail(sll, n4);

	printf("Size: %d\n", size(sll));
	traverse(sll);

	insert_at_pos(sll, n5, 2);

	traverse(sll);

	n6 = delete_at_head(sll);
	printf("Deleted at head Node: %d\n", n6->val);

	traverse(sll);

	n7 = delete_at_tail(sll);
	printf("Deleted at tail Node: %d\n", n7->val);

	traverse(sll);

	n8 = delete_at_pos(sll, 2);
	printf("Deleted at pos Node: %d\n", n8->val);

	traverse(sll);

	pos = search(sll, 20);
	printf("Search result: %d\n", pos);

	update_at_pos(sll, 1, 90);

	traverse(sll);

	reverse_list(sll);

	traverse(sll);

	free_list(sll);

	traverse(sll);

	return 0;
}

SLL *create_sll(Node *node)
{
	SLL *sll = (SLL *)malloc(sizeof(SLL));
	sll->head = node;
	sll->tail = sll->head;
	sll->size = 1;
	return sll;
}

Node *create_node(int val)
{
	Node *node;
	node = (Node *)malloc(sizeof(Node));
	node->val = val;
	return node;
}

void insert_at_head(SLL *sll, Node *node)
{
	if (is_empty(sll))
		perror("list is empty");

	node->next = sll->head;
	sll->head = node;
	sll->size++;
}

void insert_at_tail(SLL *sll, Node *node)
{
	if (is_empty(sll))
		perror("list is empty");

	node->next = NULL;
	sll->tail->next = node;
	sll->tail = node;
	sll->size++;
}

void insert_at_pos(SLL *sll, Node *node, int pos)
{
	if (pos > size(sll))
		perror("out of bounds");

	int i;
	i = 0;
	Node *curr, *prev;
	curr = sll->head;
	prev = sll->head;
	while (i++ < pos) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = node;
	node->next = curr;

	prev = curr = NULL;
	sll->size++;
}

Node *delete_at_head(SLL *sll)
{
	if (is_empty(sll))
		perror("list is empty");

	Node *deleted;
	deleted = sll->head;
	sll->head = sll->head->next;
	deleted->next = NULL;
	sll->size--;
	return deleted;
}

Node *delete_at_tail(SLL *sll)
{
	if (is_empty(sll))
		perror("list is empty");

	Node *curr, *prev;

	curr = prev = sll->head;

	while (curr->next) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = NULL;
	sll->tail = prev;
	prev = NULL;
	sll->size--;
	return curr;
}

Node *delete_at_pos(SLL *sll, int pos)
{
	if (pos > size(sll))
		perror("out of bounds");

	if (is_empty(sll))
		perror("list is empty");

	int i;
	Node *curr, *prev;

	i = 0;
	curr = prev = sll->head;

	while (i++ < pos) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;
	prev = NULL;
	sll->size--;
	return curr;
}

int search(SLL *sll, int val)
{
	int pos;
	Node *curr;

	pos = 0;
	curr = sll->head;

	while (curr->next && curr->val != val) {
		curr = curr->next;
		++pos;
	}

	return curr->val == val ? pos : -1;
}

void update_at_pos(SLL *sll, int pos, int val)
{
	int i;
	Node *curr;

	i = 0;
	curr = sll->head;

	while (i++ < pos)
		curr = curr->next;

	curr->val = val;
	curr = NULL;
}

int is_empty(SLL *sll)
{
	return sll->size == 0;
}

int size(SLL *sll)
{
	return sll->size;
}

void traverse(SLL *sll)
{
	if (is_empty(sll)) {
		printf("List is empty\n");
		return;
	}

	Node *curr;
	curr = sll->head;
	while (curr) {
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

void free_list(SLL *sll)
{
	while (sll->head) {
		sll->head = sll->head->next;
		sll->size--;
	}
}

void reverse_list(SLL *sll)
{
	Node *curr, *prev, *next;

	curr = sll->head;
	prev = NULL;

	while (curr) {
		next = curr->next; // store after curr
		curr->next = prev; // the next node of curr is now reversed list
		prev = curr;	   // and then reversed list is curr
		curr = next;	   // curr is the next node of original list
	}

	sll->tail = sll->head; // new tail is now head of original list
	sll->head = prev;      // new head is reversed list
}
