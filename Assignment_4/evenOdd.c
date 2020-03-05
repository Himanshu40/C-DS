/*
 * PROGRAM   : To store the even & odd nos. in 2nd and 3rd double linked list respectively
 * FILE      : evenOdd.c
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

void createEven(Node *head, Node **top)
{
    while (head != NULL) {
        if (head->data % 2 == 0)
            createNode(&(*top), head->data);
        head = head->next;
    }
}

void createOdd(Node *head, Node **top)
{
    while (head != NULL) {
        if (head->data % 2 != 0)
            createNode(&(*top), head->data);
        head = head->next;
    }
}

int main()
{
    Node *first  = NULL;
    Node *second = NULL;
    Node *third  = NULL;
    char choice  = 'Y';
    int  data;
    
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To store even and odd nos. in 2nd & 3rd double linked list+\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

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

    createEven(first, &second);
    createOdd(first, &third);

    printf("\nEven Numbers in 2nd single linked list:-\n");
    displayNode(second);

    printf("\nOdd Numbers in 3nd single linked list:-\n");
    displayNode(third);
    
    return 0;
}