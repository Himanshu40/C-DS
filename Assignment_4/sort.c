/*
 * PROGRAM   : To create and display sorted double linked list respectively
 * FILE      : sort.c
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

void createSortedNode(Node **head, int value)
{
   Node *curr    = (*head);
   Node *newNode = (Node *)malloc(sizeof(Node));

   newNode->data = value;
   newNode->prev = NULL;
   newNode->next = NULL;

   if (*head == NULL) {
       *head = newNode;
       return;
   } 

   if (newNode->data < curr->data) {
       newNode->next = curr;
       curr->prev    = newNode;
       *head         = newNode;
       return;
   }

   while ((curr->next != NULL) && (newNode->data > curr->next->data))
        curr = curr->next;

    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next    = newNode;    
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
    
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To create and display sorted double linked list+\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");

    while (choice == 'Y' || choice == 'y') {
        printf("Enter the element: ");
        scanf("%d", &data);
        createSortedNode(&first, data);
        printf("Do you want to add more elements(Y/N)?\n");
        fgetc(stdin);
        scanf("%c", &choice);
        printf("\n");
    }

    displayNode(first);
}