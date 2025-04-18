#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

typedef struct {
    node *top;
} stack;

stack *makestack(void) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

void createStack(stack *s, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = s->top;  // Insert at the top of the stack
    s->top = n;
}

void pushStack(stack *s, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = s->top;
    s->top = n;
}

void peepStack(stack *s) {
    if (s->top != NULL) {
        printf("%d\n", s->top->info);
    } else {
        printf("Stack is empty\n");
    }
}

void popStack(stack *s) {
    if (s->top != NULL) {
        node *t = s->top;
        s->top = t->next;
        free(t);
    }
}

int main() {
    stack *st = makestack();
    int a, i, v;

    printf("Enter values to add to stack:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a);
        createStack(st, a);  // Insert each value into the stack
    }

    printf("Top value in stack: ");
    peepStack(st);

    printf("Enter a value to push to the stack: ");
    scanf("%d", &v);
    pushStack(st, v);

    printf("Top value in stack after push: ");
    peepStack(st);

    popStack(st);
    printf("Top value in stack after pop: ");
    peepStack(st);

    return 0;
}