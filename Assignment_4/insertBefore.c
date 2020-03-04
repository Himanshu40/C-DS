/*
 * PROGRAM   : To insert a node before a node and display double linked list respectively
 * FILE      : insertBefore.c
 * CREATED BY: Himanshu Sekhar Nayak
 * DATED     : 
 */

#include <stdio.h>
#include <stdlib.h>

int NodeSize;

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
        ++NodeSize;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next     = new_node;
    new_node->prev = last;
    ++NodeSize;   
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

void createBefore(Node *head, int posn, int value)
{
    Node *curr;
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = value;
    
    while (posn != 1) {
        curr = head;
        head = head->next;
        --posn;
    }

    new_node->next = curr->next;
    new_node->prev = curr;
    curr->next     = new_node;
}

int main()
{
    Node *first = NULL;
    char choice = 'Y';
    int  data;
    int  posn;
    
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

    START:
    printf("\nEnter the position to insert before a node: ");
    scanf("%d", &posn);

    if (posn > NodeSize || posn == 0 || posn < 0) {
        printf("Entered position is incorrect. Retry(Y/N)?\n");
        fgetc(stdin);
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
            goto START;
        else
            return 0;
    }

    printf("Enter the element: ");
    scanf("%d", &data);

    createBefore(first, posn, data);
    displayNode(first);

    return 0;
}