/*
 * PROGRAM   : To create and display sorted single linked list that contains float values
 * FILE      : floatSort.c
 * CREATED BY: Himanshu Sekhar Nayak
 * DATED     : /02/2020
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    float        data;
    struct Node *next;
}Node;

void createSortedFloat(Node **head, float value)
{
    Node *curr    = (*head);
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (newNode->data > curr->data) {
        newNode->next = curr;
        *head = newNode;
        return;
    }

    while ((curr->next != NULL) && (newNode->data < curr->next->data))
        curr = curr->next;

    newNode->next = curr->next;
    curr->next    = newNode;    
}

void display(Node *head)
{
    printf("++++++++++++++++++++++++++++++++\n");
    printf("+List of descending float value+\n");
    printf("++++++++++++++++++++++++++++++++\n");

    while (head != NULL) {
        printf("%.2f ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    Node *first = NULL;
    char  choice = 'Y';
    float data;
    
    printf("+++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To create and display sorted float values+\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++\n");

    while (choice == 'Y' || choice == 'y') {
        printf("Enter the float value: ");
        scanf("%f", &data);
        createSortedFloat(&first, data);
        printf("Do you want to add more elements(Y/N)?\n");
        fgetc(stdin);
        scanf("%c", &choice);
        printf("\n");
    }

    display(first);

    return 0;
}
