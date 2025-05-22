#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
    int data; 
    struct node *next;
} Node;

typedef struct stack
{
    Node *head;
} Stack;

Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node *));
    if(temp == NULL)
    {
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

bool isEmpty(Stack *stack)
{
    return (stack->head == NULL);
}

bool push(Stack *stack, int data)
{
    Node *node = newNode(data);
    if(node == NULL)
    {
        printf("stack overflow\n");
        return false;
    }

    node->next = stack->head;
    stack->head = node;
    return true;
}

bool pop(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("stack empty\n");
        return false;       
    }

    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    return true;
}

Node *top(Stack *s)
{
    if(isEmpty(s))
    {
        printf("stack empty\n");
        return NULL;       
    }
    
    return s->head;
}

int main() 
{
    Stack *stack; 
    stack->head = NULL;

    push(stack, 1);
    push(stack, 3);
    push(stack, 4);
    push(stack, 6);

    printf("top : %d\n", top(stack)->data);
    printf("pop : %d\n",pop(stack));

    printf("top : %d\n", top(stack)->data);
    pop(stack);
    printf("pop : %d\n",pop(stack));


    return 0;
}