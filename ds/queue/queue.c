#include "queue.h"

int main(int argc, char **argv)
{
	Node *n = create_node(10);
	Node *n1 = create_node(20);
	Node *n2 = create_node(30);
	Node *n3 = create_node(40);
	Node *n4 = create_node(50);
	Node *n5 = create_node(60);
	Node *n6 = create_node(70);
	Node *n7 = create_node(80);
	Node *n8 = create_node(90);
	Node *n9 = create_node(100);
	Node *n10, *n11;

	Queue *q = create_queue(n);

	enqueue(q, n1);
	enqueue(q, n2);
	enqueue(q, n3);
	enqueue(q, n4);
	enqueue(q, n5);
	enqueue(q, n6);
	enqueue(q, n7);
	enqueue(q, n8);
	enqueue(q, n9);

	display(q);

	n10 = dequeue(q);
	printf("Dequeued %d\n", n10->val);

	n11 = dequeue(q);
	printf("Dequeue %d\n", n11->val);

	dequeue(q);
	dequeue(q);
	peek(q);

	dequeue(q);
	dequeue(q);
	display(q);

	reverse(q);

	display(q);
	return 0;
}

Node *create_node(int val)
{
	Node *n;
	n = (Node *)malloc(sizeof(Node));
	n->val = val;
	return n;
}

Queue *create_queue(Node *n)
{
	Queue *q;
	q = (Queue *)malloc(sizeof(Queue));
	q->top = n;
	q->size = 1;
	return q;
}

void enqueue(Queue *q, Node *n)
{
	Node *curr;

	curr = q->top;
	while (curr->next) {
		curr = curr->next;
	}
	curr->next = n;
	curr = NULL;
	q->size++;
}

Node *dequeue(Queue *q)
{
	if (is_empty(q)) {
		printf("queue is empty\n");
		return NULL;
	}

	Node *dequeued;
	dequeued = q->top;

	q->top = q->top->next;
	q->size--;
	return dequeued;
}

void display(Queue *q)
{
	if (is_empty(q)) {
		printf("queue is empty\n");
		return;
	}

	Node *curr;

	curr = q->top;
	while (curr) {
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

void peek(Queue *q)
{
	if (is_empty(q)) {
		printf("queue is empty\n");
		return;
	}

	printf("Peek: %d\n", q->top->val);
}

int is_empty(Queue *q)
{
	return q->size == 0;
}

void clear(Queue *q)
{
	free(q->top);
	q->size = 0;
}

void reverse(Queue *q)
{
	Node *prev, *next, *curr;

	curr = q->top;
	prev = NULL;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	q->top = prev;
}
