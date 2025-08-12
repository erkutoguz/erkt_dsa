#include "stack.h"

int main(int argc, char **argv)
{

	Stack *s;

	s = create_stack(2);
	push(s, 10);
	printf("cap of stack %d \n", s->cap);
	push(s, 30);
	push(s, 40);

	push(s, 20);
	printf("cap of stack %d\n", s->cap);
	display(s);

	push(s, 50);
	push(s, 70);
	display(s);
	reverse(s);
	display(s);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	printf("cap of stack %d \n", s->cap);
	int p = pop(s);
	printf("Popped: %d\n", p);

	pop(s);
	display(s);

	peek(s);

	return 0;
}

Stack *create_stack(int cap)
{
	Stack *s;
	int *array;

	array = (int *)malloc(cap * sizeof(int));
	s = (Stack *)malloc(sizeof(Stack));

	s->size = 0;
	s->cap = cap;
	s->array = array;

	return s;
}

void push(Stack *s, int val)
{
	if (is_full(s))
		expand_array(s);

	s->array[s->size++] = val;
}

int pop(Stack *s)
{
	if (is_empty(s)) {
		printf("stack is empty\n");
		return 0;
	}

	if (is_half_full(s))
		narrow_array(s);

	int popped;

	popped = s->array[s->size - 1];
	s->array[s->size-- - 1] = '\0';

	return popped;
}

void peek(Stack *s)
{
	if (is_empty(s)) {
		printf("stack is empty");
		return;
	}
	printf("Peek: %d\n", s->array[s->size - 1]);
}

void display(Stack *s)
{
	int i;

	for (i = 0; i < s->size; ++i) {
		printf("%d ", s->array[i]);
	}

	printf("\n");
}

int is_empty(Stack *s)
{
	return s->size == 0;
}

int is_full(Stack *s)
{
	return s->size + 1 == s->cap;
}

int is_half_full(Stack *s)
{
	return s->size == s->cap / 2;
}

int size(Stack *s)
{
	return s->size;
}

void reverse(Stack *s)
{
	int l, r, tmp;
	l = 0;
	r = s->size - 1;

	while (l < r) {
		tmp = s->array[l];
		s->array[l] = s->array[r];
		s->array[r] = tmp;
		++l;
		--r;
	}
}

void expand_array(Stack *s)
{
	int newcap;
	newcap = s->cap * 2;
	s->array = (int *)realloc(s->array, sizeof(int) * newcap);
	s->cap = newcap;
}

void narrow_array(Stack *s)
{
	int newcap;
	newcap = s->cap / 2;
	s->array = (int *)realloc(s->array, sizeof(int) * newcap);
	s->cap = newcap;
}
