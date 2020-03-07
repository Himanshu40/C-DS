/*
 * PROGRAM   : To create and display double linked list respectively
 * FILE      : createDoubleLL.c
 * CREATED BY: Himanshu Sekhar Nayak
 * DATED     : 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          data;
    struct Node *prev;
    struct Node *next;
}Node;

void createNode(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *last     = (*head);

    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next     = new_node;
    new_node->prev = last;   
}

void displayNode(Node *head)
{
    printf("++++++++++++++++++\n");
    printf("+List of elements+\n");
    printf("++++++++++++++++++\n");

    while (head != NULL) {
        printf(" %d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    Node *first = NULL;
    char choice = 'Y';
    int  data;
    
    printf("++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To create and display double linked list+\n");
    printf("++++++++++++++++++++++++++++++++++++++++++\n");

    while (choice == 'Y' || choice == 'y') {
        printf("Enter the element: ");
        scanf("%d", &data);
        createNode(&first, data);
        printf("Do you want to add more elements(Y/N)?\n");
        fgetc(stdin);
        scanf("%c", &choice);
        printf("\n");
    }

    displayNode(first);
    
    return 0;
}
